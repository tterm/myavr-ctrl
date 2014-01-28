/*
 * SerialPort.cpp
 *
 *  Created on: 26.01.2014
 *      Author: tterm
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "SerialPort.h"
#include "ModeUtils.h"
#include <boost/system/error_code.hpp>
#include <boost/asio/error.hpp>
#include <boost/asio/deadline_timer.hpp>
#include <boost/lambda/bind.hpp>
#include <boost/lambda/lambda.hpp>

using namespace log4cxx;
using std::string;
using boost::system::system_error;
using boost::system::error_code;

namespace backend {

LoggerPtr SerialPort::cdtor(Logger::getLogger("lifecycle"));
LoggerPtr SerialPort::logger(Logger::getLogger("backend.SerialPort"));

SerialPort::SerialPort(const PortConfig & config)
        throw (DeviceNotFoundException) :
        config_(config), port_(io_service_), deadline_(io_service_) {
    LOG4CXX_TRACE(cdtor, "SerialPort()");
    LOG4CXX_TRACE(logger, "Creating connection to the serial port " << config_.getDevice());
    try {
        port_.open(config_.getDevice());
    } catch (system_error & ec) {
        LOG4CXX_ERROR(logger,
                "Error opening device " + config_.getDevice() + " " + ec.what())
        throw DeviceNotFoundException(config_);
    }
    port_.set_option(config_.getBaudRate());
    port_.set_option(config_.getCharSize());
    port_.set_option(config_.getStopBits());
    port_.set_option(config_.getFlowControl());
    port_.set_option(config_.getParity());

    // No deadline is required until the first socket operation is started. We
    // set the deadline to positive infinity so that the actor takes no action
    // until a specific deadline is set.
    deadline_.expires_at(boost::posix_time::pos_infin);

    // Start the persistent actor that checks for deadline expiry.
    checkDeadline();
    LOG4CXX_TRACE(logger, "Successfully established connection to the serial port at" << config_.getDevice())
}

SerialPort::~SerialPort() {
    LOG4CXX_TRACE(cdtor, "~SerialPort -> Close the connection");
    port_.close();
}

void SerialPort::writeSome(boost::posix_time::time_duration timeout)
        throw (SerialPortCommunicationError) {
    std::string com(ModeUtils::request_prefix);
    com.push_back(ModeUtils::instance()->getMode(config_.getMode()));
    LOG4CXX_TRACE(logger, "Write stream to device")
    // Start the timer
    deadline_.expires_from_now(timeout);
    // Set error code to would_block because async_write will never get back
    // with would_block.
    error_code ec = boost::asio::error::would_block;
    try {

        boost::asio::async_write(port_,
                boost::asio::buffer(com.c_str(), com.length()),
                boost::lambda::var(ec) = boost::lambda::_1);
        // block as long as error is untouched with would_block
        // we check for would block because async_write never returns
        // would_block
        do {
            io_service_.run_one();
        } while (ec == boost::asio::error::would_block);

        if (ec)
            throw SerialPortCommunicationError();
            //throw system_error(ec);
    } catch (system_error & ex) {
        LOG4CXX_ERROR(logger, ex.what())
    }
    LOG4CXX_TRACE(logger, "Finished writing stream to device")
}

string SerialPort::readSome(boost::posix_time::time_duration timeout)
        throw (SerialPortCommunicationError) {
    LOG4CXX_TRACE(logger, "Starting to read from serial port");
    char c;
    std::string result;
    bool end = false;
    while (!end) {
        deadline_.expires_from_now(timeout);
        error_code ec = boost::asio::error::would_block;
        boost::asio::async_read(port_, boost::asio::buffer(&c, 1),
                boost::lambda::var(ec) = boost::lambda::_1);

        do
            io_service_.run_one();
        while (ec == boost::asio::error::would_block);

        if (ec)
            throw SerialPortCommunicationError();
            //throw boost::system::system_error(ec);

        switch (c) {
        case '\r':
            break;
        case '\n':
            end = true;
            break;
        default:
            result += c;
            LOG4CXX_TRACE(logger, std::hex << (unsigned int)c)
            break;
        }
    }
    LOG4CXX_TRACE(logger, "End")
    return result;
}

void SerialPort::checkDeadline() {
    // Check whether the deadline has passed. We compare the deadline against
    // the current time since a new asynchronous operation may have moved the
    // deadline before this actor had a chance to run.
    LOG4CXX_TRACE(logger, "Check Deadline");
    if (deadline_.expires_at()
            <= boost::asio::deadline_timer::traits_type::now()) {
        // The deadline has passed. The port is closed so that any outstanding
        // asynchronous operations are cancelled. This allows the blocked
        // readSome() or writeSome() functions to return.
        error_code ignored_ec;
        port_.close(ignored_ec);

        // There is no longer an active deadline. The expiry is set to positive
        // infinity so that the actor takes no action until a new deadline is set.
        deadline_.expires_at(boost::posix_time::pos_infin);
    }

    // Put the actor back to sleep.
    deadline_.async_wait(boost::lambda::bind(&SerialPort::checkDeadline, this));
}

} /* namespace backend */

/*
 * Command.cpp
 *
 *  Created on: 19.12.2011
 *      Author: tterm
 */

#include "Command.h"
#include "PortConfig.h"
#include "ModeUtils.h"
#include <iostream>
#include <boost/asio.hpp>

using namespace log4cxx;

namespace backend {

LoggerPtr Command::cdtor(Logger::getLogger("lifecycle"));
LoggerPtr Command::logger(Logger::getLogger("backend.Command"));

Command::Command() {
	LOG4CXX_TRACE(cdtor, "Command()");
}

Command::~Command() {
	LOG4CXX_TRACE(cdtor, "~Command()");
}

void Command::execute(const PortConfig & config)
		throw (DeviceNotFoundException) {
	boost::asio::io_service service;
	boost::asio::serial_port port(service);
	try {
		port.open(config.getDevice());
	} catch (boost::system::system_error & ec) {
		LOG4CXX_ERROR(logger, "Error opening device " + config.getDevice() + " " + ec.what());
		throw DeviceNotFoundException(config);
	}
	port.set_option(config.getBaudRate());
	port.set_option(config.getCharSize());
	port.set_option(config.getStopBits());
	port.set_option(config.getFlowControl());
	port.set_option(config.getParity());
	std::string com(ModeUtils::request_prefix);
	com.push_back(ModeUtils::instance()->getMode(config.getMode()));
	LOG4CXX_TRACE(logger, "Write stream to device");
	try {
		port.write_some(boost::asio::buffer(com.c_str(), com.length()));
	} catch (boost::system::system_error & ex) {
		LOG4CXX_ERROR(logger, ex.what());
	}
	LOG4CXX_TRACE(logger, "Finished writing stream to device");

	char c;
	std::string result;
	bool end = false;
	while(!end) {
		port.read_some(boost::asio::buffer(&c, 1));
		switch (c) {
		case '\r':
			break;
		case '\n':
			end = true;
			break;
		default:
			result += c;
			LOG4CXX_TRACE(logger, std::hex << (unsigned int)c);
			break;
		}
	}
	LOG4CXX_TRACE(logger, "End");
}

/*void Command::readHandler(const boost::system::error_code & error, std::size_t bytes_transfered)
{
	if (!error)
	{
		LOG4CXX_TRACE(logger, "read handler success");
	}
}*/

}

/*
 * SerialPort.h
 *
 *  Created on: 26.01.2014
 *      Author: tterm
 */

#ifndef SERIALPORT_H_
#define SERIALPORT_H_

#include <string>
#include "PortConfig.h"
#include "DeviceNotFoundException.h"
#include "SerialPortCommunicationError.h"
#include <boost/asio/deadline_timer.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/asio/serial_port.hpp>
#include <log4cxx/logger.h>

namespace backend {

class SerialPort {
public:
    /**
     * Create a connection to the serial port with the given
     * configuration.
     *
     * @param PortConfig A valid port configuration is needed
     */
    SerialPort(const PortConfig & portConfig) throw (DeviceNotFoundException);

    /**
     * Destructor close the connection
     */
    ~SerialPort();

    /**
     * Write something to the serial port.
     *
     * @param timeout The timeout after the write is getting back
     */
    void writeSome(boost::posix_time::time_duration timeout)
            throw (SerialPortCommunicationError);

    /**
     * Read something from the serial port
     *
     * @param timeout The timeout after the read is getting back
     */
    std::string readSome(boost::posix_time::time_duration timeout)
            throw (SerialPortCommunicationError);

private:
    void checkDeadline();

private:
    PortConfig config_;
    boost::asio::io_service io_service_;
    boost::asio::serial_port port_;
    boost::asio::deadline_timer deadline_;
    static log4cxx::LoggerPtr cdtor;
    static log4cxx::LoggerPtr logger;
};

} /* namespace backend */

#endif /* SERIALPORT_H_ */

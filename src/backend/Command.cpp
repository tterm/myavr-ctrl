/*
 * Command.cpp
 *
 *  Created on: 19.12.2011
 *      Author: tterm
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "Command.h"
#include "PortConfig.h"
#include "ModeUtils.h"
#include "SerialPort.h"
#include <iostream>
#include <boost/asio.hpp>

using namespace log4cxx;

namespace backend {

LoggerPtr Command::cdtor(Logger::getLogger("lifecycle"));
LoggerPtr Command::logger(Logger::getLogger("backend.Command"));

Command::Command() {
    LOG4CXX_TRACE(cdtor, "Command()")
}

Command::~Command() {
    LOG4CXX_TRACE(cdtor, "~Command()")
}

void Command::execute(const PortConfig & config)
        throw (DeviceNotFoundException, SerialPortCommunicationError) {
    SerialPort serialPort(config);
    serialPort.writeSome(boost::posix_time::milliseconds(1500));
    serialPort.readSome(boost::posix_time::milliseconds(1500));
}

}

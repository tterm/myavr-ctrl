/*
 * Command.h
 *
 *  Created on: 19.12.2011
 *      Author: tterm
 */

#ifndef COMMAND_H_
#define COMMAND_H_

#include "DeviceNotFoundException.h"
#include "SerialPortCommunicationError.h"
#include "PortConfig.h"
#include <log4cxx/logger.h>
#include <boost/asio.hpp>

namespace backend {

class Command {
public:
    Command();
    ~Command();
    void execute(const PortConfig & config) throw (DeviceNotFoundException,
            SerialPortCommunicationError);
private:
    static log4cxx::LoggerPtr cdtor;
    static log4cxx::LoggerPtr logger;
};

}

#endif /* COMMAND_H_ */

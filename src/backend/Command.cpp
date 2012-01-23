/*
 * Command.cpp
 *
 *  Created on: 19.12.2011
 *      Author: tterm
 */

#include "Command.h"
#include "SerialStream.h"
#include "PortConfig.h"
#include "ModeUtils.h"
#include <iostream>

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

void Command::execute(const PortConfig & config) throw(DeviceNotFoundException) {
	LibSerial::SerialStream stream;
	stream.Open(config.getDevice());
	if (!stream.good()) {
		LOG4CXX_ERROR(logger, "Error opening device " + config.getDevice());
		throw DeviceNotFoundException(config);
	}
	stream.SetBaudRate(config.getBaudRate());
	stream.SetCharSize(config.getCharSize());
	stream.SetNumOfStopBits(config.getStopBits());
	stream.SetFlowControl(config.getFlowControl());
	stream.SetParity(config.getParity());
	//stream.SetVMin(0);
	//	stream.SetVTime(100);
	std::string com(ModeUtils::request_prefix);
	com.push_back(ModeUtils::instance()->getMode(config.getMode()));
	LOG4CXX_TRACE(logger, "Write stream to device");
	stream.write(com.c_str(), com.length());
	LOG4CXX_TRACE(logger, "Finished writing stream to device");
	if (!stream.good()) {
		LOG4CXX_ERROR(logger, "Error writing to device");
		return;
	}
	stream.clear();
	std::string resp(ModeUtils::response_prefix);
	resp.push_back(ModeUtils::instance()->getMode(config.getMode()));
	resp.push_back('\r');
	resp.push_back('\0');
	char c;
	while (c != '\n') {
		stream.get(c);
		LOG4CXX_TRACE(logger, "Value: " << std::hex << (int)c);
	}
	/*char buff[100];
	std::cout << "get" << std::endl;
	stream.get(buff, 100, '\n');
	std::cout << "got it" << std::endl;
	for (int i = 0; i < 10; ++i) {
		if (buff[i] == '\r') {
			std::cerr << "Zeilenumbruch" << std::endl;
			continue;
		}
		if (buff[i] == '\0') {
			std::cerr << "here " << std::endl;
			break;
		}
		std::cerr << "###" << std::hex << (int) buff[i] << "###" << std::endl;
	}*/
	std::cerr << "End " << std::endl;
}

}

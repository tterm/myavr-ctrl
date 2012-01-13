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

namespace backend {

Command::Command() {

}

Command::~Command() {
}

void Command::execute(const PortConfig & config) throw(DeviceNotFoundException) {
	LibSerial::SerialStream stream;
	stream.Open(config.getDevice());
	if (!stream.good()) {
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
	std::cout << "Write" << std::endl;
	stream.write(com.c_str(), com.length());
	std::cout << "Written" << std::endl;
	if (!stream.good()) {
		std::cerr << "Error sending data to programmer " << std::endl;
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
		std::cout << "Value: " << std::hex << (int)c << std::endl;
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

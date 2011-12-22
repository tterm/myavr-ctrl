/*
 * Command.cpp
 *
 *  Created on: 19.12.2011
 *      Author: tterm
 */

#include "Command.h"
#include "SerialStream.h"
#include "BaudUtils.h"
#include "FlowControlUtils.h"
#include "CharSizeUtils.h"
#include "ModeUtils.h"
#include "ParityUtils.h"
#include <iostream>

namespace TTE {

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
	stream.SetBaudRate(BaudUtils::instance()->getBaudRate(config.getBaud()));
	stream.SetCharSize(
			CharSizeUtils::instance()->getCharSize(config.getCharsize()));
	stream.SetNumOfStopBits(config.getStopBit());
	stream.SetFlowControl(
			FlowControlUtils::instance()->getFlowControl(
					config.getFlowControl()));
	stream.SetParity(ParityUtils::instance()->getParity(config.getParity()));
	std::string com(ModeUtils::prefix);
	com.push_back(ModeUtils::instance()->getMode(config.getMode()));
	stream.write(com.c_str(), com.length());
	char buff[100];
	stream.get(buff, 100, '\n');
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
	}
}

}

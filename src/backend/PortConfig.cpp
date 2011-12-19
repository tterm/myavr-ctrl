/*
 * PortConfig.cpp
 *
 *  Created on: 19.12.2011
 *      Author: tterm
 */

#include "PortConfig.h"

#include <iostream>
#include <sstream>

PortConfig::PortConfig(const std::string & device, const std::string & baud,
		const std::string & charsize, const std::string & flowcontrol,
		const std::string & parity, const std::string & stopbit, const std::string & mode) :
	baud_(baud), charsize_(charsize), flow_conrol_(flowcontrol), mode_(mode),
			parity_(parity), device_(device) {
	std::stringstream str(stopbit);
	str >> stopbit_;
}

PortConfig::~PortConfig() {
}

std::ostream & operator<<(std::ostream & os, const PortConfig & config) {
	os << "Device: " << config.getDevice()
	   << "\nBaud: " << config.getBaud()
	   << "\nParity: " << config.getParity()
	   << "\nCharsize: " << config.getCharsize()
	   << "\nStopbit: " << config.getStopBit()
	   << "\nFlowcontrol: " << config.getFlowControl()
	   << "\nMode: " << config.getMode();
	   return os;
}

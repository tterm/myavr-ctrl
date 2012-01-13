/*
 * PortConfig.cpp
 *
 *  Created on: 29.12.2011
 *      Author: tterm
 */

#include "PortConfig.h"

#include <ostream>

namespace backend {

PortConfig::PortConfig(BaudRateEnum baud,
		CharSizeEnum char_size,
		FlowControlEnum flow_ctrl,
		ParityEnum parity,
		unsigned int stopbit)
:baud_(baud), char_size_(char_size),
 flow_ctrl_(flow_ctrl), parity_(parity),
 stopbit_(stopbit)
{

}

PortConfig::PortConfig(const PortConfig & to_copy) {
	copy_values(to_copy);
}

PortConfig::~PortConfig() {
}

PortConfig & PortConfig::operator =(const PortConfig & to_assign) {
	copy_values(to_assign);
	return *this;
}

void PortConfig::copy_values(const PortConfig & to_copy) {
	setBaudRate(to_copy.getBaudRate());
	setCharSize(to_copy.getCharSize());
	setFlowControl(to_copy.getFlowControl());
	setParity(to_copy.getParity());
	setStopBits(to_copy.getStopBits());
	setDevice(to_copy.getDevice());
	setMode(to_copy.getMode());
}

std::ostream & operator<<(std::ostream & os, const PortConfig & pc) {
	os << "Baud " << pc.getBaudRate();
	return os;
}

}


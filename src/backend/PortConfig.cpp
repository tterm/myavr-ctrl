/*
 * PortConfig.cpp
 *
 *  Created on: 29.12.2011
 *      Author: tterm
 */

#include "PortConfig.h"

#include <ostream>

using namespace log4cxx;


namespace backend {

LoggerPtr PortConfig::cdtor(Logger::getLogger("lifecycle"));
LoggerPtr PortConfig::logger(Logger::getLogger("backend.PortConfig"));

PortConfig::PortConfig(BaudRate baud,
		CharSize char_size,
		FlowControl flow_ctrl,
		Parity parity,
		StopBits stopbit)
:baud_(baud), char_size_(char_size),
 flow_ctrl_(flow_ctrl), parity_(parity),
 stopbit_(stopbit)
{
	LOG4CXX_TRACE(cdtor, "PortConfig()")
}

PortConfig::PortConfig(const PortConfig & to_copy) {
	copy_values(to_copy);
	LOG4CXX_TRACE(cdtor, "PortConfig(const PortConfig &)")
}

PortConfig::~PortConfig() {
	LOG4CXX_TRACE(cdtor, "~PortConfig()")
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
	os << pc.getBaudRate().value();
	return os;
}

}


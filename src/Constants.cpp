/*
 * Constants.cpp
 *
 *  Created on: 15.12.2011
 *      Author: tterm
 */

#include "Constants.h"

namespace TTE {

Constants * Constants::instance_ = 0;

Constants::Constants()
{
	initBaudRates();
}

Constants::~Constants() {
}

Constants * Constants::instance(void) {
	if (instance_ == 0) {
		instance_ = new Constants();
	}
	return instance_;
}

const std::map<std::string, BaudRate> &
Constants::getBaudRates(void) const {
	return baud_rates_;
}

void Constants::initBaudRates(void) {

	baud_rates_.insert(std::make_pair("50", LibSerial::SerialStreamBuf::BAUD_50));
	baud_rates_.insert(std::make_pair("75", LibSerial::SerialStreamBuf::BAUD_75));
	baud_rates_.insert(std::make_pair("110", LibSerial::SerialStreamBuf::BAUD_110));
	baud_rates_.insert(std::make_pair("134", LibSerial::SerialStreamBuf::BAUD_134));
	baud_rates_.insert(std::make_pair("150", LibSerial::SerialStreamBuf::BAUD_150));
	baud_rates_.insert(std::make_pair("200", LibSerial::SerialStreamBuf::BAUD_200));
	baud_rates_.insert(std::make_pair("300", LibSerial::SerialStreamBuf::BAUD_300));
	baud_rates_.insert(std::make_pair("600", LibSerial::SerialStreamBuf::BAUD_600));
	baud_rates_.insert(std::make_pair("1200", LibSerial::SerialStreamBuf::BAUD_1200));
	baud_rates_.insert(std::make_pair("1800", LibSerial::SerialStreamBuf::BAUD_1800));
	baud_rates_.insert(std::make_pair("2400", LibSerial::SerialStreamBuf::BAUD_2400));
	baud_rates_.insert(std::make_pair("4800", LibSerial::SerialStreamBuf::BAUD_4800));
	baud_rates_.insert(std::make_pair("9600", LibSerial::SerialStreamBuf::BAUD_9600));
	baud_rates_.insert(std::make_pair("19200", LibSerial::SerialStreamBuf::BAUD_19200));
	baud_rates_.insert(std::make_pair("38400", LibSerial::SerialStreamBuf::BAUD_38400));
	baud_rates_.insert(std::make_pair("57600", LibSerial::SerialStreamBuf::BAUD_57600));
	baud_rates_.insert(std::make_pair("115200", LibSerial::SerialStreamBuf::BAUD_115200));

}

}

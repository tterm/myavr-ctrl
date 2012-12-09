/*
 * BaudUtils.cpp
 *
 *  Created on: 16.12.2011
 *      Author: tterm
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "BaudUtils.h"

namespace backend {

BaudUtils * BaudUtils::instance_ = 0;

BaudUtils::BaudUtils()
{
	initBaudRates();
}

BaudUtils::~BaudUtils() {
}

BaudUtils * BaudUtils::instance(void) {
	if (instance_ == 0) {
		instance_ = new BaudUtils();
	}
	return instance_;
}

const std::map<std::string, BaudRate> &
BaudUtils::getBaudRates(void) const {
	return baud_rates_;
}

const std::map<BaudRate, std::string, BaudComparator> &
BaudUtils::getBauds(void) const {
	return baud_str_;
}

BaudRate BaudUtils::getBaudRate(const std::string & rate) const {
	std::map<std::string, BaudRate>::const_iterator iter = baud_rates_.find(rate);
	if (iter != baud_rates_.end()) {
		return iter->second;
	}
	return BaudRate(0);
}

void BaudUtils::initBaudRates(void) {
	baud_rates_.insert(
			std::make_pair("50", BaudRate(50)));
	baud_rates_.insert(
			std::make_pair("75", BaudRate(75)));
	baud_rates_.insert(
			std::make_pair("110", BaudRate(110)));
	baud_rates_.insert(
			std::make_pair("134", BaudRate(134)));
	baud_rates_.insert(
			std::make_pair("150", BaudRate(150)));
	baud_rates_.insert(
			std::make_pair("200", BaudRate(200)));
	baud_rates_.insert(
			std::make_pair("300", BaudRate(300)));
	baud_rates_.insert(
			std::make_pair("600", BaudRate(600)));
	baud_rates_.insert(
			std::make_pair("1200", BaudRate(1200)));
	baud_rates_.insert(
			std::make_pair("1800", BaudRate(1800)));
	baud_rates_.insert(
			std::make_pair("2400", BaudRate(2400)));
	baud_rates_.insert(
			std::make_pair("4800", BaudRate(4800)));
	baud_rates_.insert(
			std::make_pair("9600", BaudRate(9600)));
	baud_rates_.insert(
			std::make_pair("19200", BaudRate(19200)));
	baud_rates_.insert(
			std::make_pair("38400", BaudRate(38400)));
	baud_rates_.insert(
			std::make_pair("57600", BaudRate(57600)));
	baud_rates_.insert(
			std::make_pair("115200", BaudRate(115200)));

	std::map<std::string, BaudRate, BaudComparator>::const_iterator iter = baud_rates_.begin();
	while (iter != baud_rates_.end()) {
		baud_str_.insert(std::make_pair(iter->second, iter->first));
		++iter;
	}
}

}

/*
 * ParityUtils.cpp
 *
 *  Created on: 16.12.2011
 *      Author: tterm
 */

#include "ParityUtils.h"

namespace backend {

ParityUtils * ParityUtils::instance_ = 0;

ParityUtils::ParityUtils() {
	init();
}

ParityUtils::~ParityUtils() {
}

ParityUtils * ParityUtils::instance(void) {
	if (instance_ == 0) {
		instance_ = new ParityUtils();
	}
	return instance_;
}

const StringParityMap & ParityUtils::getStrParityMap(void) const {
	return str_par_map_;
}

const ParityStringMap & ParityUtils::getParityStrMap(void) const {
	return par_str_map_;
}

Parity ParityUtils::getParity(const std::string & pari) const {
	StringParityMap::const_iterator iter = str_par_map_.find(pari);
	if (iter != str_par_map_.end()) {
		return iter->second;
	}
	return LibSerial::SerialStreamBuf::PARITY_INVALID;

}

void ParityUtils::init(void) {
	str_par_map_.insert(std::make_pair("Even", LibSerial::SerialStreamBuf::PARITY_EVEN));
	str_par_map_.insert(std::make_pair("Odd", LibSerial::SerialStreamBuf::PARITY_ODD));
	str_par_map_.insert(std::make_pair("None", LibSerial::SerialStreamBuf::PARITY_NONE));
	StringParityMap::const_iterator iter = str_par_map_.begin();
	while (iter != str_par_map_.end()) {
		par_str_map_.insert(std::make_pair(iter->second, iter->first));
		++iter;
	}
}

}

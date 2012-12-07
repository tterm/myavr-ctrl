/*
 * ParityUtils.cpp
 *
 *  Created on: 16.12.2011
 *      Author: tterm
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

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
	return Parity(Parity::none);

}

void ParityUtils::init(void) {
	str_par_map_.insert(std::make_pair("Even", Parity(Parity::even)));
	str_par_map_.insert(std::make_pair("Odd", Parity(Parity::odd)));
	str_par_map_.insert(std::make_pair("None", Parity(Parity::none)));

	typedef StringParityMap::const_iterator CIter;
	CIter iter = str_par_map_.begin();
	CIter end = str_par_map_.end();
	while (iter != end) {
		par_str_map_.insert(std::make_pair(iter->second, iter->first));
		++iter;
	}
}

}

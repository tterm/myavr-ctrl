/*
 * CharSizeUtils.cpp
 *
 *  Created on: 16.12.2011
 *      Author: tterm
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "CharSizeUtils.h"

namespace backend {

CharSizeUtils * CharSizeUtils::instance_ = 0;

CharSizeUtils::CharSizeUtils() {
	init();
}

CharSizeUtils::~CharSizeUtils() {
}

CharSizeUtils * CharSizeUtils::instance(void) {
	if (instance_ == 0) {
		instance_ = new CharSizeUtils();
	}
	return instance_;
}

const std::map<std::string, CharSize> & CharSizeUtils::getStrCharsize(void) const {
	return str_charsize_;
}

const std::map<CharSize, std::string, CharSizeComparator> & CharSizeUtils::getCharsizeStr(void) const {
	return charsize_str_;
}

CharSize CharSizeUtils::getCharSize(const std::string & charsize) const {
	std::map<std::string, CharSize>::const_iterator iter = str_charsize_.find(charsize);
	if (iter != str_charsize_.end()) {
		return iter->second;
	}
	return CharSize(0);
}

void CharSizeUtils::init(void) {
	str_charsize_.insert(std::make_pair("5", CharSize(5)));
	str_charsize_.insert(std::make_pair("6", CharSize(6)));
	str_charsize_.insert(std::make_pair("7", CharSize(7)));
	str_charsize_.insert(std::make_pair("8", CharSize(8)));

	typedef std::map<std::string, CharSize>::const_iterator Iter;
	Iter iter = str_charsize_.begin();
	Iter end = str_charsize_.end();
	while (iter != end) {
		charsize_str_.insert(std::make_pair(iter->second, iter->first));
		++iter;
	}
}

}

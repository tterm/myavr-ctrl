/*
 * CharSizeUtils.cpp
 *
 *  Created on: 16.12.2011
 *      Author: tterm
 */

#include "CharSizeUtils.h"

namespace TTE {

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

const std::map<CharSize, std::string> & CharSizeUtils::getCharsizeStr(void) const {
	return charsize_str_;
}

CharSize CharSizeUtils::getCharSize(const std::string & charsize) const {
	std::map<std::string, CharSize>::const_iterator iter = str_charsize_.find(charsize);
	if (iter != str_charsize_.end()) {
		return iter->second;
	}
	return LibSerial::SerialStreamBuf::CHAR_SIZE_INVALID;
}

void CharSizeUtils::init(void) {
	str_charsize_.insert(std::make_pair("5", LibSerial::SerialStreamBuf::CHAR_SIZE_5));
	str_charsize_.insert(std::make_pair("6", LibSerial::SerialStreamBuf::CHAR_SIZE_6));
	str_charsize_.insert(std::make_pair("7", LibSerial::SerialStreamBuf::CHAR_SIZE_7));
	str_charsize_.insert(std::make_pair("8", LibSerial::SerialStreamBuf::CHAR_SIZE_8));

	std::map<std::string, CharSize>::const_iterator iter = str_charsize_.begin();
	while (iter != str_charsize_.end()) {
		charsize_str_.insert(std::make_pair(iter->second, iter->first));
		++iter;
	}
}

}

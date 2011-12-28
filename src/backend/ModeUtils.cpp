/*
 * ModeUtils.cpp
 *
 *  Created on: 18.12.2011
 *      Author: tterm
 */

#include "ModeUtils.h"

namespace backend {

const char * ModeUtils::prefix = "\xE6\xB5\xBA\xB9\xB2\xB3\xA9";
ModeUtils * ModeUtils::instance_ = 0;

ModeUtils::ModeUtils() {
	init();
}

ModeUtils::~ModeUtils() {
}

ModeUtils * ModeUtils::instance(void) {
	if (instance_ == 0) {
		instance_ = new ModeUtils();
	}
	return instance_;
}

std::string ModeUtils::getMode(const char & mode) const {
	std::map<char, std::string>::const_iterator iter =
			mode_to_str_.find(mode);
	if (iter != mode_to_str_.end()) {
		return iter->second;
	}
	throw std::string();
}

char ModeUtils::getMode(const std::string & mode) const {
	std::map<std::string, char>::const_iterator iter =
			str_to_mode_.find(mode);
	if (iter != str_to_mode_.end()) {
		return iter->second;
	}
	throw "Mode not available";
}

const std::map<std::string, char> & ModeUtils::getModes(void) const {
	return str_to_mode_;
}

void ModeUtils::init(void) {
	str_to_mode_.insert(std::make_pair("Program", 'p'));
	str_to_mode_.insert(std::make_pair("Data", 'd'));
	str_to_mode_.insert(std::make_pair("Reset Board", 'r'));
	str_to_mode_.insert(std::make_pair("Reset Programmer", 'R'));
	std::map<std::string, char>::const_iterator iter =
			str_to_mode_.begin();
	while (iter != str_to_mode_.end()) {
		mode_to_str_.insert(std::make_pair(iter->second, iter->first));
		++iter;
	}
}

}  // namespace TTE

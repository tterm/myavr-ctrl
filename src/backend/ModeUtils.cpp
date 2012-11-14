/*
 * ModeUtils.cpp
 *
 *  Created on: 18.12.2011
 *      Author: tterm
 */

#include "ModeUtils.h"

using namespace log4cxx;


namespace backend {

LoggerPtr ModeUtils::cdtor(Logger::getLogger("lifecycle"));

const char * ModeUtils::request_prefix = "\xE6\xB5\xBA\xB9\xB2\xB3\xA9";
const char * ModeUtils::response_prefix = "\xF7\xB1";
ModeUtils * ModeUtils::instance_ = 0;

ModeUtils::ModeUtils() {
	init();
	LOG4CXX_TRACE(cdtor, "ModeUtils()")
}

ModeUtils::~ModeUtils() {
	LOG4CXX_TRACE(cdtor, "~ModeUtils()")
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
	str_to_mode_.insert(std::make_pair("Power on Board", '+'));
	str_to_mode_.insert(std::make_pair("Power off Board", '-'));
	str_to_mode_.insert(std::make_pair("Status", 'i'));
	std::map<std::string, char>::const_iterator iter =
			str_to_mode_.begin();
	while (iter != str_to_mode_.end()) {
		mode_to_str_.insert(std::make_pair(iter->second, iter->first));
		++iter;
	}
}

}  // namespace TTE

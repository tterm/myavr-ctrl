/*
 * ConfigModel.cpp
 *
 *  Created on: 28.12.2011
 *      Author: tterm
 */

#include "ConfigModel.h"

namespace backend {

ConfigModel::ConfigModel() {
	init();
}

ConfigModel::~ConfigModel() {
}

PortConfig * ConfigModel::getPortConfig(const std::string & name) throw(ConfigNotFoundException){
	ConfigTable::iterator iter = configs_.find(name);
	if (iter != configs_.end()) {
		return &(iter->second);
	}
	throw ConfigNotFoundException(name);
}

std::vector<std::string> ConfigModel::getConfigNames(void) const {
	std::vector<std::string> results;
	ConfigTable::const_iterator iter = configs_.begin();
	while (iter != configs_.end()) {
		results.push_back(iter->first);
		++iter;
	}
	return results;
}

void ConfigModel::init(void) {
	PortConfig mk2(LibSerial::SerialStreamBuf::BAUD_19200,
			LibSerial::SerialStreamBuf::CHAR_SIZE_8,
			LibSerial::SerialStreamBuf::FLOW_CONTROL_NONE,
			LibSerial::SerialStreamBuf::PARITY_NONE,
			1);
	configs_["myAVRMKII"] = mk2;
}

}

/*
 * ConfigModel.h
 *
 *  Created on: 28.12.2011
 *      Author: tterm
 */
#ifndef CONFIGMODEL_H_
#define CONFIGMODEL_H_

#include <tr1_impl/unordered_map>

namespace backend {

class ConfigModel {
public:
	ConfigModel();
	virtual ~ConfigModel();

	std::unordered_map<std::string, PortConfig> configs_;
	// map von port configs
};

}

#endif /* CONFIGMODEL_H_ */

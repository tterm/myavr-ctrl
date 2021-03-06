/*
 * ConfigModel.h
 *
 *  Created on: 28.12.2011
 *      Author: tterm
 */
#ifndef CONFIGMODEL_H_
#define CONFIGMODEL_H_

#include "PortConfig.h"
#include "ConfigNotFoundException.h"
#include <string>
#include <vector>
#include <tr1/unordered_map>
#include <log4cxx/logger.h>

namespace backend {

typedef std::tr1::unordered_map<std::string, PortConfig> ConfigTable;

class ConfigModel {
public:
	ConfigModel();
	virtual ~ConfigModel();
	PortConfig * getPortConfig(const std::string & name) throw(ConfigNotFoundException);
	std::vector<std::string> getConfigNames(void) const;

private:
	void init(void);
	ConfigTable configs_;
	static log4cxx::LoggerPtr cdtor;
	static log4cxx::LoggerPtr logger;

};

}

#endif /* CONFIGMODEL_H_ */

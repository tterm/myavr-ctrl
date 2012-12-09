/*
 * ConfigNotFoundException.cpp
 *
 *  Created on: 30.12.2011
 *      Author: tterm
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "ConfigNotFoundException.h"

#include <sstream>

namespace backend {

const char * ConfigNotFoundException::reason = "No port config found with name: ";

ConfigNotFoundException::ConfigNotFoundException(const std::string & config_name)
:config_name_(config_name)
{

}

ConfigNotFoundException::~ConfigNotFoundException() throw() {
}

const char* ConfigNotFoundException::what() const throw() {
	std::stringstream str;
	str << reason;
	str << config_name_;
	return str.str().c_str();
}

}

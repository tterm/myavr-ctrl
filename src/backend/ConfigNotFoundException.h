/*
 * ConfigNotFoundException.h
 *
 *  Created on: 30.12.2011
 *      Author: tterm
 */

#ifndef CONFIGNOTFOUNDEXCEPTION_H_
#define CONFIGNOTFOUNDEXCEPTION_H_

#include <exception>
#include <string>

namespace backend {

class ConfigNotFoundException: public std::exception {
public:
	static const char * reason;
	ConfigNotFoundException(const std::string & config_name);
	virtual ~ConfigNotFoundException() throw();
	virtual const char* what() const throw();
private:
	std::string config_name_;
};

}

#endif /* CONFIGNOTFOUNDEXCEPTION_H_ */

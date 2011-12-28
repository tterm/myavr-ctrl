/*
 * DeviceNotFoundException.h
 *
 *  Created on: 22.12.2011
 *      Author: tterm
 */

#ifndef DEVICENOTFOUNDEXCEPTION_H_
#define DEVICENOTFOUNDEXCEPTION_H_

#include "PortConfig.h"
#include <exception>
#include <string>

namespace backend {

class DeviceNotFoundException: public std::exception {
public:
	DeviceNotFoundException(const PortConfig & config);
	virtual ~DeviceNotFoundException() throw();
	virtual const char* what() const throw();
private:
	std::string reason_;
};

}

#endif /* DEVICENOTFOUNDEXCEPTION_H_ */

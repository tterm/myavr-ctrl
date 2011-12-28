/*
 * DeviceNotFoundException.cpp
 *
 *  Created on: 22.12.2011
 *      Author: tterm
 */

#include "DeviceNotFoundException.h"

namespace backend {

DeviceNotFoundException::DeviceNotFoundException(const PortConfig & config) {
	reason_ = ("No device found on ");
	reason_ += config.getDevice();

}

DeviceNotFoundException::~DeviceNotFoundException() throw() {
}

const char* DeviceNotFoundException::what() const throw() {
	return reason_.c_str();
}
}

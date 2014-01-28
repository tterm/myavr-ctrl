/*
 * SerialPortCommunicationError.cpp
 *
 *  Created on: 28.01.2014
 *      Author: tterm
 */

#include "SerialPortCommunicationError.h"

namespace backend {

const char * SerialPortCommunicationError::reason = "Error communication with the serial port. Please check your configuration";

const char* SerialPortCommunicationError::what() const throw() {
    return reason;
}

} /* namespace backend */

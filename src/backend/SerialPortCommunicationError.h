/*
 * SerialPortCommunicationError.h
 *
 *  Created on: 28.01.2014
 *      Author: tterm
 */

#ifndef SERIALPORTCOMMUNICATIONERROR_H_
#define SERIALPORTCOMMUNICATIONERROR_H_

#include <exception>

namespace backend {

class SerialPortCommunicationError : public std::exception {
public:
    static const char * reason;
    virtual const char* what() const throw();
};

} /* namespace backend */

#endif /* SERIALPORTCOMMUNICATIONERROR_H_ */

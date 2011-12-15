/*
 * Constants.h
 *
 *  Created on: 15.12.2011
 *      Author: tterm
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#include <SerialStreamBuf.h>
#include <string>
#include <map>

namespace TTE {

typedef LibSerial::SerialStreamBuf::BaudRateEnum BaudRate;

class Constants {
public:
	~Constants();
	static Constants * instance();
	const std::map<std::string, BaudRate> & getBaudRates(void) const;
private:
	Constants();
	void initBaudRates(void);
private:
	static Constants * instance_;
	std::map<std::string, BaudRate> baud_rates_;
};

}

#endif /* CONSTANTS_H_ */

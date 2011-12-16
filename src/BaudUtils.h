/*
 * BaudUtils.h
 *
 *  Created on: 16.12.2011
 *      Author: tterm
 */

#ifndef BAUDUTILS_H_
#define BAUDUTILS_H_

#include <map>
#include <SerialStreamBuf.h>

namespace TTE {

typedef LibSerial::SerialStreamBuf::BaudRateEnum BaudRate;

class BaudUtils {
public:
	~BaudUtils();
	static BaudUtils * instance(void);
	const std::map<std::string, BaudRate> & getBaudRates(void) const;
	const std::map<BaudRate, std::string> & getBauds(void) const;

private:
	BaudUtils();
	BaudUtils(const BaudUtils & to_copy);
	void operator=(const BaudUtils & to_assign);
	void initBaudRates(void);
private:
	static BaudUtils * instance_;
	std::map<std::string, BaudRate> baud_rates_;
	std::map<BaudRate, std::string> baud_str_;
};

}

#endif /* BAUDUTILS_H_ */

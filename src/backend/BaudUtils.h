/*
 * BaudUtils.h
 *
 *  Created on: 16.12.2011
 *      Author: tterm
 */

#ifndef BAUDUTILS_H_
#define BAUDUTILS_H_

#include <map>
#include <boost/asio.hpp>

namespace backend {

typedef boost::asio::serial_port_base::baud_rate BaudRate;

class BaudComparator {
public:
	bool operator()(const BaudRate & baud_a, const BaudRate & baud_b) {
		return baud_a.value() < baud_b.value();
	}

};

class BaudUtils {
public:
	~BaudUtils();
	static BaudUtils * instance(void);
	const std::map<std::string, BaudRate> & getBaudRates(void) const;
	const std::map<BaudRate, std::string, BaudComparator> & getBauds(void) const;
	BaudRate getBaudRate(const std::string & rate) const;

private:
	BaudUtils();
	BaudUtils(const BaudUtils & to_copy);
	void operator=(const BaudUtils & to_assign);
	void initBaudRates(void);
private:
	static BaudUtils * instance_;
	std::map<std::string, BaudRate> baud_rates_;
	std::map<BaudRate, std::string, BaudComparator> baud_str_;
};



}

#endif /* BAUDUTILS_H_ */

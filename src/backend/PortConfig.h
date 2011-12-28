/*
 * PortConfig.h
 *
 *  Created on: 19.12.2011
 *      Author: tterm
 */

#ifndef PORTCONFIG_H_
#define PORTCONFIG_H_

#include <string>
#include <iosfwd>

namespace backend {

class PortConfig {
public:
	PortConfig();
	PortConfig(const std::string & baud,
			const std::string & charsize, const std::string & flowcontrol,
			const std::string & parity, const std::string & stopbit);
	~PortConfig();
	const std::string & getBaud(void) const {
		return baud_;
	}
	const std::string & getCharsize(void) const {
		return charsize_;
	}

	const std::string & getFlowControl(void) const {
		return flow_conrol_;
	}

	const std::string & getParity(void) const {
		return parity_;
	}

	unsigned int getStopBit(void) const {
		return stopbit_;
	}

	const std::string & getDevice(void) const {
		return device_;
	}

	void setDevice(const std::string & device) {
		device_ = device;
	}

	const std::string & getMode(void) const {
		return mode_;
	}

	void setMode(const std::string & mode) {
		mode_ = mode;
	}

private:
	std::string baud_;
	std::string charsize_;
	std::string flow_conrol_;
	std::string mode_;
	std::string parity_;
	unsigned int stopbit_;
	std::string device_;
};

std::ostream & operator<<(std::ostream & os, const PortConfig & config);

}

#endif /* PORTCONFIG_H_ */

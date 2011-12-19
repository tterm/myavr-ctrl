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

class PortConfig {
public:
	PortConfig(const std::string & device, const std::string & baud,
			const std::string & charsize, const std::string & flowcontrol,
			const std::string & parity, const std::string & stopbit,
			const std::string & mode);
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

	const std::string & getMode(void) const {
		return mode_;
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

#endif /* PORTCONFIG_H_ */

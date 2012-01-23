/*
 * PortConfig.h
 *
 *  Created on: 29.12.2011
 *      Author: tterm
 */

#ifndef PORTCONFIG_H_
#define PORTCONFIG_H_

#include <iosfwd>
#include <string>
#include <SerialStreamBuf.h>

#include <log4cxx/logger.h>

namespace backend {

typedef LibSerial::SerialStreamBuf::BaudRateEnum BaudRateEnum;
typedef LibSerial::SerialStreamBuf::CharSizeEnum CharSizeEnum;
typedef LibSerial::SerialStreamBuf::FlowControlEnum FlowControlEnum;
typedef LibSerial::SerialStreamBuf::ParityEnum ParityEnum;

class PortConfig {
public:
	PortConfig() {}
	PortConfig(BaudRateEnum baud,
			CharSizeEnum char_size,
			FlowControlEnum flow_ctrl,
			ParityEnum parity,
			unsigned int stopbit);
	PortConfig(const PortConfig & to_copy);
	~PortConfig();
	PortConfig & operator=(const PortConfig & to_assign);

	BaudRateEnum getBaudRate(void) const {
		return baud_;
	}

	void setBaudRate(BaudRateEnum baud) {
		baud_ = baud;
	}

	CharSizeEnum getCharSize(void) const {
		return char_size_;
	}

	void setCharSize(CharSizeEnum char_size) {
		char_size_ = char_size;
	}

	FlowControlEnum getFlowControl(void) const {
		return flow_ctrl_;
	}

	void setFlowControl(FlowControlEnum flow_ctrl) {
		flow_ctrl_ = flow_ctrl;
	}

	ParityEnum getParity(void) const {
		return parity_;
	}

	void setParity(ParityEnum parity) {
		parity_ = parity;
	}

	unsigned int getStopBits(void) const {
		return stopbit_;
	}

	void setStopBits(unsigned int stop_bits) {
		stopbit_ = stop_bits;
	}

	const std::string & getMode(void) const {
		return mode_;
	}

	void setMode(const std::string & mode) {
		mode_ = mode;
	}

	const std::string & getDevice(void) const {
		return device_;
	}

	void setDevice(const std::string & device) {
		device_ = device;
	}

private:
	void copy_values(const PortConfig & to_copy);

private:
	BaudRateEnum baud_;
	CharSizeEnum char_size_;
	FlowControlEnum flow_ctrl_;
	ParityEnum parity_;
	unsigned int stopbit_;
	std::string device_;
	std::string mode_;
	static log4cxx::LoggerPtr cdtor;
	static log4cxx::LoggerPtr logger;
};

std::ostream & operator<<(std::ostream & os, const PortConfig & pc);

}

#endif /* PORTCONFIG_H_ */

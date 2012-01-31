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
#include <boost/asio.hpp>

#include <log4cxx/logger.h>

namespace backend {

typedef boost::asio::serial_port_base::baud_rate BaudRate;
typedef boost::asio::serial_port_base::character_size CharSize;
typedef boost::asio::serial_port_base::flow_control FlowControl;
typedef boost::asio::serial_port_base::parity Parity;
typedef boost::asio::serial_port_base::stop_bits StopBits;

class PortConfig {
public:
	PortConfig() {}
	PortConfig(BaudRate baud,
			CharSize char_size,
			FlowControl flow_ctrl,
			Parity parity,
			StopBits stopbit);
	PortConfig(const PortConfig & to_copy);
	~PortConfig();
	PortConfig & operator=(const PortConfig & to_assign);

	BaudRate getBaudRate(void) const {
		return baud_;
	}

	void setBaudRate(BaudRate baud) {
		baud_ = baud;
	}

	CharSize getCharSize(void) const {
		return char_size_;
	}

	void setCharSize(CharSize char_size) {
		char_size_ = char_size;
	}

	FlowControl getFlowControl(void) const {
		return flow_ctrl_;
	}

	void setFlowControl(FlowControl flow_ctrl) {
		flow_ctrl_ = flow_ctrl;
	}

	Parity getParity(void) const {
		return parity_;
	}

	void setParity(Parity parity) {
		parity_ = parity;
	}

	StopBits getStopBits(void) const {
		return stopbit_;
	}

	void setStopBits(StopBits stop_bits) {
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
	BaudRate baud_;
	CharSize char_size_;
	FlowControl flow_ctrl_;
	Parity parity_;
	StopBits stopbit_;
	std::string device_;
	std::string mode_;
	static log4cxx::LoggerPtr cdtor;
	static log4cxx::LoggerPtr logger;
};

std::ostream & operator<<(std::ostream & os, const PortConfig & pc);

}

#endif /* PORTCONFIG_H_ */

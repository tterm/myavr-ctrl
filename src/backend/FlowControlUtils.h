/*
 * FlowControlUtils.h
 *
 *  Created on: 16.12.2011
 *      Author: tterm
 */

#ifndef FLOWCONTROLUTILS_H_
#define FLOWCONTROLUTILS_H_

#include <map>
#include <string>
#include <boost/asio.hpp>

namespace backend {

typedef boost::asio::serial_port_base::flow_control FlowControl;

class FlowControlComparator {
public:
	bool operator()(const FlowControl & a, const FlowControl & b) {
		return a.value() < b.value();
	}
};

class FlowControlUtils {
public:
	~FlowControlUtils();
	const std::map<std::string, FlowControl> & getStrFlowControl(void) const;
	const std::map<FlowControl, std::string, FlowControlComparator> & getFlowControl(void) const;
	static FlowControlUtils * instance(void);
	FlowControl getFlowControl(const std::string & flowcontrol) const;

private:
	FlowControlUtils();
	FlowControlUtils(const FlowControlUtils &);
	void operator=(const FlowControlUtils &);
	void init(void);

private:
	static FlowControlUtils * instance_;
	std::map<std::string, FlowControl> str_flow_controls_;
	std::map<FlowControl, std::string, FlowControlComparator> flow_controls_str_;

};

}

#endif /* FLOWCONTROLUTILS_H_ */

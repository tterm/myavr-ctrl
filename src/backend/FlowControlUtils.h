/*
 * FlowControlUtils.h
 *
 *  Created on: 16.12.2011
 *      Author: tterm
 */

#ifndef FLOWCONTROLUTILS_H_
#define FLOWCONTROLUTILS_H_

#include <SerialStreamBuf.h>
#include <map>
#include <string>

namespace TTE {

typedef LibSerial::SerialStreamBuf::FlowControlEnum FlowControl;
typedef std::map<FlowControl, std::string> FlowControlMap;

class FlowControlUtils {
public:
	~FlowControlUtils();
	const std::map<std::string, FlowControl> & getStrFlowControl(void) const;
	const std::map<FlowControl, std::string> & getFlowControl(void) const;
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
	std::map<FlowControl, std::string> flow_controls_str_;

};

}

#endif /* FLOWCONTROLUTILS_H_ */

/*
 * FlowControlUtils.cpp
 *
 *  Created on: 16.12.2011
 *      Author: tterm
 */

#include "FlowControlUtils.h"

namespace backend {

FlowControlUtils * FlowControlUtils::instance_ = 0;

FlowControlUtils::FlowControlUtils() {
	init();
}

FlowControlUtils::~FlowControlUtils() {
}

FlowControlUtils * FlowControlUtils::instance(void) {
		if (instance_ == 0) {
			instance_ = new FlowControlUtils();
		}
		return instance_;
}

const std::map<std::string, FlowControl> & FlowControlUtils::getStrFlowControl(void) const {
	return str_flow_controls_;
}

const std::map<FlowControl, std::string, FlowControlComparator> & FlowControlUtils::getFlowControl(void) const {
	return flow_controls_str_;
}

FlowControl FlowControlUtils::getFlowControl(const std::string & flowcontrol) const {
	std::map<std::string, FlowControl>::const_iterator iter = str_flow_controls_.find(flowcontrol);
	if (iter != str_flow_controls_.end()) {
		return iter->second;
	}
	return FlowControl(FlowControl::none);
}

void FlowControlUtils::init(void) {
	str_flow_controls_.insert(std::make_pair("Hardware", FlowControl(FlowControl::hardware)));
	str_flow_controls_.insert(std::make_pair("Software", FlowControl(FlowControl::software)));
	str_flow_controls_.insert(std::make_pair("None", FlowControl(FlowControl::none)));

	typedef std::map<std::string, FlowControl>::const_iterator CIter;
	CIter iter = str_flow_controls_.begin();
	CIter end = str_flow_controls_.end();
	while (iter != end) {
		flow_controls_str_.insert(std::make_pair(iter->second, iter->first));
		++iter;
	}
}

}

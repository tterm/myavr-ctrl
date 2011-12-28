/*
 * Command.h
 *
 *  Created on: 19.12.2011
 *      Author: tterm
 */

#ifndef COMMAND_H_
#define COMMAND_H_

#include "DeviceNotFoundException.h"
#include "PortConfig.h"

namespace backend {

class Command {
public:
	Command();
	~Command();
	void execute(const PortConfig & config) throw(DeviceNotFoundException);
};

}

#endif /* COMMAND_H_ */

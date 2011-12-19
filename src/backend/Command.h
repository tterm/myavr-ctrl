/*
 * Command.h
 *
 *  Created on: 19.12.2011
 *      Author: tterm
 */

#ifndef COMMAND_H_
#define COMMAND_H_

#include "PortConfig.h"

namespace TTE {

class Command {
public:
	Command();
	~Command();
	void execute(const PortConfig & config);
};

}

#endif /* COMMAND_H_ */

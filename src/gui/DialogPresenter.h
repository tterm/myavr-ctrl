/*
 * DialogPresenter.h
 *
 *  Created on: 28.12.2011
 *      Author: tterm
 */

#ifndef DIALOGPRESENTER_H_
#define DIALOGPRESENTER_H_

#include "backend/PortConfig.h"

namespace TTE {

class DialogPresenter {
public:
	DialogPresenter(PortConfig * config);
	virtual ~DialogPresenter();
	void start(void);
private:
	PortConfig * config_;
	ConfigDialog * dialog_;
};

}

#endif /* DIALOGPRESENTER_H_ */

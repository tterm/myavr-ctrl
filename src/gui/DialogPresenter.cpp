/*
 * DialogPresenter.cpp
 *
 *  Created on: 28.12.2011
 *      Author: tterm
 */

#include "DialogPresenter.h"

namespace TTE {


DialogPresenter::DialogPresenter(PortConfig * config)
:config_(config), dialog_(0)
{
}

DialogPresenter::~DialogPresenter() {
}

void DialogPresenter::start(void) {
	dialog_->exec();
}

}

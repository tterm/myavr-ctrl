/*
 * MainWindowPresenter.cpp
 *
 *  Created on: 28.12.2011
 *      Author: tterm
 */

#include "MainWindowPresenter.h"
#include "MainWindow.h"
#include "DialogPresenter.h"

namespace TTE {

MainWindowPresenter::MainWindowPresenter(PortConfig * config)
:config_(config)
{
	mainWindow_ = new MainWindow;
	dialogPresenter_ = new DialogPresenter(config);
}

MainWindowPresenter::~MainWindowPresenter() {
	delete mainWindow_;
}

void MainWindowPresenter::start(void) {
	mainWindow_->show();
}

void MainWindowPresenter::on_edit_config_clicked(void) {
	dialogPresenter_->start();
}

}

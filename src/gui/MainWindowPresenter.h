/*
 * MainWindowPresenter.h
 *
 *  Created on: 28.12.2011
 *      Author: tterm
 */

#ifndef MAINWINDOWPRESENTER_H_
#define MAINWINDOWPRESENTER_H_

#include "backend/PortConfig.h"


namespace TTE {

class MainWindow;
class DialogPresenter;

class MainWindowPresenter {
public:
	MainWindowPresenter(PortConfig * config);
	virtual ~MainWindowPresenter();
	void start(void);

public slots:
	void on_edit_config_clicked(void);

private:
	PortConfig * config_;
	MainWindow * mainWindow_;
	DialogPresenter * dialogPresenter_;
};

}

#endif /* MAINWINDOWPRESENTER_H_ */

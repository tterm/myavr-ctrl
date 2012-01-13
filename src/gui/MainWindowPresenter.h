/*
 * MainWindowPresenter.h
 *
 *  Created on: 28.12.2011
 *      Author: tterm
 */

#ifndef MAINWINDOWPRESENTER_H_
#define MAINWINDOWPRESENTER_H_

#include <QtCore/QObject>
#include <QtCore/QStringList>

#include <backend/DeviceNotFoundException.h>

namespace backend {
class ConfigModel;
}

namespace gui {

class MainWindow;
class DialogPresenter;

class MainWindowPresenter : public QObject {
	Q_OBJECT
public:
	MainWindowPresenter(backend::ConfigModel * model, QObject * parent = 0);
	virtual ~MainWindowPresenter();
	void start(void);
	void editConfig(const QString & name);
	QStringList getConfigNames(void) const;
	QStringList getModes(void) const;
	void onPush(void) throw(backend::DeviceNotFoundException);

private:
	backend::ConfigModel * model_;
	MainWindow * mainWindow_;
	DialogPresenter * dialogPresenter_;
};

}

#endif /* MAINWINDOWPRESENTER_H_ */

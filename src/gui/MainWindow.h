/*
 * MainWindow.h
 *
 *  Created on: 15.12.2011
 *      Author: tterm
 */

#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <QtGui/QMainWindow>

#include <log4cxx/logger.h>

QT_BEGIN_NAMESPACE
class QComboBox;
class QLineEdit;
class QMenu;
class QPushButton;
QT_END_NAMESPACE

namespace gui {

class MainWindowPresenter;

class MainWindow : public QMainWindow {
	Q_OBJECT
public:
	MainWindow(MainWindowPresenter * presenter, QWidget * parent = 0);
	virtual ~MainWindow();
	QString getConfigValue(void) const;
	QString getModeValue(void) const;
	QString getDeviceValue(void) const;

public slots:
	void on_push_button_clicked(void);
	void on_edit_config_clicked(void);

private:
	void setupUI(void);

private:
	QComboBox * mode_box_;
	QLineEdit * device_;
	QComboBox * config_box_;
	QPushButton * push_it_button_;
	QPushButton * edit_button_;
	MainWindowPresenter * presenter_;
	static log4cxx::LoggerPtr cdtor;
	static log4cxx::LoggerPtr logger;
};

}

#endif /* MAINWINDOW_H_ */

/*
 * MainWindow.h
 *
 *  Created on: 15.12.2011
 *      Author: tterm
 */

#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <QtGui/QMainWindow>

QT_BEGIN_NAMESPACE
class QComboBox;
class QLineEdit;
class QMenu;
QT_END_NAMESPACE

namespace TTE {

class ConfigDialog;

class MainWindow : public QMainWindow {
	Q_OBJECT
public:
	MainWindow(QWidget * parent = 0);
	virtual ~MainWindow();

public slots:
	void on_push_button_clicked(void);
	void on_config_action_triggered(void);
	void on_ok_button_clicked(void);
	void on_cancel_button_clicked(void);

private:
	void setupUI(void);
	void createActions(void);
	void createMenus(void);

private:
	QComboBox * mode_box_;
	QLineEdit * device_;
	QMenu * config_menu_;
};

}

#endif /* MAINWINDOW_H_ */

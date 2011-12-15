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
QT_END_NAMESPACE

namespace TTE {

class MainWindow : public QMainWindow {
	Q_OBJECT
public:
	MainWindow(QWidget * parent = 0);
	virtual ~MainWindow();

public slots:
	void on_push_button_clicked(void);

private:
	void setupUI(void);

private:
	QComboBox * baud_box;
	QComboBox * stopbit_box;
	QComboBox * charsize_box;
	QComboBox * parity_box;
	QComboBox * flowctrl_box;
};

}

#endif /* MAINWINDOW_H_ */

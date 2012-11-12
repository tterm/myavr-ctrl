/*
 * MainWindow.cpp
 *
 *  Created on: 15.12.2011
 *      Author: tterm
 */

#include "MainWindow.h"
#include "MainWindowPresenter.h"

#include <backend/PortConfig.h>
#include <backend/Command.h>

#include <QtGui/QGridLayout>
#include <QtGui/QVBoxLayout>
#include <QtGui/QPushButton>
#include <QtGui/QComboBox>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QStatusBar>
#include <QtGui/QMessageBox>
#include <QtGui/QApplication>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QAction>

#include <iostream>
#include <sstream>

using namespace backend;
using namespace log4cxx;


namespace gui {

LoggerPtr MainWindow::cdtor(Logger::getLogger("lifecycle"));
LoggerPtr MainWindow::logger(Logger::getLogger("gui.MainWindow"));


MainWindow::MainWindow(MainWindowPresenter * presenter, QWidget * parent) :
	QMainWindow(parent),
	mode_box_(0),
	device_(0),
	config_box_(0),
	push_it_button_(0),
	edit_button_(0),
	presenter_(presenter)
{
	setupUI();
	metaObject()->connectSlotsByName(this);
	LOG4CXX_TRACE(cdtor, "MainWindow()");
}

MainWindow::~MainWindow() {
	LOG4CXX_TRACE(cdtor, "~MainWindow()");
}

void MainWindow::setupUI(void) {
	QWidget * central = new QWidget(this);
	setCentralWidget(central);
	QVBoxLayout * box = new QVBoxLayout(central);
	QGridLayout * layout = new QGridLayout;
	box->addLayout(layout);
	int gridrow = 0;

	QStringList list;
	config_box_ = new QComboBox(this);
	config_box_->addItems(presenter_->getConfigNames());
	edit_button_ = new QPushButton(this);
	edit_button_->setObjectName("edit_config");
	edit_button_->setText(tr("Edit"));
	QLabel * config_label = new QLabel(tr("Config"), this);
	layout->addWidget(config_label, gridrow, 0);
	layout->addWidget(config_box_, gridrow, 1);
	layout->addWidget(edit_button_, gridrow, 2);
	++gridrow;

	mode_box_ = new QComboBox(this);
	mode_box_->insertItems(0, presenter_->getModes());
	layout->addWidget(mode_box_, gridrow, 1);
	QLabel * mode_label = new QLabel(tr("Mode"), this);
	layout->addWidget(mode_label, gridrow, 0);
	++gridrow;
	device_ = new QLineEdit(this);
	layout->addWidget(device_, gridrow, 1);
	device_->setText("/dev/ttyUSB0");
	QLabel * device_label = new QLabel(tr("Device"), this);
	layout->addWidget(device_label, gridrow, 0);
	++gridrow;

	push_it_button_ = new QPushButton(central);
	push_it_button_->setText(tr("Push it"));
	push_it_button_->setObjectName("push_button");
	//layout->addWidget(push_it_button_, gridrow, 0);
	box->addWidget(push_it_button_);
	QStatusBar * sb = new QStatusBar(this);
	setStatusBar(sb);
	createMenu();
}

QString MainWindow::getConfigValue(void) const {
	return config_box_->currentText();
}

QString MainWindow::getModeValue(void) const {
	return mode_box_->currentText();
}

QString MainWindow::getDeviceValue(void) const {
	return device_->text();
}

//slots
void MainWindow::on_push_button_clicked(void) {
	if (device_->text().length() == 0) {
		QMessageBox::critical(this, tr("Device error"), tr("A valid device is needed like /dev/ttyUSB0"));
		return;
	}
	try {
		presenter_->onPush();
	} catch (backend::DeviceNotFoundException & ex) {
		QMessageBox::critical(this, tr("Device not found"), QString::fromUtf8(ex.what()));
	}
}

void MainWindow::on_edit_config_clicked(void) {
	presenter_->editConfig(config_box_->currentText());
}

void MainWindow::createMenu(void) {
	QMenuBar * menubar = menuBar();
	QMenu * file_menu = new QMenu(tr("&File"),menubar);
	QAction * exitAct = new QAction(tr("E&xit"), this);
	exitAct->setShortcuts(QKeySequence::Quit);
	exitAct->setStatusTip(tr("Exit the application"));
	connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));
	file_menu->addAction(exitAct);
	menubar->addMenu(file_menu);
}

}

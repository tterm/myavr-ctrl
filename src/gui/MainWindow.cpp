/*
 * MainWindow.cpp
 *
 *  Created on: 15.12.2011
 *      Author: tterm
 */

#include "MainWindow.h"

#include "backend/BaudUtils.h"
#include "backend/CharSizeUtils.h"
#include "backend/FlowControlUtils.h"
#include "backend/ParityUtils.h"
#include "backend/ModeUtils.h"
#include "backend/PortConfig.h"
#include "backend/Command.h"

#include <QtGui/QGridLayout>
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

namespace TTE {

MainWindow::MainWindow(QWidget * parent) :
	QMainWindow(parent), mode_box_(0), device_(0) {
	setupUI();
	metaObject()->connectSlotsByName(this);
}

MainWindow::~MainWindow() {
}

void MainWindow::setupUI(void) {
	createMenus();
	createActions();
	QWidget * central = new QWidget(this);
	setCentralWidget(central);
	QGridLayout * layout = new QGridLayout(central);


	QStringList list;
	mode_box_ = new QComboBox(this);
	ModeUtils * mode_utils = ModeUtils::instance();
	std::map<std::string, char> modes = mode_utils->getModes();
	std::map<std::string, char>::const_iterator mode_iter = modes.begin();
	list.clear();
	while (mode_iter != modes.end()) {
		list.push_back(QString::fromStdString(mode_iter->first));
		++mode_iter;
	}
	mode_box_->insertItems(0, list);
	layout->addWidget(mode_box_, 0, 1);
	QLabel * mode_label = new QLabel(tr("Mode"), this);
	layout->addWidget(mode_label, 0, 0);

	device_ = new QLineEdit(this);
	layout->addWidget(device_, 1, 1);
	QLabel * device_label = new QLabel(tr("Device"), this);
	layout->addWidget(device_label, 1, 0);

	QPushButton * button = new QPushButton(central);
	button->setText("Push it");
	button->setObjectName("push_button");
	layout->addWidget(button);

	QStatusBar * sb = new QStatusBar(this);
	setStatusBar(sb);

}

void MainWindow::createActions(void) {
	QAction * action_dialog = new QAction("config", this);
	action_dialog->setObjectName("config_action");
	config_menu_->addAction(action_dialog);
}

void MainWindow::on_config_action_triggered(void) {
	std::cout << "Action triggered" << std::endl;
}

void MainWindow::createMenus(void) {
	QMenuBar * bar = menuBar();
	config_menu_ = new QMenu("Config", this);
	if (bar != 0) {
		std::cout << " menu !_ 0" << std::endl;
		bar->addMenu(config_menu_);
	}
}

//slots
void MainWindow::on_push_button_clicked(void) {
	std::string command = (ModeUtils::prefix);
	command += ModeUtils::instance()->getMode(mode_box_->currentText().toStdString());
	for (std::string::size_type i = 0, n = command.length() - 1; i < n; ++i) {
		std::cerr << std::hex << (unsigned short)command[i];
	}
	std::cerr << command[command.length() - 1] << std::endl;
}

void MainWindow::on_ok_button_clicked(void) {
	std::cout << "Ok clicked in dialog" << std::endl;
}

void MainWindow::on_cancel_button_clicked(void) {
//	dialog->hide();
}
}

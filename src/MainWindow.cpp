/*
 * MainWindow.cpp
 *
 *  Created on: 15.12.2011
 *      Author: tterm
 */

#include "MainWindow.h"
#include <QtGui/QGridLayout>
#include <QtGui/QPushButton>
#include <QtGui/QComboBox>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QStatusBar>
#include <QtGui/QMessageBox>
#include <QtGui/QApplication>
#include <iostream>
#include <sstream>
#include "backend/BaudUtils.h"
#include "backend/CharSizeUtils.h"
#include "backend/FlowControlUtils.h"
#include "backend/ParityUtils.h"
#include "backend/ModeUtils.h"
#include "backend/PortConfig.h"
#include "backend/Command.h"

namespace TTE {

MainWindow::MainWindow(QWidget * parent) :
	QMainWindow(parent), baud_box(0), stopbit_box(0), charsize_box(0),
			parity_box(0), flowctrl_box(0), mode_box_(0), device_(0) {
	setupUI();
}

MainWindow::~MainWindow() {
}

void MainWindow::setupUI(void) {
	QWidget * central = new QWidget(this);
	setCentralWidget(central);
	QGridLayout * layout = new QGridLayout(central);
	baud_box = new QComboBox(central);
	baud_box->clear();
	BaudUtils * baud_utils = BaudUtils::instance();
	typedef std::map<BaudRate, std::string> BaudRates;
	BaudRates baud_rates = baud_utils->getBauds();
	BaudRates::const_iterator iter = baud_rates.begin();
	QStringList list;
	int current_index = 0;
	for (int i = 0; iter != baud_rates.end(); ++i, ++iter) {
		list.insert(i, QString::fromStdString(iter->second));
		if (iter->first == LibSerial::SerialStreamBuf::BAUD_19200) {
			current_index = i;
		}
	}
	baud_box->insertItems(0, list);
	baud_box->setCurrentIndex(current_index);
	layout->addWidget(baud_box, 0, 0);
	QLabel * baud_label = new QLabel(tr("Baud Rate"), this);
	layout->addWidget(baud_label, 1, 0);

	stopbit_box = new QComboBox(this);
	stopbit_box->clear();
	stopbit_box->addItem("1");
	stopbit_box->addItem("2");
	layout->addWidget(stopbit_box, 0, 1);
	QLabel * stop_label = new QLabel(tr("Stop Bit"), this);
	layout->addWidget(stop_label, 1, 1);

	charsize_box = new QComboBox(this);
	typedef std::map<CharSize, std::string> CharSizeMap;
	CharSizeUtils * charsize_utils = CharSizeUtils::instance();
	CharSizeMap csm = charsize_utils->getCharsizeStr();
	list.clear();
	current_index = 0;
	CharSizeMap::const_iterator csm_iter = csm.begin();
	for (int i = 0; csm_iter != csm.end(); ++i, ++csm_iter) {
		list.insert(i, QString::fromStdString(csm_iter->second));
		if (csm_iter->first == LibSerial::SerialStreamBuf::CHAR_SIZE_8) {
			current_index = i;
		}
	}
	charsize_box->insertItems(0, list);
	charsize_box->setCurrentIndex(current_index);
	layout->addWidget(charsize_box, 0, 2);
	QLabel * charsize_label = new QLabel(tr("Char Size"), this);
	layout->addWidget(charsize_label, 1, 2);

	parity_box = new QComboBox(this);
	ParityUtils * par_util = ParityUtils::instance();
	ParityStringMap psm = par_util->getParityStrMap();
	ParityStringMap::const_iterator psm_iter = psm.begin();
	list.clear();
	current_index = 0;
	for (int i = 0; psm_iter != psm.end(); ++i, ++psm_iter) {
		list.insert(i, QString::fromStdString(psm_iter->second));
		if (psm_iter->first == LibSerial::SerialStreamBuf::PARITY_NONE) {
			current_index = i;
		}
	}
	parity_box->insertItems(0, list);
	parity_box->setCurrentIndex(current_index);
	layout->addWidget(parity_box, 0, 3);
	QLabel * parity_label = new QLabel(tr("Parity"), this);
	layout->addWidget(parity_label, 1, 3);

	flowctrl_box = new QComboBox(this);
	FlowControlUtils * flowctrl = FlowControlUtils::instance();
	FlowControlMap flcm = flowctrl->getFlowControl();
	FlowControlMap::const_iterator flcm_iter = flcm.begin();
	list.clear();
	current_index = 0;
	for (int i = 0; flcm_iter != flcm.end(); ++i, ++flcm_iter) {
		list.insert(i, QString::fromStdString(flcm_iter->second));
		if (flcm_iter->first == LibSerial::SerialStreamBuf::FLOW_CONTROL_NONE) {
			current_index = i;
		}
	}
	flowctrl_box->insertItems(0, list);
	flowctrl_box->setCurrentIndex(current_index);
	layout->addWidget(flowctrl_box, 0, 4);
	QLabel * flowctrl_label = new QLabel(tr("Flow Control"), this);
	layout->addWidget(flowctrl_label, 1, 4);

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
	layout->addWidget(mode_box_, 2, 4);
	QLabel * mode_label = new QLabel(tr("Mode"), this);
	layout->addWidget(mode_label, 3, 4);

	device_ = new QLineEdit(this);
	layout->addWidget(device_, 2, 3);
	QLabel * device_label = new QLabel(tr("Device"), this);
	layout->addWidget(device_label, 3, 3);

	QPushButton * button = new QPushButton(central);
	button->setText("Push it");
	button->setObjectName("push_button");
	layout->addWidget(button, 5, 0, Qt::AlignCenter);
	metaObject()->connectSlotsByName(this);
	QStatusBar * sb = new QStatusBar(this);
	setStatusBar(sb);

}

//slots
void MainWindow::on_push_button_clicked(void) {
	std::string command = (ModeUtils::prefix);
	command += ModeUtils::instance()->getMode(mode_box_->currentText().toStdString());
	for (std::string::size_type i = 0, n = command.length() - 1; i < n; ++i) {
		std::cerr << std::hex << (unsigned short)command[i];
	}
	std::cerr << command[command.length() - 1] << std::endl;
	PortConfig config(device_->text().toStdString(),
			baud_box->currentText().toStdString(),
			charsize_box->currentText().toStdString(),
			flowctrl_box->currentText().toStdString(),
			parity_box->currentText().toStdString(),
			stopbit_box->currentText().toStdString(),
			mode_box_->currentText().toStdString());
	if (config.getDevice().length() < 1) {
		QMessageBox box;
		box.setText("No device set!");
		box.exec();
		return;
	}
	Command cmd;
	try {
		cmd.execute(config);
	} catch (const DeviceNotFoundException & ex) {
		QMessageBox box;
		box.setText(QString::fromUtf8(ex.what()));
		box.exec();
	}
}

}

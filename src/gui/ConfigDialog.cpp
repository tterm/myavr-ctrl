/*
 * ConfigDialog.cpp
 *
 *  Created on: 22.12.2011
 *      Author: tterm
 */

#include "ConfigDialog.h"
#include "backend/BaudUtils.h"
#include "backend/CharSizeUtils.h"
#include "backend/FlowControlUtils.h"
#include "backend/ParityUtils.h"
#include "backend/ModeUtils.h"
#include "backend/PortConfig.h"
#include "backend/Command.h"

#include <QtGui/QGridLayout>
#include <QtGui/QComboBox>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QLabel>

#include <iostream>

namespace TTE {

ConfigDialog::ConfigDialog(QWidget * parent) :
	QDialog(parent), baud_box_(0), stopbit_box_(0), charsize_box_(0), parity_box_(0),
			flowctrl_box_(0), ok_button_(0),
			cancel_button_(0) {
	setupUi();
	metaObject()->connectSlotsByName(this);
}

ConfigDialog::~ConfigDialog() {
}

void ConfigDialog::setupUi(void) {
	ok_button_ = new QPushButton("OK", this);
	ok_button_->setObjectName("ok_button");
	cancel_button_ = new QPushButton("Cancel");
	cancel_button_->setObjectName("cancel_button");

	QGridLayout * layout = new QGridLayout(this);
	baud_box_ = new QComboBox(this);
	baud_box_->clear();
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
	baud_box_->insertItems(0, list);
	baud_box_->setCurrentIndex(current_index);
	layout->addWidget(baud_box_, 0, 1);
	QLabel * baud_label = new QLabel(tr("Baud Rate"), this);
	layout->addWidget(baud_label, 0, 0);

	stopbit_box_ = new QComboBox(this);
	stopbit_box_->clear();
	stopbit_box_->addItem("1");
	stopbit_box_->addItem("2");
	layout->addWidget(stopbit_box_, 1, 1);
	QLabel * stop_label = new QLabel(tr("Stop Bit"), this);
	layout->addWidget(stop_label, 1, 0);

	charsize_box_ = new QComboBox(this);
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
	charsize_box_->insertItems(0, list);
	charsize_box_->setCurrentIndex(current_index);
	layout->addWidget(charsize_box_, 2, 1);
	QLabel * charsize_label = new QLabel(tr("Char Size"), this);
	layout->addWidget(charsize_label, 2, 0);

	parity_box_ = new QComboBox(this);
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
	parity_box_->insertItems(0, list);
	parity_box_->setCurrentIndex(current_index);
	layout->addWidget(parity_box_, 3, 1);
	QLabel * parity_label = new QLabel(tr("Parity"), this);
	layout->addWidget(parity_label, 3, 0);

	flowctrl_box_ = new QComboBox(this);
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
	flowctrl_box_->insertItems(0, list);
	flowctrl_box_->setCurrentIndex(current_index);
	layout->addWidget(flowctrl_box_, 4, 1);
	QLabel * flowctrl_label = new QLabel(tr("Flow Control"), this);
	layout->addWidget(flowctrl_label, 4, 0);
	layout->addWidget(ok_button_, 5, 0);
	layout->addWidget(cancel_button_, 5, 1);
}

void ConfigDialog::on_ok_button_clicked(void) {
	std::cerr << "On ok button" << std::endl;
}

}

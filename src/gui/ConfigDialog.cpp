/*
 * ConfigDialog.cpp
 *
 *  Created on: 22.12.2011
 *      Author: tterm
 */

#include "ConfigDialog.h"
#include "DialogPresenter.h"

#include <QtGui/QGridLayout>
#include <QtGui/QComboBox>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QLabel>

#include <iostream>

using namespace backend;


namespace gui {

ConfigDialog::ConfigDialog(DialogPresenter * presenter, QWidget * parent) :
	QDialog(parent), baud_box_(0), stopbit_box_(0), charsize_box_(0), parity_box_(0),
			flowctrl_box_(0), ok_button_(0),
			cancel_button_(0), presenter_(presenter) {
	setupUi();
	metaObject()->connectSlotsByName(this);
	std::cout << "ConfigDialog()" << std::endl;
}

ConfigDialog::~ConfigDialog() {
	std::cout << "~ConfigDialog" << std::endl;
}

void ConfigDialog::setupUi(void) {
	int gridrow = 0;
	ok_button_ = new QPushButton("OK", this);
	ok_button_->setObjectName("ok_button");
	cancel_button_ = new QPushButton("Cancel");
	cancel_button_->setObjectName("cancel_button");

	QGridLayout * layout = new QGridLayout(this);
	baud_box_ = new QComboBox(this);
	baud_box_->clear();
	baud_box_->insertItems(0, presenter_->getBaudRates());
	baud_box_->setCurrentIndex(presenter_->getCurrentBaudRateIndex());
	layout->addWidget(baud_box_, gridrow, 1);
	QLabel * baud_label = new QLabel(tr("Baud Rate"), this);
	layout->addWidget(baud_label, gridrow, 0);
	++gridrow;

	stopbit_box_ = new QComboBox(this);
	stopbit_box_->clear();
	stopbit_box_->insertItems(0, presenter_->getStopBits());
	stopbit_box_->setCurrentIndex(presenter_->getCurrentStopBitIndex());
	layout->addWidget(stopbit_box_, gridrow, 1);
	QLabel * stop_label = new QLabel(tr("Stop Bit"), this);
	layout->addWidget(stop_label, gridrow, 0);
	++gridrow;

	charsize_box_ = new QComboBox(this);
	charsize_box_->insertItems(0, presenter_->getCharSizes());
	charsize_box_->setCurrentIndex(presenter_->getCurrentCharSizeIndex());
	layout->addWidget(charsize_box_, gridrow, 1);
	QLabel * charsize_label = new QLabel(tr("Char Size"), this);
	layout->addWidget(charsize_label, gridrow, 0);
	++gridrow;

	parity_box_ = new QComboBox(this);
	parity_box_->insertItems(0, presenter_->getParities());
	parity_box_->setCurrentIndex(presenter_->getCurrentParityIndex());
	layout->addWidget(parity_box_, gridrow, 1);
	QLabel * parity_label = new QLabel(tr("Parity"), this);
	layout->addWidget(parity_label, gridrow, 0);
	++gridrow;

	flowctrl_box_ = new QComboBox(this);
	flowctrl_box_->insertItems(0, presenter_->getFlowControls());
	flowctrl_box_->setCurrentIndex(presenter_->getCurrentFlowControlIndex());
	layout->addWidget(flowctrl_box_, gridrow, 1);
	QLabel * flowctrl_label = new QLabel(tr("Flow Control"), this);
	layout->addWidget(flowctrl_label, gridrow, 0);
	++gridrow;
	layout->addWidget(ok_button_, gridrow, 0);
	layout->addWidget(cancel_button_, gridrow, 1);
	++gridrow;
}

QString ConfigDialog::getBaudValue(void) const {
	return baud_box_->currentText();
}

QString ConfigDialog::getCharSizeValue(void) const {
	return charsize_box_->currentText();
}

QString ConfigDialog::getFlowCtrlValue(void) const {
	return flowctrl_box_->currentText();
}

QString ConfigDialog::getParityValue(void) const {
	return parity_box_->currentText();
}

QString ConfigDialog::getStopBitValue(void) const {
	return stopbit_box_->currentText();
}
void ConfigDialog::on_ok_button_clicked(void) {
	presenter_->onOK();
}

void ConfigDialog::on_cancel_button_clicked(void) {
	done(0);
}

}

/*
 * DialogPresenter.cpp
 *
 *  Created on: 28.12.2011
 *      Author: tterm
 */

#include "DialogPresenter.h"
#include "ConfigDialog.h"
#include <backend/ConfigModel.h>
#include <backend/BaudUtils.h>
#include <backend/CharSizeUtils.h>
#include <backend/FlowControlUtils.h>
#include <backend/ParityUtils.h>
#include <iostream>
#include <map>
#include <string>
#include <QtCore/QString>

using namespace log4cxx;


namespace gui {

const int DialogPresenter::baud_index;
const int DialogPresenter::char_size_index;
const int DialogPresenter::flow_ctrl_index;
const int DialogPresenter::parity_index;
const int DialogPresenter::stopbit_index;

LoggerPtr DialogPresenter::cdtor(Logger::getLogger("lifecycle"));
LoggerPtr DialogPresenter::logger(Logger::getLogger("gui.DialogPresenter"));

DialogPresenter::DialogPresenter(backend::ConfigModel * model, QObject * parent) :
	QObject(parent), model_(model), current_config_(0), dialog_(0) {
	LOG4CXX_TRACE(cdtor,"DialogPresenter()");
}

DialogPresenter::~DialogPresenter() {
	LOG4CXX_TRACE(cdtor,"~DialogPresenter()");
}

void DialogPresenter::start(const QString & config_name)
		throw (backend::ConfigNotFoundException) {
	// throws exception if no config is found
	// presenter is not in an invalid state
	current_config_ = model_->getPortConfig(config_name.toStdString());
	dialog_ = new ConfigDialog(this);
	//dialog_->setAttribute(Qt::WA_DeleteOnClose, true);
	dialog_->exec();
	delete dialog_;
	dialog_ = 0;
}

QStringList DialogPresenter::getBaudRates(void) {
	QStringList result;
	typedef std::map<backend::BaudRate, std::string>::const_iterator
			BaudMapIter;
	BaudMapIter iter = backend::BaudUtils::instance()->getBauds().begin();
	BaudMapIter end = backend::BaudUtils::instance()->getBauds().end();
	for (unsigned int index = 0; iter != end; ++iter, ++index) {
		result.insert(index, QString::fromStdString(iter->second));
		if (iter->first == current_config_->getBaudRate()) {
			current_index_[baud_index] = index;
		}
	}
	return result;
}

unsigned int DialogPresenter::getCurrentBaudRateIndex(void) const {
	return findIndex(baud_index);
}

QStringList DialogPresenter::getCharSizes(void) {
	QStringList result;
	typedef std::map<backend::CharSize, std::string>::const_iterator
			CharSizeIter;
	CharSizeIter iter =
			backend::CharSizeUtils::instance()->getCharsizeStr().begin();
	CharSizeIter end =
			backend::CharSizeUtils::instance()->getCharsizeStr().end();
	for (unsigned int index = 0; iter != end; ++iter, ++index) {
		result.insert(index, QString::fromStdString(iter->second));
		if (iter->first == current_config_->getCharSize()) {
			current_index_[char_size_index] = index;
		}
	}
	return result;
}

unsigned int DialogPresenter::getCurrentCharSizeIndex(void) const {
	return findIndex(char_size_index);
}

QStringList DialogPresenter::getFlowControls(void) {
	QStringList result;
	typedef std::map<backend::FlowControl, std::string>::const_iterator
			FlowCtrlIter;
	FlowCtrlIter iter =
			backend::FlowControlUtils::instance()->getFlowControl().begin();
	FlowCtrlIter end =
			backend::FlowControlUtils::instance()->getFlowControl().end();
	for (unsigned int index = 0; iter != end; ++iter, ++index) {
		result.insert(index, QString::fromStdString(iter->second));
		if (iter->first == current_config_->getFlowControl()) {
			current_index_[flow_ctrl_index] = index;
		}
	}
	return result;
}

unsigned int DialogPresenter::getCurrentFlowControlIndex(void) const {
	return findIndex(flow_ctrl_index);
}

QStringList DialogPresenter::getParities(void) {
	QStringList result;
	typedef std::map<backend::Parity, std::string>::const_iterator ParityIter;
	ParityIter iter =
			backend::ParityUtils::instance()->getParityStrMap().begin();
	ParityIter end = backend::ParityUtils::instance()->getParityStrMap().end();
	for (unsigned int index = 0; iter != end; ++iter, ++index) {
		result.insert(index, QString::fromStdString(iter->second));
		if (iter->first == current_config_->getParity()) {
			current_index_[parity_index] = index;
		}
	}
	return result;
}

unsigned int DialogPresenter::getCurrentParityIndex(void) const {
	return findIndex(parity_index);
}

QStringList DialogPresenter::getStopBits(void) {
	QStringList result;
	result.insert(0, "1");
	result.insert(1, "2");
	if (current_config_->getStopBits() == 1) {
		current_index_[stopbit_index] = 0;
	} else {
		current_index_[stopbit_index] = 1;
	}
	return result;
}

unsigned int DialogPresenter::getCurrentStopBitIndex(void) const {
	return findIndex(stopbit_index);
}

void DialogPresenter::onOK(void) {
	current_config_->setBaudRate(
			backend::BaudUtils::instance()->getBaudRate(
					dialog_->getBaudValue().toStdString()));
	current_config_->setCharSize(
			backend::CharSizeUtils::instance()->getCharSize(
					dialog_->getCharSizeValue().toStdString()));
	current_config_->setFlowControl(
			backend::FlowControlUtils::instance()->getFlowControl(
					dialog_->getFlowCtrlValue().toStdString()));
	current_config_->setParity(backend::ParityUtils::instance()->getParity(dialog_->getParityValue().toStdString()));
	if (dialog_->getStopBitValue().compare("1") == 0) {
		current_config_->setStopBits(1);
	} else {
		current_config_->setStopBits(2);
	}
	dialog_->done(0);
}

unsigned int DialogPresenter::findIndex(const int & type) const {
	std::map<int, unsigned int>::const_iterator iter =
			current_index_.find(type);
	if (iter != current_index_.end()) {
		return iter->second;
	}
	return 0;
}

}

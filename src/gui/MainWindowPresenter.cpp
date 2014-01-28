/*
 * MainWindowPresenter.cpp
 *
 *  Created on: 28.12.2011
 *      Author: tterm
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "MainWindowPresenter.h"
#include "MainWindow.h"
#include "DialogPresenter.h"
#include <backend/ConfigModel.h>
#include <backend/ModeUtils.h>
#include <backend/Command.h>
#include <QtGui/QMessageBox>

#include <iostream>

using namespace log4cxx;

namespace gui {

LoggerPtr MainWindowPresenter::cdtor(Logger::getLogger("lifecycle"));
LoggerPtr MainWindowPresenter::logger(
        Logger::getLogger("gui.MainWindowPresenter"));

MainWindowPresenter::MainWindowPresenter(backend::ConfigModel * model,
        QObject * parent) :
        QObject(parent), model_(model) {
    mainWindow_ = new MainWindow(this);
    dialogPresenter_ = new DialogPresenter(model_, this);
    LOG4CXX_TRACE(cdtor, "MainWindowPresenter()")
}

MainWindowPresenter::~MainWindowPresenter() {
    if (model_ != 0) {
        delete model_;
        model_ = 0;
    }
    delete mainWindow_;
    mainWindow_ = 0;
    LOG4CXX_TRACE(cdtor, "~MainWindowPresenter()")
}

void MainWindowPresenter::start(void) {
    mainWindow_->show();
}

void MainWindowPresenter::editConfig(const QString & name) {
    try {
        dialogPresenter_->start(name);
    } catch (backend::ConfigNotFoundException & ex) {
        QMessageBox::critical(mainWindow_, tr("Config Exception"),
                tr(ex.what()));
    }
}

QStringList MainWindowPresenter::getConfigNames(void) const {
    QStringList result;
    std::vector<std::string> vec = model_->getConfigNames();
    std::vector<std::string>::const_iterator iter = vec.begin();
    while (iter != vec.end()) {
        result.append(QString::fromStdString(*iter));
        ++iter;
    }
    return result;
}

QStringList MainWindowPresenter::getModes(void) const {
    QStringList result;
    typedef std::map<std::string, char>::const_iterator ModeIter;
    ModeIter iter = backend::ModeUtils::instance()->getModes().begin();
    ModeIter end = backend::ModeUtils::instance()->getModes().end();
    while (iter != end) {
        result.append(QString::fromStdString(iter->first));
        ++iter;
    }
    return result;
}

void MainWindowPresenter::onPush(void) throw (backend::DeviceNotFoundException,
        backend::SerialPortCommunicationError) {
    backend::PortConfig * config = model_->getPortConfig(
            mainWindow_->getConfigValue().toStdString());
    config->setMode(mainWindow_->getModeValue().toStdString());
    config->setDevice(mainWindow_->getDeviceValue().toStdString());
    backend::Command command;
    command.execute(*config);
}

}

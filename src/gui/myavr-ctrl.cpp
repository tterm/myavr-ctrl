#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "MainWindowPresenter.h"
#include "backend/PortConfig.h"
#include <backend/ConfigModel.h>
#include <QtGui/QApplication>
#include <QtCore/QDir>
#include <iostream>
#include <log4cxx/logger.h>
#include <log4cxx/xml/domconfigurator.h>

using namespace log4cxx;
using namespace log4cxx::xml;
using namespace log4cxx::helpers;

using namespace gui;

int main(int argc, char ** argv) {

	QApplication app(argc, argv);

    QDir appPath(QApplication::applicationDirPath());
    appPath.cdUp();
	// Load configuration file
    DOMConfigurator::configure(appPath.absolutePath().toStdString() + "/conf/log4cxx.xml");
    LoggerPtr logger(Logger::getLogger("gui.main"));
	LOG4CXX_INFO(logger, "Start myavr control gui")
	backend::ConfigModel * model = new backend::ConfigModel;
	MainWindowPresenter mwp(model);
	mwp.start();
	return app.exec();
}

#include "MainWindowPresenter.h"
#include "backend/PortConfig.h"
#include <backend/ConfigModel.h>
#include <QtGui/QApplication>
#include <iostream>
#include <log4cxx/logger.h>
#include <log4cxx/xml/domconfigurator.h>

using namespace log4cxx;
using namespace log4cxx::xml;
using namespace log4cxx::helpers;

using namespace gui;

int main(int argc, char ** argv) {

	// Load configuration file
	LoggerPtr logger(Logger::getLogger("gui.main"));
	DOMConfigurator::configure("../conf/log4cxx.xml");
	LOG4CXX_INFO(logger, "Start myavr control gui");
	QApplication app(argc, argv);
	backend::ConfigModel * model = new backend::ConfigModel;
	MainWindowPresenter mwp(model);
	mwp.start();
	return app.exec();
}

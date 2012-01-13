
#include "MainWindowPresenter.h"
#include "backend/PortConfig.h"
#include <backend/ConfigModel.h>
#include <QtGui/QApplication>
#include <iostream>

using namespace gui;

int main(int argc, char ** argv) {
	QApplication app(argc, argv);
	backend::ConfigModel * model = new backend::ConfigModel;
	MainWindowPresenter mwp(model);
	mwp.start();
	return app.exec();
}


#include "MainWindowPresenter.h"
#include "backend/PortConfig.h"
#include <QtGui/QApplication>

int main(int argc, char ** argv) {
	QApplication app(argc, argv);
	PortConfig * config = new PortConfig();
	TTE::MainWindowPresenter mwp(config);
	mwp.start();
	//TTE::MainWindow w;
	//w.show();
	return app.exec();
}

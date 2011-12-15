#include <iostream>
#include <QtGui/QApplication>
#include <QtGui/QMainWindow>
#include "MainWindow.h"

int main(int argc, char ** argv) {
	QApplication app(argc, argv);
	TTE::MainWindow w;
	w.show();
	return app.exec();
}

/*
 * MainWindow.cpp
 *
 *  Created on: 15.12.2011
 *      Author: tterm
 */

#include "MainWindow.h"
#include <QtGui/QGridLayout>
#include <QtGui/QPushButton>
#include <QtGui/qcombobox.h>
#include <QtGui/QApplication>
#include <iostream>
#include "Constants.h"

namespace TTE {

MainWindow::MainWindow(QWidget * parent)
:QMainWindow(parent),
 baud_box(0),
 stopbit_box(0),
 charsize_box(0),
 parity_box(0),
 flowctrl_box(0)
{
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
	/*baud_box->insertItems(0, QStringList()
	         << QApplication::translate("MainWindow", "9600", 0, QApplication::UnicodeUTF8)
	         << QApplication::translate("MainWindow", "19200", 0, QApplication::UnicodeUTF8)
	        );*/
	Constants * constants = Constants::instance();
	typedef std::map<std::string, BaudRate> BaudRates;
	BaudRates baud_rates = constants->getBaudRates();
	BaudRates::const_reverse_iterator iter = baud_rates.rbegin();
	QStringList list;
	for (int i = 0; iter != baud_rates.rend(); ++i, ++iter) {
		std::cout << iter->first << std::endl;
		list.push_back(QString::fromStdString(iter->first));
	}
	baud_box->insertItems(0, list);
	layout->addWidget(baud_box, 0, 0);

	QPushButton *  button = new QPushButton(central);
	button->setText("Push it");
	button->setObjectName("push_button");
	layout->addWidget(button);
	metaObject()->connectSlotsByName(this);

}

//slots
void MainWindow::on_push_button_clicked(void) {
	std::cerr << "on_push_buton_clicked and value " << baud_box->currentText().toStdString() << std::endl;


}


}

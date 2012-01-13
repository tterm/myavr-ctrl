/*
 * ConfigDialog.h
 *
 *  Created on: 22.12.2011
 *      Author: tterm
 */

#ifndef CONFIGDIALOG_H_
#define CONFIGDIALOG_H_

#include <QtGui/QDialog>

QT_BEGIN_NAMESPACE
class QComboBox;
class QPushButton;
class QLineEdit;
QT_END_NAMESPACE

namespace gui {

class DialogPresenter;

class ConfigDialog: public QDialog {
Q_OBJECT
public:
	ConfigDialog(DialogPresenter * presenter, QWidget * parent = 0);
	virtual ~ConfigDialog();
	QString getBaudValue(void) const;
	QString getCharSizeValue(void) const;
	QString getFlowCtrlValue(void) const;
	QString getParityValue(void) const;
	QString getStopBitValue(void) const;

private:
	void setupUi(void);

private slots:
	void on_ok_button_clicked();
	void on_cancel_button_clicked();

private:
	QComboBox * baud_box_;
	QComboBox * stopbit_box_;
	QComboBox * charsize_box_;
	QComboBox * parity_box_;
	QComboBox * flowctrl_box_;
	QPushButton * ok_button_;
	QPushButton * cancel_button_;
	DialogPresenter * presenter_;
};

}

#endif /* CONFIGDIALOG_H_ */

/*
 * DialogPresenter.h
 *
 *  Created on: 28.12.2011
 *      Author: tterm
 */

#ifndef DIALOGPRESENTER_H_
#define DIALOGPRESENTER_H_

#include <QtCore/QObject>
#include <backend/ConfigNotFoundException.h>
#include <map>

QT_BEGIN_NAMESPACE
class QString;
QT_END_NAMESPACE

namespace backend {
class ConfigModel;
class PortConfig;
}  // namespace backend

namespace gui {

class ConfigDialog;

class DialogPresenter : public QObject {
	Q_OBJECT
public:
	static const int baud_index = 0;
	static const int char_size_index = 1;
	static const int flow_ctrl_index = 2;
	static const int parity_index = 3;
	static const int stopbit_index = 4;

	DialogPresenter(backend::ConfigModel * model, QObject * parent = 0);
	virtual ~DialogPresenter();

	/*
	 * @brief Create and run a new dialog widget with
	 *        the config choosen by the parameter.
	 */
	void start(const QString & config_name) throw(backend::ConfigNotFoundException);

	void onOK();

	unsigned int getCurrentBaudRateIndex(void) const;
	QStringList getBaudRates(void);
	unsigned int getCurrentCharSizeIndex(void) const;
	QStringList getCharSizes(void);
	unsigned int getCurrentFlowControlIndex() const;
	QStringList getFlowControls(void);
	unsigned int getCurrentParityIndex(void) const;
	QStringList getParities(void);
	unsigned int getCurrentStopBitIndex(void) const;
	QStringList getStopBits(void);

private:
	unsigned int findIndex(const int & type) const;
private:
	// not the owner of the model
	backend::ConfigModel * model_;
	backend::PortConfig * current_config_;
	std::map<int, unsigned int> current_index_;
	ConfigDialog * dialog_;
};

}

#endif /* DIALOGPRESENTER_H_ */

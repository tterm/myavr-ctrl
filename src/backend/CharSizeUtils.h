/*
 * CharSizeUtils.h
 *
 *  Created on: 16.12.2011
 *      Author: tterm
 */

#ifndef CHARSIZEUTILS_H_
#define CHARSIZEUTILS_H_

#include <map>
#include <string>
#include <boost/asio.hpp>

namespace backend {

typedef boost::asio::serial_port_base::character_size CharSize;

class CharSizeComparator {
public:
	bool operator()(const CharSize & a, const CharSize & b) {
		return a.value() < b.value();
	}
};

class CharSizeUtils {
public:
	~CharSizeUtils();
	static CharSizeUtils * instance(void);
	const std::map<std::string, CharSize> &
		getStrCharsize(void) const;
	const std::map<CharSize, std::string, CharSizeComparator> &
		getCharsizeStr(void) const;
	CharSize getCharSize(const std::string & charsize) const;

private:
	CharSizeUtils();
	CharSizeUtils(const CharSizeUtils & to_copy);
	void operator=(const CharSizeUtils & to_assign);
	void init(void);

private:
	static CharSizeUtils * instance_;
	std::map<std::string, CharSize> str_charsize_;
	std::map<CharSize, std::string, CharSizeComparator> charsize_str_;

};

}

#endif /* CHARSIZEUTILS_H_ */

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
#include <SerialStreamBuf.h>

namespace TTE {

typedef LibSerial::SerialStreamBuf::CharSizeEnum CharSize;

class CharSizeUtils {
public:
	~CharSizeUtils();
	static CharSizeUtils * instance(void);
	const std::map<std::string, CharSize> &
		getStrCharsize(void) const;
	const std::map<CharSize, std::string> &
		getCharsizeStr(void) const;

private:
	CharSizeUtils();
	CharSizeUtils(const CharSizeUtils & to_copy);
	void operator=(const CharSizeUtils & to_assign);
	void init(void);

private:
	static CharSizeUtils * instance_;
	std::map<std::string, CharSize> str_charsize_;
	std::map<CharSize, std::string> charsize_str_;

};

}

#endif /* CHARSIZEUTILS_H_ */

/*
 * ModeUtils.h
 *
 *  Created on: 18.12.2011
 *      Author: tterm
 */

#ifndef MODEUTILS_H_
#define MODEUTILS_H_

#include <map>
#include <string>

namespace backend {


class ModeUtils {
public:
	static const char * request_prefix;
	static const char * response_prefix;

	~ModeUtils();
	static ModeUtils * instance(void);
	std::string getMode(const char & mode) const;
	char getMode(const std::string & mode) const;
	const std::map<std::string, char> & getModes(void) const;

private:
	ModeUtils();
	ModeUtils(const ModeUtils & );
	void operator=(const ModeUtils & );
	void init(void);

private:
	static ModeUtils * instance_;
	std::map<std::string, char> str_to_mode_;
	std::map<char, std::string> mode_to_str_;
};

}  // namespace TTE

#endif /* MODEUTILS_H_ */

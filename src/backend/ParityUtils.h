/*
 * ParityUtils.h
 *
 *  Created on: 16.12.2011
 *      Author: tterm
 */

#ifndef PARITYUTILS_H_
#define PARITYUTILS_H_

#include <map>
#include <string>
#include <SerialStreamBuf.h>

namespace TTE {

typedef LibSerial::SerialStreamBuf::ParityEnum Parity;
typedef std::map<std::string, Parity> StringParityMap;
typedef std::map<Parity, std::string> ParityStringMap;

class ParityUtils {
public:
	~ParityUtils();
	static ParityUtils * instance();
	const StringParityMap & getStrParityMap(void) const;
	const ParityStringMap & getParityStrMap(void) const;
	Parity getParity(const std::string & pari) const;

private:
	ParityUtils();
	ParityUtils(const ParityUtils & );
	void operator=(const ParityUtils &);
	void init(void);

private:
	static ParityUtils * instance_;
	StringParityMap str_par_map_;
	ParityStringMap par_str_map_;
};

}

#endif /* PARITYUTILS_H_ */

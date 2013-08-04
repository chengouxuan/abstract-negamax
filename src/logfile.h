/*
 * logfile.h
 *
 *  Created on: 2013-8-4
 *      Author: chengouxuan
 */

#ifndef LOGFILE_H_
#define LOGFILE_H_


#include <iostream>

class log_file {

	std::ostream &os;

	log_file(): os(std::cerr) {
		;
	}

public:

	static log_file &get_instance() {
		static log_file instance;
		return instance;
	}

	template <typename type>
	void log(type value) {
		os << value << "\n";
	}
};

#endif /* LOGFILE_H_ */

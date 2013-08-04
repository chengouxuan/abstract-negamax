/*
 * utilities.h
 *
 *  Created on: 2013-8-4
 *      Author: chengouxuan
 */

#ifndef UTILITIES_H_
#define UTILITIES_H_

#include <cassert>

class utilities {

public:

	template <typename type>
	static void ensure_inside_range(type lo, type hi, type val) {
		assert(lo <= val && val < hi);
	}
};

#endif /* UTILITIES_H_ */

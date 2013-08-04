/*
 * tttboarddata.h
 *
 *  Created on: 2013-8-4
 *      Author: chengouxuan
 */

#ifndef TTTBOARDDATA_H_
#define TTTBOARDDATA_H_

#include <cstring>
#include "utilities.h"

class tttboard_data {

	char data[3][3];


public:

	enum CellType {
		XType = 'X',
		OType = 'O',
		None = '.'
	};

	tttboard_data() {
		memset(data, None, sizeof(data));
	}

	void set(int r, int c, CellType type) {
		utilities::ensure_inside_range(0, 3, r);
		utilities::ensure_inside_range(0, 3, c);
		data[r][c] = type;
	}

	CellType get(int r, int c) {
		utilities::ensure_inside_range(0, 3, r);
		utilities::ensure_inside_range(0, 3, c);
		return data[r][c];
	}
};

#endif /* TTTBOARDDATA_H_ */

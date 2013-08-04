/*
 * tttevaluater.h
 *
 *  Created on: 2013-8-4
 *      Author: chengouxuan
 */

#ifndef TTTEVALUATER_H_
#define TTTEVALUATER_H_

#include "basictypes/scoretype.h"

class tttevaluater {

	enum {
		MinEvaluation = -100000,
		MaxEvaluation = -MinEvaluation,
	};

public:

	static score_type min_eval() {
		return score_type(MinEvaluation);
	}

	static score_type max_eval() {
		return score_type(MaxEvaluation);
	}


	template <typename board_info_type>
	score_type evaluate(board_info_type &board_info) {
		return min_eval();
	}
};

#endif /* TTTEVALUATER_H_ */

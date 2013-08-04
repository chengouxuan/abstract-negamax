/*
 * scoretype.h
 *
 *  Created on: 2013-8-4
 *      Author: chengouxuan
 */

#ifndef SCORETYPE_H_
#define SCORETYPE_H_

class score_type {

	int val;

public:


	score_type(int i): val(i) {}

	score_type(score_type &orig_score): val(orig_score.val) {}

	score_type &assign(score_type &new_score) {
		if (&new_score != this) {
			this->val = new_score.val;
		}
		return *this;
	}

	bool larger_than(score_type &rhs) {
		return this->val > rhs.val;
	}

	score_type negate() {
		return score_type(-this->val);
	}

private:

	void operator=();
};


#endif /* SCORETYPE_H_ */

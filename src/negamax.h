/*
 * negamax.h
 *
 *  Created on: 2013-8-4
 *      Author: chengouxuan
 */

#ifndef NEGAMAX_H_
#define NEGAMAX_H_

#define NEGAMAX_ALGORITHM_DUMP

#include <cstddef>
//#include <string>
//#include "logfile.h"

template <typename board_info_type, typename evaluater_type>
class negamax {

	board_info_type &board_info;
	evaluater_type &evaluater;
//	typedef std::string string;

public:

	negamax(board_info_type &bi, evaluater_type &e)
	: board_info(bi)
	, evaluater(e) {
		;
	}

	typedef typename evaluater_type::score_type score_type;
	typedef typename board_info_type::action_type action_type;

	void run_negamax(int depth_limit, score_type &lower_bound, score_type &upper_bound) {
		action_type action = action_type::default_action();
		run_negamax_imp(depth_limit, lower_bound, upper_bound, &action);
	}

private:

	 score_type run_negamax_imp(
			 int depth_limit,
			 score_type &lower_bound,
			 score_type &upper_bound,
			 /* the author thinks 'lower_bound' and 'upper_bound'
			  * are more clear than 'alpha' and 'beta'. */
			 action_type *action_ptr) {

#ifdef NEGAMAX_ALGORITHM_DUMP
//		 log("run_negamax_imp()");
//		 log(string("depth_limit = ").operator +=(depth_limit));
#endif

		if (depth_limit <= 0) {
			return evaluater.evaluate(board_info.board);
		}

		score_type max_score = evaluater_type::min_eval();

		board_info.prepare_iteration();

		while (board_info.has_more_iteration()) {

			board_info.next();

			score_type score = run_negamax_imp(
					depth_limit - 1,
					upper_bound.negate(),
					lower_bound.negate(),
					NULL).negate();

			if (score.larger_than(max_score)) {

				max_score.assign(score);

				if (action_ptr) {
					action_ptr->score = score;
					action_ptr->do_what = board_info.do_what;
				}
			}
		}

		board_info.reset_this_iteration();

		return max_score;
	 }

//	 template <typename type>
//	 void log(type value) {
//		 log_file::get_instance().log(value);
//	 }
};

#endif /* NEGAMAX_H_ */

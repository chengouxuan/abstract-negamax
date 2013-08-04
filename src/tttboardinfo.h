/*
 * tttboardinfo.h
 *
 *  Created on: 2013-8-4
 *      Author: chengouxuan
 */

#ifndef TTTBOARDINFO_H_
#define TTTBOARDINFO_H_

//#include <utility>
#include <vector>

template <typename board_data_type>
class tttboard_info {

	board_data_type &board_data;

//	typedef std::pair<int , int> move_type;
	typedef struct move_type {
		int r, c;
		board_data_type::Type type;
		move_type(int rr, int cc, board_data_type::Type tt)
		: r(rr)
		, c(cc)
		, type(tt) {
			;
		}
	} move_type;
	typedef std::vector<move_type> move_array_type;
	typedef std::vector<move_array_type> move_array_stack_type;

	move_array_stack_type move_array_stack;
	size_t iteration_ind;

public:

	tttboard_info(board_data_type &bd)
	: board_data(bd)
	, iteration_ind(0) {
		;
	}

	void prepare_iteration() {

		move_array_stack.push_back(move_array_type());
		move_array_type &move_array = const_cast<move_array_type &>(move_array_stack.back());

		for (int r = 0; r < 3; ++r) {
			for (int c = 0; c < 3; ++c) {
				if (board_data.get(r, c) == board_data_type::None) {
					move_array.push_back(move_type(r, c, board_data_type::OType));
					move_array.push_back(move_type(r, c, board_data_type::XType));
				}
			}
		}

		iteration_ind = 0;

		move_type current_move = move_array_stack.back()[iteration_ind];
		board_data.set(current_move.r, current_move.c, current_move.type);
	}

	void reset_this_iteration() {
		move_array_stack.pop_back();
		iteration_ind = 0;
	}

	bool has_more_iteration() {
		return iteration_ind < move_array_stack.back().size();
	}

	void next() {

		move_type last_move = move_array_stack.back()[iteration_ind++];
		board_data.set(last_move.first, last_move.second, board_data_type::None);

		move_type current_move = move_array_stack.back()[iteration_ind];
		board_data.set(current_move.r, current_move.c, current_move.type);
	}
};

#endif /* TTTBOARDINFO_H_ */

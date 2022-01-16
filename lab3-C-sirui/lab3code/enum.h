#pragma once

/*
* Aurthur: Ryan Chen
* Purpose: List return values and input values, avoid hard coding
*
*/

#ifndef ENUM_H
#define ENUM_H
#include <iostream>
using namespace std;

enum outcome {
	SUCCESS = 0,
	QUIT = 1,
	CONTINUE = 2,
	INVALID_INPUT = -1,
	INVALID_COORDINATE = -2,
	DRAW = 0,
	WINNER_X = 0,
	WINNER_Y = 0,
	WRONG_NUM_INPUT = -3,
};

enum input {
	num_argv = 2,
	comma_index = 1,
	second_comma_index = 3,
	input_size = 3,
	program_name = 0,
	main_input = 1,
};


static int usagemessage(string name) {
	cout << "This program takes in the name of game, please use the following input format:" << endl;
	cout << name << " + name of game" << endl;
	return WRONG_NUM_INPUT;
};

#endif 
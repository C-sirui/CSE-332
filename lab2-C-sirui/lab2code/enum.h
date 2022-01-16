#pragma once

#ifndef ENUM_H
#define ENUM_H
#include <string>
using namespace std;

// take in string
// return the same string but each of its char changed to smaller case
string tosmall(string up);

// all color allowed, the others are represented by invalid and treated as an error
enum struct piece_color {
	red,
	white,
	blue,
	black,
	blank,
	invalid,
};

// print usage message when input is wrong
int usage_message(char* program_name);

// followings are all enums for possible outcomes of every functions
enum common_outcome {
	SUCCESS = 0,
};

enum array_index {
	PROGRAM_NAME = 0, 
	INPUT_FILE = 1,
};

enum outcome_read_dimension {
	FAIL_GETLINE = -1,
	FAIL_GETX = -2,
	FAIL_GETY = -3,
	FAIL_NOT_DIMENSION = -10,
};

enum main_input_check {
	CORRECT_INPUT_SIZE = 2,
	FAIL_OPEN_FILE = -4,
	FAIL_INPUTSIZE = -5,
	FAIL_READ_PIECE = -11,
	FAIL_READ_DIMENSION = -12,
};

enum outcome_read_piece {
	CANNOT_EXTRACT_FIVE_VALUES = -6, 
	INVALID_COLOR = -7, 
	X_AND_Y_EXTRACTED_INVALID = -8, 
	PIECE_WELL_FORMED = -9,
};

enum outcome_print_game {
	ARRAY_SIZE_DOESNOT_MATCH = -13,
	PRINT_FAIL = -14,
};


#endif
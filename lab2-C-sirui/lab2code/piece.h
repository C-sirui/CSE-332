#pragma once

#ifndef PIECE_H
#define PIECE_H
#include <string>
#include "enum.h"
using namespace std;

// take in piece_color return string
// return a string as representation for input piece_color
string piece_colortostring(piece_color color);

// take in string return piece_color
// return a piece_color as representation of input string
piece_color stringtopiece_color(string color);

// elements necessary to print the game board
struct game_piece {
	piece_color color_;
	string piece_name_;
	string display_;

	game_piece();
	game_piece(piece_color, string, string);
};

#endif
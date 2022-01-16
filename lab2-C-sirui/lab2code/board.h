#pragma once

#ifndef BOARD_H
#define BOARD_H
using namespace std;
#include <istream>
#include <fstream>
#include <vector>
#include "piece.h"
#include "enum.h"

// read_dimensions from input file
// input: areference to an input file stream andreferences to two unsigned integers
// output: change the value of two uint parameter and return enum outcome
int read_dimension(ifstream& file, unsigned int& x, unsigned int& y);

// read_pieces from input file
// input: areference to an input file stream, areference to a vector ofgame pieces, andtwounsigned integersby value.
// output: fill in the piece vector and return enum outcomes
int read_pieces(ifstream& file, vector<game_piece>& pieces, unsigned int x, unsigned int y);

// print the game
// input: reference to a const vector of game pieces, and two unsigned integers byvalue as its parameters
// output: print game board and return enum outcomes
int print_game(const vector<game_piece>& pieces, unsigned int width, unsigned int height);

#endif
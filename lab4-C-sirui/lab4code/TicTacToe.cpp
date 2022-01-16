/*
* Aurthur: Ryan Chen, Jack Li
* Purpose: Set up functions that 1) cout the game board
*								 2) check winner
*								 3) check draw
*								 4) prompt coordinat input
*								 5) switch between player
*								 6) play the game repeatedly until draw or win
*
*/

#include<iostream>
#include "TicTacToe.h"
#include "pieces.h"
#include <sstream>
#include <istream>
using namespace std;


// cout the game board
// formately print the gameboard
ostream& operator<<(ostream& out, TicTacToe const& game) {
	for (int i = game.height; i >= 0; --i) {
		string line;
		line += to_string(i);
		line += " ";
		for (unsigned int j = 0; j <= game.width; ++j){
			line += game.pieces[i * (game.width + 1) + j].player;
			line += " ";
			
		}
		cout << line << endl;
	}

	string last_line;
	last_line += "  ";
	for (unsigned int j = 0; j <= game.width; ++j) {
		last_line += to_string(j);
		last_line += " ";
	}
	cout << last_line << endl;
	return out;
}

//  wrap the operator<<(ostream& out, Gomoku const& game), to make print as easy as print()
void TicTacToe::print() {
	cout << *this << endl;
}


bool TicTacToe::done(int winNum)
{
	int count = 1;
	// check hrizontal win
	for (int i = height; i >= 0; --i) {
		for (unsigned int j = 0; j <= width; ++j) {
			count = 1;
			// if the position has no pieces, skip
			if (pieces[i * (width + 1) + j].player == ' ') {
				continue;
			}
			else {
				// if pieces not equal, break
				for (int k = 1; k >= 0; ++k) {
					if (pieces[i * (width + 1) + j].player != pieces[i * (width + 1) + j + k].player) { // if pieces not equal, break
						break;
					}
					// if pieces are equal, count++
					else {
						count++;
						// when count = winNum, return who is winning
						if (count >= winNum) {
							if (pieces[i * (width + 1) + j].player == 'X') {
								X_WON = true;
								return X_WON;
							}
							else {
								O_WON = true;
								return O_WON;
							}
						}
					}
				}
			}
		}
	}

	count = 1;
	// check vertical win
	for (int i = height; i >= 0; --i) {
		for (unsigned int j = 0; j <= width; ++j) {
			count = 1;
			if (pieces[i * (width + 1) + j].player == ' ') {
				continue;
			}
			else {
				for (int k = 1; k >= 0; ++k) {
					if (pieces[i * (width + 1) + j].player != pieces[i * (width + 1) + j + k * (width + 1)].player) { // if pieces not equal, break
						break;
					}
					else {
						count++;
						if (count >= winNum) {
							if (pieces[i * (width + 1) + j].player == 'X') {
								X_WON = true;
								return X_WON;
							}
							else {
								O_WON = true;
								return O_WON;
							}
						}
					}
				}
			}
		}
	}

	count = 1;
	// check left diagonal win
	for (int i = height; i >= 0; --i) {
		for (unsigned int j = 0; j <= width; ++j) {
			count = 1;
			if (pieces[i * (width + 1) + j].player == ' ') {
				continue;
			}
			else {
				for (int k = 1; k >= 0; ++k) {
					if (pieces[i * (width + 1) + j].player != pieces[i * (width + 1) + j + k * (width + 1) + k].player) { // if pieces not equal, break
						break;
					}
					else {
						count++;
						if (count >= winNum) {
							if (pieces[i * (width + 1) + j].player == 'X') {
								X_WON = true;
								return X_WON;
							}
							else {
								O_WON = true;
								return O_WON;
							}
						}
					}
				}
			}
		}
	}

	count = 1;
	// pieces[i * (width + 1) + j].player == pieces[i * (width + 1) + j + 2 * (width + 1) - 2].player
	// check right diagonal win
	for (unsigned int i = 0; i <= height; ++i) {
		for (unsigned int j = 0; j <= width; ++j) {
			count = 1;
			if (pieces[i * (width + 1) + j].player == ' ') {
				continue;
			}
			else {
				for (int k = 1; k >= 0; ++k) {
					if (pieces[i * (width + 1) + j].player != pieces[i * (width + 1) + j + k * (width + 1) - k].player) { // if pieces not equal, break
						break;
					}
					else {
						count++;
						if (count >= winNum) {
							if (pieces[i * (width + 1) + j].player == 'X') {
								X_WON = true;
								return X_WON;
							}
							else {
								O_WON = true;
								return O_WON;
							}
						}
					}
				}
			}
		}
	}
	return false;
}



// check draw
// input: none
// output: check remaining moves, if it is 0, then it is a draw, return false;
bool TicTacToe::draw() {
	if (remaining_moves == 0) {
		return false;
	}
	return true;
}


// 5) switch between player
// check if the coordinate from prompt is empty and place it in pieces vector 
// then print the board and switch player
int TicTacToe::turn() {
	unsigned int row;
	unsigned int column;
	int ans = prompt(row, column);

	// if returned value ans from prompt is INVALID_INPUT or INVALID_COORDINATE, re-prompt
	while (ans != SUCCESS && ans != QUIT) {
		ans = prompt(row, column);
	}

	// condition: quit
	if (ans == QUIT) {
		return QUIT;
	}

	// not quit, not invalid input/cooridnate, than it's okey to put it in pieces vector
	// check if position is alreadt taken, if so, re prompt
	unsigned int index = row * (width + 1) + column;
	while (pieces[index].player != ' ') {
		cout << " " << endl;
		cout << "Position already taken, please re-enter" << endl;
		ans = prompt(row, column);
		if (ans == QUIT) {
			return QUIT;
		}
		index = row * (width + 1) + column;
	}

	// the put the piece in vector
	piece temp = piece(piece::which_player(player), column, row);
	pieces[index] = temp;
	print();

	// one less remaining move, switch player
	--remaining_moves;
	player = !player;
	return SUCCESS;

}

// default initialization, board of 3x3 size
TicTacToe::TicTacToe()
{
	set_width(4);
	set_height(4);
	cout << "Initialize TicTacToe Game" << endl;
}



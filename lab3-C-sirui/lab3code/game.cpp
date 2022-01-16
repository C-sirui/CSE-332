/*
* Aurthur: Ryan Chen
* Purpose: Set up functions that 1) cout the game board
*								 2) check winner
*								 3) check draw
*								 4) prompt coordinat input
*								 5) switch between player
*								 6) play the game repeatedly until draw or win
*
*/

#include<iostream>
#include "game.h"
#include "enum.h"
#include "pieces.h"
#include <sstream>
#include <istream>
using namespace std;

// 1) cout the game board
ostream& operator<<(ostream& out, game const& game) {
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

// 2) check winner
// return true if X or 0 has a consecutive three
bool game::done() {
	// check hrizontal win
	for (int i = height; i >= 0; --i) {
		for (unsigned int j = 0; j <= width; ++j) {
			if (pieces[i * (width + 1) + j].player != ' ' &&
				pieces[i * (width + 1) + j].player == pieces[i * (width + 1) + j + 1].player &&
				pieces[i * (width + 1) + j].player == pieces[i * (width + 1) + j - 1].player) {
				if (pieces[i * (width + 1) + j].player == 'X') {
					X_WON = true;
					return X_WON;
				}
				if (pieces[i * (width + 1) + j].player == 'Y') {
					Y_WON = true;
					return Y_WON;
				}
				
			}
		}
	}
	
	// check vertical win
	for (int i = height; i >= 0; --i) {
		for (unsigned int j = 0; j <= width; ++j) {
			if (pieces[i * (width + 1) + j].player != ' ' &&
				pieces[i * (width + 1) + j].player == pieces[i * (width + 1) + j + (width + 1)].player &&
				pieces[i * (width + 1) + j].player == pieces[i * (width + 1) + j - (width + 1)].player) {
				if (pieces[i * (width + 1) + j].player == 'X') {
					X_WON = true;
					return X_WON;
				}
				if (pieces[i * (width + 1) + j].player == 'Y') {
					Y_WON = true;
					return Y_WON;
				}

			}
		}
	}

	// check left diagonal win
	for (int i = height; i >= 0; --i) {
		for (unsigned int j = 0; j <= width; ++j) {
			if (pieces[i * (width + 1) + j].player != ' ' &&
				pieces[i * (width + 1) + j].player == pieces[i * (width + 1) + j + (width + 1) - 1].player &&
				pieces[i * (width + 1) + j].player == pieces[i * (width + 1) + j - (width + 1) + 1].player) {
				if (pieces[i * (width + 1) + j].player == 'X') {
					X_WON = true;
					return X_WON;
				}
				if (pieces[i * (width + 1) + j].player == 'Y') {
					Y_WON = true;
					return Y_WON;
				}

			}
		}
	}
	// check right diagonal win
	for (unsigned int i = 0; i <= height; ++i) {
		for (unsigned int j = 0; j <= width; ++j) {
			if (pieces[i * (width + 1) + j].player != ' ' &&
				pieces[i * (width + 1) + j].player == pieces[i * (width + 1) + j + (width + 1) + 1 ].player &&
				pieces[i * (width + 1) + j].player == pieces[i * (width + 1) + j - (width + 1) - 1].player) {
				if (pieces[i * (width + 1) + j].player == 'X') {
					X_WON = true;
					return X_WON;
				}
				if (pieces[i * (width + 1) + j].player == 'Y') {
					Y_WON = true;
					return Y_WON;
				}

			}
		}
	}
	return false;
}

// 3) check draw
// return false if done() returns three
bool game::draw() {
	if (done() || remaining_moves == 0) {
		return false;
	}
	return true;
}



// 4) prompt coordinat input
// prompt player to put in a a correct coordinate of form (unsigned int, insigned int)
int game::prompt(unsigned int& row, unsigned int& column) {
	string input;
	cout << "enter one of the two from command line: " << endl;
	cout << "1) 'quit' to stop playing. 2) a correct coordinate of form (unsigned int, insigned int) to place your piece." << endl;
	cout.clear();
	getline(cin, input);

	if (input == "quit") {
		cout << "QUIT GAME." << endl;
		return QUIT;
	}
	else if (input.size() != input_size) {
		cout << " "<< endl;
		cout << "1INVALID_INPUT, please re-enter or enter 'quit'." << endl;
		prompt(row, column);
		return INVALID_INPUT;
	}
	else if (input[comma_index] == ',') {
		input[comma_index] = ' ';
		input.insert(second_comma_index, " ");
		istringstream coordinate(input);

		// check if input x,x is valid
		if (coordinate >> column >> row){
	
			// check if row and column in valid range
			if (row > (height - 1) || column > (width - 1) || row == 0 || column == 0) {
				cout << " " << endl;
				cout << "INVALID_COORDINATE, please re-enter or enter 'quit'. (You entered coordiante out of range)" << endl;
				prompt(row, column);
				return INVALID_COORDINATE;
			}
			return SUCCESS;
		}
		else {
			cout << " " << endl;
			cout << "2INVALID_INPUT, please re-enter or enter 'quit'." << endl;
			prompt(row, column);
			return INVALID_INPUT;
		}
	}
	else {
		cout << " " << endl;
		cout << "3INVALID_INPUT, please re-enter or enter 'quit'." << endl;
		prompt(row, column);
		return INVALID_INPUT;
	}

}


// 5) switch between player
// check if the coordinate from prompt is empty and place it in pieces vector 
// then print the board and switch player
int game::turn() {
	unsigned int row;
	unsigned int column;
	if (prompt(row, column) != QUIT) {

		// check if position is alreadt taken
		unsigned int index = row * (width+1) + column;
		while (pieces[index].player != ' ' ) {
			cout << " " << endl;
			cout << "Position already taken, please re-enter" << endl;
			if (prompt(row, column) == QUIT) {
				return QUIT;
			}
			index = row * (width+1)+column;
		}

		// place piece at correct index in pieces vector and print board
		piece temp = piece(piece::which_player(player), column, row);
		pieces[index] = temp;
		cout << *this << endl;

		// one less remaining move, switch player
		--remaining_moves;
		player = !player;
		return SUCCESS;
	}

	return QUIT;
}


// 6) play the game repeatedly until draw or win
// repeatly call prompt() done() and draw() to make the game
int game::play(){
	cout << *this << endl;
	cout << "player X first" << endl;
	while (true) {
		if (turn() == QUIT) {
			cout << "Turn played: " << (width - 1) * (height - 1) - remaining_moves << endl;
			cout << "QUIT, No Winner" << endl;
			return QUIT;
		}
		if (done()) {
			cout << "Turn played: " << (width - 1) * (height - 1) - remaining_moves << endl;
			if (X_WON) {
				cout << "X is winner" << endl;
				return WINNER_X;
			}
			else {
				cout << "Y is winner" << endl;
				return WINNER_Y;
			}
		}
		if (draw() == false) {
			cout << "Turn played: " << (width - 1) * (height - 1) - remaining_moves << endl;
			cout << "No winner, it is a DRAW." << endl;
			return DRAW;
		}
		cout << "player " << piece::which_player(player) << " next" << endl;
	}

}



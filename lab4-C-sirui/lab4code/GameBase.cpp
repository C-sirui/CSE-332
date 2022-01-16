/*
* Aurthur: Ryan Chen, Jack Li
* Purpose: GameBase.cpp, define functions in GameBase, define none virtual functions, 
*           	virtual function definition difinition are taken care in inherited classes
*					
*/
#include<iostream>
#include "TicTacToe.h"
#include "Gomoku.h"
#include "GameBase.h"
#include "pieces.h"
#include <sstream>
#include <istream>
using namespace std;


// prompt coordinat input
// prompt player to put in a a correct coordinate of form (unsigned int, insigned int)
// input: row and column passed by reference
// output: SUCESS OR INVALID INPUT OR INVALID COORDINATE
int GameBase::prompt(unsigned int& row, unsigned int& column) {
	string input;
	cout << "enter one of the two from command line: " << endl;
	cout << "1) 'quit' to stop playing. 2) a correct coordinate of form (unsigned int, insigned int) to place your piece." << endl;
	cout.clear();

	// get input from command line 
	getline(cin, input);

	// check if input is quit, if so, quit
	if (input == "quit") {
		cout << "QUIT GAME." << endl;
		return (int)QUIT;
	}

	// check if input has correct length
	else if (input.size() < minimum_input_size || input.size() > maximum_input_size) {
		cout << " " << endl;
		cout << "1INVALID_INPUT, please re-enter or enter 'quit'." << endl;
		return INVALID_INPUT;
	}

	//else if (input[comma_index] == ',' || input[comma_index + 1] == ',') {		
	//	char flag = ',';
	//	int position = 0;
	//	int i = 1;
	//	while ((position = input.find(flag, position)) != string::npos)
	//	{
	//		input[position] = ' ';
	//		position++;
	//		i++;
	//	}

	// parse input and wrap it by istringstream
	else if (input[comma_index] == ',' || input[comma_index + 1] == ',') {
		int a = input.find(',');
		input[a] = ' ';
		istringstream coordinate(input);

		// check if input is a valid coordinate
		if (coordinate >> column >> row) {
			
			// check if row and column in valid range
			if (row > (height - 1) || column > (width - 1) || row == 0 || column == 0) {
				cout << " " << endl;
				cout << "INVALID_COORDINATE, please re-enter or enter 'quit'. (You entered coordiante out of range)" << endl;
				return INVALID_COORDINATE;
			}
			return (int)SUCCESS;
		}
		else {
			cout << " " << endl;
			cout << "2INVALID_INPUT, please re-enter or enter 'quit'." << endl;
			return INVALID_INPUT;
		}
	}
	else {
		cout << " " << endl;
		cout << "3INVALID_INPUT, please re-enter or enter 'quit'." << endl;
		return INVALID_INPUT;
	}

}

// get argument from command line and decide to create a type of game
// input: command line input
// output: if commmand line input is Gomoku, return Gomoku object by pointer
//         if						 TicTacToe, return TicTacToe object by pointer
GameBase* GameBase::check_argument(int argc, char* argv[]) {
	if (argc ==  num_argv && strcmp(argv[main_input], "TicTacToe") == 0) {
		TicTacToe* game = new TicTacToe();
		return game;
	}
	else if (argc == num_argv && strcmp(argv[main_input], "Gomoku") == 0) {
		Gomoku* game = new Gomoku();
		return game;
	}
}	

// play the game repeatedly until draw or win
// repeatly call prompt() done() and draw() to make the game
int GameBase::play(int numWin) {
	print();
	cout << "player X(Black) first" << endl;
	while (true) {
		if (turn() == QUIT) {
			cout << "Turn played: " << (width - 1) * (height - 1) - remaining_moves << endl;
			cout << "QUIT, No Winner" << endl;
			return QUIT;
		}
		else if (done(numWin)) {
			cout << "Turn played: " << (width - 1) * (height - 1) - remaining_moves << endl;
			if (O_WON) {
				cout << "O(White) is winner" << endl;
				return WINNER_X;
			}
			else {
				cout << "X(Black) is winner" << endl;
				return WINNER_Y;
			}
		}
		else if (draw() == false) {
			cout << "Turn played: " << (width - 1) * (height - 1) - remaining_moves << endl;
			cout << "No winner, it is a DRAW." << endl;
			return DRAW;
		}
	}

}
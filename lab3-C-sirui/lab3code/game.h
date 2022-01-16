#pragma once
/*
* Aurthur: Ryan Chen
* Purpose: header file for game.cpp
*          Set up functions that 1) cout the game board
*								 2) check winner
*								 3) check draw
*								 4) prompt coordinat input
*								 5) switch between player
*								 6) play the game repeatedly until draw or win
*
*/

#ifndef GAME_H
#define GAME_H


#include<iostream>
#include<sstream>
#include<vector>
#include"pieces.h"
#include"enum.h"
using namespace std;

class game {
private:
	unsigned int width;
	unsigned int height;
	unsigned int remaining_moves;
	bool player = true; // player X fisrt
	bool X_WON = false;
	bool Y_WON = false;
	vector<piece> pieces;

public:
	friend ostream& operator<< (ostream& out, game const& game);
	bool done();
	bool draw();
	int prompt(unsigned int& row, unsigned int& column);
	int turn();
	int play();


	// default constructor, need to adjust since default values of width and height are smaller than 4
	game(): width(1), height(1), remaining_moves(0), pieces(vector<piece>(0, piece(' ', 0, 0))) {
		cout << "A GAME IS CREATED with " << width-1 << "x" << height-1 << " game board" << endl;
	}
	~game() {
		cout << "GAME DESTROYED" << endl;
	}
	static int usage_message(char* argv[]);

	// reset game board for more fun
	void set_width(unsigned int x) {
		width = x;
		remaining_moves = (height - 1) * (width - 1);
		pieces = vector<piece>((width+1)*(height+1), piece(' ', 0, 0));
		cout << "Gameboard changed to " << width - 1 << "x" << height - 1 << endl;
	}
	void set_height(unsigned int x) {
		height = x;
		remaining_moves = (height - 1) * (width - 1);
		pieces = vector<piece>((width + 1) * (height + 1), piece(' ', 0, 0));
		cout << "Gameboard changed to " << width - 1 << "x" << height - 1 << endl;
	}
};

#endif // !game.h

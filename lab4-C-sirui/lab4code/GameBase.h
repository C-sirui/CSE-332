#pragma once
/*
* Aurthur: Ryan Chen, Jack Li
* Purpose: header file for game.cpp
*          Set up functions that 1) virtual print(): cout the game board
*								 2) virtual done(int winNum): check winner 
*								 3) virtual draw(): check draw 
*								 4) prompt(unsigned int& row, unsigned int& column): prompt coordinat input
*								 5) virtual turn(): switch between player 
*								 6) play(int winNum): play the game repeatedly until draw or win
* 
*		   Enum outcome: possible outcomes from methods, like SUCCESS and INVALID_INPUT
* 
*		   usage_message(): explain how use the programm
* 
*	
*
*/

#ifndef GAMEBASE_H
#define GAMEBASE_H


#include<iostream>
#include<sstream>
#include<vector>
#include"pieces.h"
using namespace std;

class GameBase {
	
protected:
	unsigned int width;
	unsigned int height;
	unsigned int remaining_moves;
	bool player = true; // player X fisrt
	bool O_WON = false;
	bool X_WON = false;
	vector<piece> pieces;
	vector<piece> piece_for_Gomoku;

public:
	friend ostream& operator<< (ostream& out, const GameBase& game);
	virtual void print() = 0;
	virtual bool done(int winNum) = 0;
	virtual bool draw() = 0;
	int prompt(unsigned int& row, unsigned int& column);
	virtual int turn() = 0;
	int play(int numWin);

	// default initialization of game board 0x0
	GameBase(): width(1), height(1), remaining_moves(0), pieces(vector<piece>(0, piece(' ', 0, 0))) {
		cout << "A GAME IS CREATED with " << width - 1 << "x" << height - 1 << " game board" << endl;
	}

	static GameBase* check_argument(int, char* []);

	// reset game board for Gomoku
	void set_width(unsigned int x) {
		width = x;
		remaining_moves = (height - 1) * (width - 1);
		pieces = vector<piece>((width + 1) * (height + 1), piece(' ', 0, 0));
		cout << "Gameboard changed to " << width - 1 << "x" << height - 1 << endl;
	}
	void set_height(unsigned int x) {
		height = x;
		remaining_moves = (height - 1) * (width - 1);
		pieces = vector<piece>((width + 1) * (height + 1), piece(' ', 0, 0));
		cout << "Gameboard changed to " << width - 1 << "x" << height - 1 << endl;
	}
};


// outcome value and usage message
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
	UNKOWN_GAME_TYPE = -99,
	INVALID_BOARD_SIZE = -11,
	INVALID_WINNING_SIZE = -22,
};

// avoid hard coding
enum input {
	num_argv = 2,
	comma_index = 1,
	second_comma_index = 3,
	program_name = 0,
	main_input = 1,
	minimum_input_size = 3,
	maximum_input_size = 5,

};

// teach client to use command line input
static int usagemessage(string name) {
	cout << "This program takes in the name of game, please use the following input format:" << endl;
	cout << name << " + name of game" << endl;
	cout << "Games avaliable are: Gomoku (or) TicTacToe" << endl;
	cout << "You can define Gomoku's board size and winning size" << endl;
	cout << "To create Gomoku of board size 10: Gomoku 10" << endl;
	cout << "To create Gomoku of board size 10 and winning size 5: Gomoku 10 5" << endl;
	return INVALID_INPUT;
};

#endif // !game.h


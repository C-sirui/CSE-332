#pragma once
/*
* Aurthur: Ryan Chen
* Purpose: header file for TicTacToe.cpp, inherite function from GameBase, declare virtual functions,
*				
*/

#ifndef GAME_H
#define GAME_H


#include<iostream>
#include<sstream>
#include<vector>
#include"pieces.h"
#include"GameBase.h"
using namespace std;

class TicTacToe: public GameBase {

public:
	friend ostream& operator<< (ostream& out, const TicTacToe& game);
	virtual void print();
	virtual bool done(int winNum);
	virtual bool draw();
	virtual int turn();
	int play();

	// default constructor, need to adjust since default values of width and height are smaller than 4
	TicTacToe();
	virtual ~TicTacToe() {
		cout << "GAME DESTROYED" << endl;
	}
	

};

#endif // !game.h

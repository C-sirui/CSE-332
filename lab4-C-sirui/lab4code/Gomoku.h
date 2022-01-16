/*
* Aurthur: Ryan Chen, Jack Li
* Purpose: header file for Gomoku.cpp, inherite function from GameBase, declare virtual functions,
*				
*         
*	
*
*/

//#pragma once
#include<iostream>
#include<sstream>
#include<vector>
#include"pieces.h"
#include"GameBase.h"
using namespace std;

class Gomoku : public GameBase {

public:
	friend ostream& operator<< (ostream& out, const Gomoku& game);
	virtual void print();
	bool done(int winNum);
	virtual bool draw();
	virtual int turn();
	int play();
	// default constructor, need to adjust since default values of width and height are smaller than 4
	Gomoku();
	Gomoku(int board);
	virtual ~Gomoku() {
		cout << "GAME DESTROYED" << endl;
	}
};


#pragma once
/*
* Aurthur: Ryan Chen
* Purpose: Properties of pieces
*
*/

struct piece {
	char player;
	unsigned int x;
	unsigned int y;

	// constructors
	piece();
	piece(char a, unsigned int b, unsigned int c) {
		player = a;
		x = b;
		y = c;
	}

	// decide player, input is boolean player from game.h
	static char which_player(bool x) {
		if (x) {
			return 'X';
		}
		else {
			return 'O';
		}
	}
};


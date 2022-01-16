#pragma once
/*
* Aurthur: Ryan Chen, Jack Li
* Purpose: Properties of pieces, 'B' = 'X' and 'W' = 'O'
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

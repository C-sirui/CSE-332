Ryan Chen
Lab3 TicTacToe

SUMMARY: 
	a tictactoe game requesting command line input of coordinate, switching player each turn
	to run it: program name + TicTacToe
	it works on different kinds of board as long as board's length = width


DETAILS:
pieces.h: include details of pieces 1) player it belongs to
									2) column and row coordinate

game.h: header file for essential game functions

game.cpp: 1) cout the game board
		  2) check winner
		  3) check draw
	      4) prompt coordinat input
		  5) switch between player
		  6) play the game repeatedly until draw or win

enum.h: 1) usage function
		2) input's int representations (avoid hard coding)
		2) values of return types(listed below)
			SUCCESS = 0,
			DRAW = 0,
			WINNER_X = 0,
			WINNER_Y = 0,
			QUIT = 1,
			INVALID_INPUT = -1,
			INVALID_COORDINATE = -2,
			WRONG_NUM_INPUT = -3,

ERRORs:
1)	after each invalid input coordinate that colid with existing piece on board, quit function doesn't works.
	fixed by adding a missing return.
2)  vector<pieces> out of range
	fixed by initalizing it again after changing board size

TEST CASEs:
1) blank:
	1INVALID_INPUT, please re-enter or enter 'quit'.

2) "1,":
	1INVALID_INPUT, please re-enter or enter 'quit'.

3) "1,1":
	player O next

4) "1,1"
   "1,1":
	Position already taken, please re-enter

5) "1,1"
   "quit":
	QUIT GAME.
	Turn played: 1
	No winner
	GAME DESTROYED

6) draw cases:
	Turn played: 9
	No winner, it is a DRAW.
	GAME DESTROYED

7) "1,     1"
	1INVALID_INPUT, please re-enter or enter 'quit'.

8) winning cases:
	display is all correct.
	
	
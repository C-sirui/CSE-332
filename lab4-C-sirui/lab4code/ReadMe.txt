ReadMe file
11/19/21
Xinyu(Jack) Li & Sirui(Ryan) Chen
l.xinyujack@wustl.edu
c.sirui@wustl.edu
CSE332 Lab4

Difficulties:

1. With the Ryan's code from lab 3, we went through the instruction quickly our code didn't have errors except 
   some small ones like missing a bracket.
2. However, we ran the program, our Gomoku game pieces didn't align with the columns of the game board.
3. This took us some time to solve, but we fixed it afterall.
4. Another issue was that since we cannot let play() call ostream directly, we had to modify the ostream in
   base class so that for Gomoku game, whenever the piece is X or O, print it as B or W. So we could still
   use X and O in the program, but what you see on the game board is B and W. Also, when the program prints out
   the player's name, we put X(Black) or Y(White) so if you are playing TicTacToe, you will know it's X or Y,
   and if you playing Gomoku, you will know it's B or W. I confirmed this action with the TA and this is ok.
5. Since we are using Ryan's code from lab3, the majority of his code is unchanged and has been examined by 
   the previous grader. The only part that was taken points off was not enough comments, which we have fixed 
   for this lab. The output for most of test cases remained unchanged from the last lab, and they were approved
   by the previous grader.
6. For Gomoku gameboard, we still print out 0 and the 20, which cannot be inserted with anything. We chekced with
   the TA and this is ok.

Testings:
1. When type in "quit" during the game:

	<<<<<TicTacToe>>>>>

 	4
	 3     X
	 2   X   O
	 1
	 0
	   0 1 2 3 4

	 enter one of the two from command line:
 	1) 'quit' to stop playing. 2) a correct coordinate of form (unsigned int, insigned int) to place your piece.
 	quit
 	QUIT GAME.
 	Turn played: 3
	 QUIT, No Winner

 	<<<<<Gomoku>>>>>

 	20
 	19
 	18
 	17
 	16
	 15
 	14
	 13
 	12
 	11
 	10
	 9
	 8
	 7
 	6
 	5
	 4
	 3
	 2
	 1
	 0
 	X 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20

 	player X(Black) first
 	enter one of the two from command line:
 	1) 'quit' to stop playing. 2) a correct coordinate of form (unsigned int, insigned int) to place your piece.
	 quit
	 QUIT GAME.
 	Turn played: 0
 	QUIT, No Winner


2. For badly formed input string, since it's up to me to decide how it will go, we ask the user to input the 
   coordinate in the format of "x,y". If the comma is missing or misplaced, or there are spaces before or 
   between three characters, the error message will print out ask the user to re-enter a valid coordinate:

 	<Same result for both games>

 	player X(Black) first
 	enter one of the two from command line:
 	1) 'quit' to stop playing. 2) a correct coordinate of form (unsigned int, insigned int) to place your piece.
 	13

	3INVALID_INPUT, please re-enter or enter 'quit'.
	enter one of the two from command line:
	1) 'quit' to stop playing. 2) a correct coordinate of form (unsigned int, insigned int) to place your piece.
 	1 3
 
	3INVALID_INPUT, please re-enter or enter 'quit'.
 	enter one of the two from command line:
 	1) 'quit' to stop playing. 2) a correct coordinate of form (unsigned int, insigned int) to place your piece.
 	1  3

	3INVALID_INPUT, please re-enter or enter 'quit'.
 	enter one of the two from command line:
 	1) 'quit' to stop playing. 2) a correct coordinate of form (unsigned int, insigned int) to place your piece.
 	1,3

 	1INVALID_INPUT, please re-enter or enter 'quit'.
 	enter one of the two from command line:
 	1) 'quit' to stop playing. 2) a correct coordinate of form (unsigned int, insigned int) to place your piece.
 	1,

 	2INVALID_INPUT, please re-enter or enter 'quit'.
 	enter one of the two from command line:
 	1) 'quit' to stop playing. 2) a correct coordinate of form (unsigned int, insigned int) to place your piece.
 	1.3

 	3INVALID_INPUT, please re-enter or enter 'quit'.
 	enter one of the two from command line:
 	1) 'quit' to stop playing. 2) a correct coordinate of form (unsigned int, insigned int) to place your piece.
 	1,3fhuqofeuqf

 	1INVALID_INPUT, please re-enter or enter 'quit'.
 	enter one of the two from command line:
 	1) 'quit' to stop playing. 2) a correct coordinate of form (unsigned int, insigned int) to place your piece.
 	a,b

 	2INVALID_INPUT, please re-enter or enter 'quit'.
 	enter one of the two from command line:
 	1) 'quit' to stop playing. 2) a correct coordinate of form (unsigned int, insigned int) to place your piece.


3. However, the program will only get the first three inputs on the terminal line, so it doesn't matter what
   you enter after these three inputs, the program won't read them:
	
	<<<<<TicTacToe>>>>

	1 3,1
	1 asd 3
	4
	3   X
	2
	1
	0
	  0 1 2 3 4

	enter one of the two from command line:
	1) 'quit' to stop playing. 2) a correct coordinate of form (unsigned int, insigned int) to place your piece.

	<<<<<Gomoku>>>>>

 	1 3,1
	1 asd 3
	20
	19
	18
	17
	16
	15
	14
	13
	12
	11
	10
	9
	8
	7
	6
	5
	4
	3   B
	2
	1
	0
	X 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20

	enter one of the two from command line:
	1) 'quit' to stop playing. 2) a correct coordinate of form (unsigned int, insigned int) to place your piece.


4. If the user inputs nothing, the error message will print and prompt the user to input a valid coordinate:

 	<<<<<Same result for both games>>>>>

	player X(Black) first
	enter one of the two from command line:
	1) 'quit' to stop playing. 2) a correct coordinate of form (unsigned int, insigned int) to place your piece.


	1INVALID_INPUT, please re-enter or enter 'quit'.
	enter one of the two from command line:
	1) 'quit' to stop playing. 2) a correct coordinate of form (unsigned int, insigned int) to place your piece.


5. If the input is out of bound, the error message will print out and ask the user to input again:

 	<<<<<TicTacToe>>>>>

 	4
 	3   O X
 	2   X
 	1
 	0
 	  0 1 2 3 4

 	enter one of the two from command line:
 	1) 'quit' to stop playing. 2) a correct coordinate of form (unsigned int, insigned int) to place your piece.
 	2,4

 	INVALID_COORDINATE, please re-enter or enter 'quit'. (You entered coordiante out of range)
 	enter one of the two from command line:
 	1) 'quit' to stop playing. 2) a correct coordinate of form (unsigned int, insigned int) to place your piece.

 	<<<<<Gomoku>>>>>

 	20
 	19
 	18
 	17
 	16
 	15
 	14
 	13
 	12
 	11
 	10
 	9
 	8
 	7
 	6
 	5
 	4
 	3
 	2
 	1
 	0
 	X 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20

 	player X(Black) first
 	enter one of the two from command line:
 	1) 'quit' to stop playing. 2) a correct coordinate of form (unsigned int, insigned int) to place your piece.
 	20,20

 	INVALID_COORDINATE, please re-enter or enter 'quit'. (You entered coordiante out of range)
 	enter one of the two from command line:
 	1) 'quit' to stop playing. 2) a correct coordinate of form (unsigned int, insigned int) to place your piece.


6. Turn keeps switching:
 
 	<<<<<TicTacToe>>>>>
 	4
 	3
 	2
 	1
 	0
 	  0 1 2 3 4

 	player X(Black) first
 	enter one of the two from command line:
 	1) 'quit' to stop playing. 2) a correct coordinate of form (unsigned int, insigned int) to place your piece.
 	1,1

 	4
 	3
 	2
 	1   X
 	0
 	  0 1 2 3 4

 	enter one of the two from command line:
 	1) 'quit' to stop playing. 2) a correct coordinate of form (unsigned int, insigned int) to place your piece.
 	2,3

 	4
 	3     O
 	2
 	1   X
 	0
	  0 1 2 3 4

 	enter one of the two from command line:
 	1) 'quit' to stop playing. 2) a correct coordinate of form (unsigned int, insigned int) to place your piece.
 	2,1

 	4
 	3     O
 	2
 	1   X X
 	0
  	  0 1 2 3 4

 	enter one of the two from command line:
 	1) 'quit' to stop playing. 2) a correct coordinate of form (unsigned int, insigned int) to place your piece.

 <<<<<Gomoku>>>>>

 20
 19
 18
 17
 16
 15
 14
 13
 12
 11
 10
 9
 8
 7
 6
 5
 4
 3
 2   B
 1
 0
 X 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20

 enter one of the two from command line:
 1) 'quit' to stop playing. 2) a correct coordinate of form (unsigned int, insigned int) to place your piece.
 3,4

 20
 19
 18
 17
 16
 15
 14
 13
 12
 11
 10
 9
 8
 7
 6
 5
 4       W
 3
 2   B
 1
 0
 X 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20

 enter one of the two from command line:
 1) 'quit' to stop playing. 2) a correct coordinate of form (unsigned int, insigned int) to place your piece.
 19,3

 20
 19
 18
 17
 16
 15
 14
 13
 12
 11
 10
 9
 8
 7
 6
 5
 4       W
 3                                                B
 2   B
 1
 0
 X 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20

 enter one of the two from command line:
 1) 'quit' to stop playing. 2) a correct coordinate of form (unsigned int, insigned int) to place your piece.
 5,10

 20
 19
 18
 17
 16
 15
 14
 13
 12
 11
 10          W
 9
 8
 7
 6
 5
 4       W
 3                                                B
 2   B
 1
 0
 X 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20

 enter one of the two from command line:
 1) 'quit' to stop playing. 2) a correct coordinate of form (unsigned int, insigned int) to place your piece.


7. If the coordinate is already taken, it will print out:

 <<<<<TicTacToe>>>>>
 4
 3     O
 2
 1   X X
 0
   0 1 2 3 4

 enter one of the two from command line:
 1) 'quit' to stop playing. 2) a correct coordinate of form (unsigned int, insigned int) to place your piece.
 1,1

 Position already taken, please re-enter
 enter one of the two from command line:
 1) 'quit' to stop playing. 2) a correct coordinate of form (unsigned int, insigned int) to place your piece.

 <<<<<Gomoku>>>>>

 20
 19
 18
 17
 16
 15
 14
 13
 12
 11
 10          W
 9
 8
 7
 6
 5
 4       W
 3                                                B
 2   B
 1
 0
 X 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20

 enter one of the two from command line:
 1) 'quit' to stop playing. 2) a correct coordinate of form (unsigned int, insigned int) to place your piece.
 1,2

 Position already taken, please re-enter
 enter one of the two from command line:
 1) 'quit' to stop playing. 2) a correct coordinate of form (unsigned int, insigned int) to place your piece.


8. When a winner appears, print out the winner and the moves that player has played(for this one, you will refer to
   X when it's TicTacToe game, and (Black) when it's Gomoku game:

 <<<<<TicTacToe>>>>>
 4
 3     O
 2   O
 1   X X X
 0
   0 1 2 3 4

 Turn played: 5
 X(Black) is winner

 <<<<<GomoKu>>>>>

 20
 19
 18
 17
 16
 15
 14
 13
 12
 11
 10          W
 9
 8
 7
 6
 5
 4     W W
 3   W W                                          B
 2   B B B B B
 1
 0
 X 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20

 Turn played: 11
 X(Black) is winner


9. When a draw appears, print out "Draw", the number of turns played, and the moves remained:

 	<<<<<TicTacToe>>>>>
 	4
 	3   X X O
 	2   O O X
 	1   X O X
 	0
 	  0 1 2 3 4

 	Turn played: 9
	No winner, it is a DRAW.

 	<Since Gomoku gameboard is too large, we decided to not show DRAW here, but it's working>


How to run:
1. We did the assignment based on Ryan's "lab3code" program, and later we changed the name to lab4code, but this
   created two directories: lab3code, lab4code(they point to the same resources). If you happened to get this issue,
   just use lab4code and when complile use lab4code.exe in case anything goes wrong.

2. Several error messages will be displayed regarding of what you did on the command line:
  (1) The number of arguments on the command line is not 2, you will receive error message and instruction to tell 
      you the error and how to fix it:
	
	H:\Lab4_JackRyan\lab4code\x64\Debug>lab4code.exe
	This program takes in the name of game, please use the following input format:
	lab4code.exe + name of game
	Games avaliable are: Gomoku (or) TicTacToe


  (2) If your file name is wrong, you will receive the error message and the instruction of what to do next:
	
	H:\Lab4_JackRyan\lab4code\x64\Debug>lab4code.exe tigo
	This program takes in the name of game, please use the following input format:
	lab4code.exe + name of game
	Games avaliable are: Gomoku (or) TicTacToe



Extra Credit:
1. The correct format for input: lab4code.exe Gomoku 15 3, which will print out a 15x15 game board, and if three
   pieces on one line are the same, then win. If you enter only the board size, the rule to win to be default:
   five pieces on one line are the same is win. If you don't enter size or rule, them it will just be a default
   Gomoku game. Remember size and rule functionalities do not apply to TicTacToe.

2. Result for lab3code.exe Gomoku 15 3 (remember that 0 and 16 are just empty space around the game board, same as 
   lab 3):

	H:\Lab4_JackRyan\lab4code\x64\Debug>lab4code.exe Gomoku 15 3
	A GAME IS CREATED with 0x0 game board
	Gameboard changed to 15x0
	Gameboard changed to 15x15
	Initialize Gomoku Game
	16
	15
	14
	13
	12
	11
	10
	9
	8
	7
	6
	5
	4
	3
	2
	1
	0
	X 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16

	player X(Black) first
	enter one of the two from command line:
	1) 'quit' to stop playing. 2) a correct coordinate of form (unsigned int, insigned int) to place your piece.

3. Win when lab4code.exe Gomoku 15 3:
	16
	15
	14
	13
	12
	11
	10
	9
	8
	7
	6           W
	5           B B B
	4
	3         W
	2
	1
	0
	X 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16

	Turn played: 5
	X(Black) is winner
	GAME DESTROYED

4. The rest test cases are the same as previous.


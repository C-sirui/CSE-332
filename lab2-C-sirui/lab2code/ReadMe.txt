Ryan Chen
lab2

How to use:
under lab2code.exe folder
use cmd command: lab2exe.exe + name of inputfile

Information for functions is in header files
enum.cpp & enum.h:
--it has return values for different types of outcomes for different functions
--it has colors as piece_color
--tosmall: turn upper case string to smaller case

board.cpp:
--read_dimension: read dimension from a line for only 1 times. ***THEN IN MAIN function, it is called until finding a well formed dimension
--read_pieces: read pieces from a line utill the end of file, and put them into piece vector by certain order
--print_game: print out piece vector from end to begin. Thanks to the ordering, it is automatically formatted.

piece.cpp:
--piece_colortostring: read in a piece_color and return its string representation
--stringtopiece_color: read in a string and return its piece-color representation, and if input is not among the colors in enum, it returns invalid.
--struct for game_piece: all information needed for printing--color, player name, displays


Errors or warnings
1, when mutiplying width and height and adding to ann integer, there is a warning of converting unsigned int to int:
Warning	C26451	Arithmetic overflow: Using operator '*' on a 4 byte value and then casting the result to a 8 byte value. Cast the value to the wider type before calling operator '*' to avoid overflow (io.2).
Sloved by casting the 4 byte data to int

2, when vector<game_piece>.size not equals width*height, the print_game function return error and print message:
		"-1: --ARRAY_SIZE_DOESNOT_MATCH, this array<game_piece> doesn't match with game board size"

3, when read_pieces read a line that doesn't have five elements, error message:
"-6: 3 3 --CANNOT_EXTRACT_FIVE_VALUES, this line is not well formated, and is skipped"

4, strange error that game_piece.display doesn't print anything in cmd window.
Solved by fixing the struct game_piece by renaming its member varaibles


Trials
1, 
--------------------------------------------------------------------------------------------------input file:
red Xs X 0 0
red Xs X 0 2

red Xs X 1 1
red Xs X 1 2

red Xs X 2 2
blue Os O 0 1 
blue Os O 1 0 
3 3

blue Os O 2 0 
blue Os O 2 1
--------------------------------------------------------------------------------------------------output:
-- reading dimension --
0: 3 3 --SUCCESS, this line has dimension, and is not skipped

-- reading pieces --
-9: red Xs X 0 0 --PIECE_WELL_FORMED, this line is well formed, and is not skipped
-9: red Xs X 0 2 --PIECE_WELL_FORMED, this line is well formed, and is not skipped
-6:  --CANNOT_EXTRACT_FIVE_VALUES, this line is not well formated, and is skipped
-9: red Xs X 1 1 --PIECE_WELL_FORMED, this line is well formed, and is not skipped
-9: red Xs X 1 2 --PIECE_WELL_FORMED, this line is well formed, and is not skipped
-6:  --CANNOT_EXTRACT_FIVE_VALUES, this line is not well formated, and is skipped
-9: red Xs X 2 2 --PIECE_WELL_FORMED, this line is well formed, and is not skipped
-9: blue Os O 0 1  --PIECE_WELL_FORMED, this line is well formed, and is not skipped
-9: blue Os O 1 0  --PIECE_WELL_FORMED, this line is well formed, and is not skipped
-6: 3 3 --CANNOT_EXTRACT_FIVE_VALUES, this line is not well formated, and is skipped
-6:  --CANNOT_EXTRACT_FIVE_VALUES, this line is not well formated, and is skipped
-9: blue Os O 2 0  --PIECE_WELL_FORMED, this line is well formed, and is not skipped
-9: blue Os O 2 1 --PIECE_WELL_FORMED, this line is well formed, and is not skipped
-6:  --CANNOT_EXTRACT_FIVE_VALUES, this line is not well formated, and is skipped

-- result --
vector length = 9

XXX
OXO
XOO

2,
--------------------------------------------------------------------------------------------------input file:
8 8
black stone X 0 0
black stone X 0 2
black stone X 1 1
black stone X 2 0
black stone X 2 2
black stone X 3 1
black stone X 4 0
black stone X 4 2
black stone X 5 1
black stone X 6 0
black stone X 6 2
black stone X 7 1
white stone O 0 6
white stone O 1 5
white stone O 1 7
white stone O 2 6
white stone O 3 5
white stone O 3 7
white stone O 4 6
white stone O 5 5
white stone O 5 7
white stone O 6 6
white stone O 7 5
white stone O 7 7
--------------------------------------------------------------------------------------------------output:
C:\Users\poi\source\repos\cse332s-fl21-wustl\lab2-C-sirui\lab2code\Debug>lab2code.exe GMK.txt

-- reading dimension --
0: 8 8 --SUCCESS, this line has dimension, and is not skipped

-- reading pieces --
-6: 8 8 --CANNOT_EXTRACT_FIVE_VALUES, this line is not well formated, and is skipped
-9: black stone X 0 0 --PIECE_WELL_FORMED, this line is well formed, and is not skipped
-9: black stone X 0 2 --PIECE_WELL_FORMED, this line is well formed, and is not skipped
-9: black stone X 1 1 --PIECE_WELL_FORMED, this line is well formed, and is not skipped
-9: black stone X 2 0 --PIECE_WELL_FORMED, this line is well formed, and is not skipped
-9: black stone X 2 2 --PIECE_WELL_FORMED, this line is well formed, and is not skipped
-9: black stone X 3 1 --PIECE_WELL_FORMED, this line is well formed, and is not skipped
-9: black stone X 4 0 --PIECE_WELL_FORMED, this line is well formed, and is not skipped
-9: black stone X 4 2 --PIECE_WELL_FORMED, this line is well formed, and is not skipped
-9: black stone X 5 1 --PIECE_WELL_FORMED, this line is well formed, and is not skipped
-9: black stone X 6 0 --PIECE_WELL_FORMED, this line is well formed, and is not skipped
-9: black stone X 6 2 --PIECE_WELL_FORMED, this line is well formed, and is not skipped
-9: black stone X 7 1 --PIECE_WELL_FORMED, this line is well formed, and is not skipped
-9: white stone O 0 6 --PIECE_WELL_FORMED, this line is well formed, and is not skipped
-9: white stone O 1 5 --PIECE_WELL_FORMED, this line is well formed, and is not skipped
-9: white stone O 1 7 --PIECE_WELL_FORMED, this line is well formed, and is not skipped
-9: white stone O 2 6 --PIECE_WELL_FORMED, this line is well formed, and is not skipped
-9: white stone O 3 5 --PIECE_WELL_FORMED, this line is well formed, and is not skipped
-9: white stone O 3 7 --PIECE_WELL_FORMED, this line is well formed, and is not skipped
-9: white stone O 4 6 --PIECE_WELL_FORMED, this line is well formed, and is not skipped
-9: white stone O 5 5 --PIECE_WELL_FORMED, this line is well formed, and is not skipped
-9: white stone O 5 7 --PIECE_WELL_FORMED, this line is well formed, and is not skipped
-9: white stone O 6 6 --PIECE_WELL_FORMED, this line is well formed, and is not skipped
-9: white stone O 7 5 --PIECE_WELL_FORMED, this line is well formed, and is not skipped
-9: white stone O 7 7 --PIECE_WELL_FORMED, this line is well formed, and is not skipped

-- result --
vector length = 64

 O O O O
O O O O
 O O O O


X X X X
 X X X X
X X X X


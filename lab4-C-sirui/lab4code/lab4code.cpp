/*
* Aurthur: Ryan Chen, Jack Li
* Purpose: main function of tictactoe game
*          It check input from command line and decide to construct the corresponding game object and play it
*
*/
#include <iostream>
#include <vector>
#include "TicTacToe.h"
#include "pieces.h"
#include <iterator>
#include "GameBase.h"
#include "Gomoku.h"
using namespace std;

int main(int argc, char* argv[])
{

    // check num of input
    if (argc < num_argv) {
        usagemessage(argv[program_name]);
        return WRONG_NUM_INPUT;
    }

    // check input string
    string input = argv[main_input];

    // when input string is "TicTacToe"
    if (input == "TicTacToe") {

        // construct normal TicTacToe game of 3x3 board and 3 winning size
        GameBase* a = GameBase::check_argument(argc, argv);
        
        // play game
        int return_value = a->play(3);
        return return_value;
    }

    // when input string is "Gomoku" or "Gomoku ?" or "Gomoku ? ?"
    else if (input == "Gomoku") {

        // to get return value from play() in following code
        int return_value = -100;
        
        // when input string is not simply "Gomoku"
        if (argc > 2) {

            // if user input is "Gomoku ?"
            if (argc == 3) {

                // make sure game board size is > 0 and <= 99
                if (atoi(argv[2]) <= 99 && atoi(argv[2]) >= 2) {

                    // construct the game with user input
                    Gomoku a(atoi(argv[2]));
                    GameBase* b = &a;

                    // play game
                    return_value = b->play(5);
                }
                else {
                    cout << " " << endl;
                    cout << "INVALID_BOARD_SIZE, plase see uage message." << endl;
                    cout << "2 <= board size <= 99" << endl;
                    return INVALID_BOARD_SIZE;
                }
            }

            // if user input is "Gomoku ? ?"
            else if (argc == 4) {

                // make sure game board size is >0 and <= 99
                if (atoi(argv[2]) <= 99 && atoi(argv[2]) > 0) {

                    // make sure winning size is <= game board size
                    if ( ( atoi(argv[3]) <= atoi(argv[2]) ) && (atoi(argv[3]) >= 2) ) {

                        // construct the game with user input
                        Gomoku a( atoi(argv[2]) );
                        GameBase* b = &a;

                        // play game
                        return_value = b->play(atoi(argv[3]));
                    }
                    else {
                        cout << " " << endl;
                        cout << "INVALID_BOARD_SIZE, plase see uage message." << endl;
                        cout << "2 <= winning size <= board size" << endl;
                        return INVALID_WINNING_SIZE;
                    }
                }
                else {
                    cout << " " << endl;
                    cout << "INVALID_BOARD_SIZE, plase see uage message." << endl;
                    cout << "2 <= board size <= 99" << endl;
                    return INVALID_BOARD_SIZE;
                }
            }
        }
       
        // when input string is simply "Gomoku",
        else if (argc == 2) {

            // construct the game with 19x19 board and 5 winning size
            GameBase* a = GameBase::check_argument(argc, argv);

            // play game
            return_value = a->play(5);
        }

        return return_value;
    }

    // when client's command line input is not defined
    else {
        usagemessage(argv[program_name]);
        return UNKOWN_GAME_TYPE;
    }
    

}
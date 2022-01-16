/*
* Aurthur: Ryan Chen
* Purpose: main function of tictactoe game
*
*/
#include <iostream>
#include <vector>
#include "game.h"
#include "enum.h"
#include "pieces.h"
#include <iterator>
using namespace std;

int fact(int n) {
    if (n <= 0) {
        return 1;
    }
    else {
        int n1_fact = fact(n - 1);
        cout << n1_fact * n << endl;
        return n1_fact * n;
    }
}

int main(int argc, char* argv[])
{

    int i = fact(3);
    cout << i << endl;
    //// check num of input
    //if (argc != num_argv) {
    //    usagemessage(argv[program_name]);
    //    return WRONG_NUM_INPUT;
    //}

    //// check input string
    //string input = argv[main_input];
    //if (input == "TicTacToe") {
    //    game a;
    //    // set game board to 3X3, it should also work on any game borad that has length = width
    //    unsigned int width = 4;
    //    unsigned int height = 4;
    //    a.set_width(width);
    //    a.set_height(height);

    //    // play game
    //    int return_value = a.play();
    //    return return_value;
    //}
    //else {
    //    usagemessage(argv[program_name]);
    //    return INVALID_INPUT;
    //}

    

}

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "piece.h"
#include "enum.h"
#include "board.h"

using namespace std;


int main(int argc, char* argv[])
{
    // check num of input
    if (argc != CORRECT_INPUT_SIZE) {
        int ans = usage_message(argv[PROGRAM_NAME]);
        return ans;
    }

    // open file
    ifstream file_read_dimension;
    ifstream file_read_pieces;
    file_read_dimension.open(argv[array_index::INPUT_FILE]);
    file_read_pieces.open(argv[array_index::INPUT_FILE]);

    // check file is open
    if (!file_read_pieces.is_open() || !file_read_dimension.is_open()) {
        cout << "FAIL_OPEN_FILE" << endl;
        return FAIL_OPEN_FILE;
    }
    
    cout << endl;
    cout <<"-- reading dimension --" << endl;
    // get dimension
    unsigned int width, height;
    // ALL ERROR MESSAGGE IS INTEGRATED IN READ_DIMENSION FUNCTION
    auto outcome1 = read_dimension(file_read_dimension, width, height);
    while (outcome1 != SUCCESS) {
  /*      if (outcome1 == outcome_read_dimension::FAIL_GETLINE) {
            cout << FAIL_GETLINE << ": " << " --FAIL_GETLINE, there isn't a dimension, fail" << endl;
            return FAIL_READ_DIMENSION;
        }*/
        outcome1 = read_dimension(file_read_dimension, width, height);
    }

    cout << endl;
    cout << "-- reading pieces --" << endl;
    // get pieces vector
    vector<game_piece> pieces (static_cast<int>(width)* static_cast<int>(height)); // cast needed for 4 byte unsigned integer to avoid overflow
    auto outcome2 = read_pieces(file_read_pieces, pieces, width, height); // ALL ERROR MESSAGGES ARE INTEGRATED IN READ_PIECES FUNCTION
    if (outcome2 != SUCCESS) {
        return FAIL_READ_PIECE;
    }

    // print game board
    cout << endl;
    cout << "-- result --" << endl;
    if (print_game(pieces, width, height) != SUCCESS) {
        return PRINT_FAIL;
    }
    

}


#include <vector>
#include "board.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "piece.h"
#include "enum.h"
using namespace std;

int read_dimension(ifstream& file, unsigned int& x, unsigned int& y)
{
	string str, checker;
	if (getline(file, str)) {
		stringstream dim;
		dim << str;
		if (dim >> x) {
        
        }
		else {
			return FAIL_GETX;
		}
		if (dim >> y) {
            cout << SUCCESS << ": " << str << " --SUCCESS, this line has dimension, and is not skipped" << endl;
			return SUCCESS;
		}
		else {
			return FAIL_GETY;
		}
        if (dim >> checker) {
            cout << FAIL_NOT_DIMENSION << ": " << str << " --IFAIL_NOT_DIMENSION, this line has no dimension, and is skipped" << endl;
            return FAIL_NOT_DIMENSION;
        }
	}
	else {
		return FAIL_GETLINE;
	}
}

int read_pieces(ifstream& file, vector<game_piece>& pieces, unsigned int width, unsigned int height) {
    string str;
    string color, name, display;
    unsigned int x, y;
    while (getline(file, str)) {
        stringstream line(str);
        if (line >> color >> name >> display >> x >> y) {
            //check color
            if (stringtopiece_color(color) == piece_color::invalid) {
                cout << INVALID_COLOR << ": " << str << " --INVALID_COLOR, this line has invalid color, and is skipped" << endl;
                continue;
            }
            //check x and y
            if (x >= width || y >= height) {
                cout << X_AND_Y_EXTRACTED_INVALID << ": " << str << " --X_AND_Y_EXTRACTED_INVALID, this line has invalid x and y, and is skipped" << endl;
                continue;
            }
            //show it is well formed piece
            cout << PIECE_WELL_FORMED << ": " << str << " --PIECE_WELL_FORMED, this line is well formed, and is not skipped" << endl;
            
            //now put this piece into array<game_piece>
            game_piece temp = game_piece(stringtopiece_color(color), name, display);
            // cast needed for 4 byte unsigned integer to avoid overflow
            pieces[static_cast<int>(width) * static_cast<int>(y) + abs(static_cast<int>(x)- static_cast<int>(width-1))] = temp;
        }
        //check if five values all exist
        else {
            cout << CANNOT_EXTRACT_FIVE_VALUES << ": " << str << " --CANNOT_EXTRACT_FIVE_VALUES, this line is not well formated, and is skipped" << endl;
            continue;
        }
    }
    return SUCCESS;
}

int print_game(const vector<game_piece>& pieces, unsigned int width, unsigned int height) {
    // need cast here since unsigned int and int have different length
    int total_elements = static_cast<int>(width) * static_cast<int>(height);
    // check input array has correct number of elements
    cout << "vector length = " << pieces.size() << endl;
    if (pieces.size() != total_elements) {
        cout << ARRAY_SIZE_DOESNOT_MATCH << ": " << "--ARRAY_SIZE_DOESNOT_MATCH, this array<game_piece> doesn't match with game board size" << endl;
        return ARRAY_SIZE_DOESNOT_MATCH;
    }
    // print borad
    for (int i = (total_elements-1) ; i >= 0 ; --i) {
        if (0 == (i+1) % width) {
            cout << endl;
        }
        cout << pieces[i].display_;
    }
    return SUCCESS;
}
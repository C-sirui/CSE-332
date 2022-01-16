// lab1code.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "lab1code.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>


int main(int argc, char* argv[]) {
    vector<string> array_;
    // check num of input
    if (argc != 2) {
        usage_message(argv[static_cast<int>(array_indices::program_name)]);
        // need to cast the return value to int since the main function must be int
        return static_cast<int>(outcomes::usage_failure);
    }
    // check any undocumented error in parsing function (as long as it doesn't return success)
    if (parsing(array_, argv[static_cast<int>(array_indices::inputfile_name)])!=outcomes::success) {
        // need to cast the return value to int since the main function must be int
        return static_cast<int>(outcomes::failure_in_parsing_function);
    }
    // two new arrays, one store string, one store integers
    vector<int> digits_array;
    vector<string> string_array;
    int single_int_holder;
    for (string i : array_) {
    // boolean alldigit
    int alldigit = 1;
       for (char j : i) {
            if (!isdigit(j)) {
                string_array.push_back(i);
                alldigit = 0;
                break;
            }
        }
       if (alldigit) {
           istringstream digit(i);
           if (digit >> single_int_holder) {
               digits_array.push_back(single_int_holder);
           }
       }
    }
    // pritn result
    cout << "They are strings from input file: " << endl;
    for (string i : string_array) {
        cout << i << endl;
    }
    cout << "They are integers from input file: " << endl;
    for (int i : digits_array) {
        cout << i << endl;
    }
    return 0;
}

// print error message if used incorrectly
outcomes usage_message(char* program_name) {
    cout << "This program takes in only one txt file" << endl;
    cout << program_name << " + name of input txt file" << endl;
    return outcomes::usage_failure;
}

// print error message if cannot open
outcomes cannot_open(char* file_name) {
    cout << "This program takes in only one txt file" << endl;
    cout << file_name << " cannot be open" << endl;
    return outcomes::fail_to_open;
}

// read input file
outcomes parsing(vector<string>& array_, char* name) {
    // open and check if really open
    ifstream ifs;
    ifs.open(name);
    if (!ifs.is_open()) {
        cannot_open(name);
        return outcomes::fail_to_open;
    }
    // pull out every string from input file stream
    string word;
    while (ifs >> word) {
        array_.push_back(word);
    }
    // close and return
    ifs.close();
    return outcomes::success;
}
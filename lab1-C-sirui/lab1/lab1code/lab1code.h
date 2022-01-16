#pragma once
/*
* Aurthur: Ryan Chen
* Purpose: A record for functions in lab1code.cpp, 
			in case that any other source files need functions from lab1code.cpp in later labs.
* 
*/

#ifndef LAB1CODE_H
#define LAB1CODE_H

#include <vector> 
#include <string>
using namespace std;

// enumeration for the different array indices
// used when accessing argv[]
// need to cast it into integer
enum struct array_indices {
	program_name = 0, inputfile_name = 1
};

// enumeration for the different success and failure
// used as output of functions
// need to cast it into integer when used in main function
enum struct outcomes {
	success = 0, fail_to_open = -1, usage_failure = -2, failure_in_parsing_function = -3
};

// open, read file word by words
// input: a string arraty& and a char*
// output: one of the enumeration of outcomes
outcomes parsing(vector<string>& array_, char* name);

// print usage message if ussage failure
// input: program name at argv[arrat_indices::program_name] = argv[0]
// output: usage help message
outcomes usage_message(char* program_name);

// print usage message if ussage failure
// input: program name at argv[arrat_indices::inputfile_name] = argv[1]
// output: cannot open message
outcomes cannot_open(char* file_name);

#endif



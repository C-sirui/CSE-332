#include <string>
#include "enum.h"
#include <iostream>

using namespace std;

// take in string and return all lower case string
string tosmall(string up)
{
	for (char& c : up) {
		c = tolower(c);
	}
	return up;
}

// print usage message when input is wrong size
int usage_message(char* program_name) {
	cout << "This program takes in only one txt file" << endl;
	cout << program_name << " + name of input txt file" << endl;
	return FAIL_INPUTSIZE;
}
// parse input string by ';'
#include "MacroParsing.h"
#include <iostream>
#include <sstream>

vector<string> MacroParing::parse(string input)
{
	vector<string> commands;
	char delim = ';';

	stringstream sstream(input);
	string temp;

	while (getline(sstream, temp, delim)) {
		commands.push_back(temp);
	}

	return commands;
}

#include "RenameParsingStrategy.h"
#include <sstream>

vector<string> RenameParsingStrategy::parse(string input)
{
	vector<string> ans;
	istringstream sstream(input);

	string removeFirst;
	sstream >> removeFirst;
	ans.push_back(input);
	ans.push_back(removeFirst);

	return ans;
}
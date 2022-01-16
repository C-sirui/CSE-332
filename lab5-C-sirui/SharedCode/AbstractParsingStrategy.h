#pragma once

#ifndef ABSTRACTPARSINGSTRATEGY_H
#define ABSTRACTPARSINGSTRATEGY_H

#include <vector>
#include <string>
using namespace std;

class AbstractParsingStrategy {
public:
	virtual vector<string> parse(string) = 0;
};

#endif // !ABSTRACTPARSINGSTRATEGY_H

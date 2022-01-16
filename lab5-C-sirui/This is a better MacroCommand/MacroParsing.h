// parse input string by ';'
#pragma once

#ifndef MACROPARSING_H
#define MACROPARSING_H

#include "AbstractParsingStrategy.h"

class MacroParing : public AbstractParsingStrategy {
	virtual vector<string> parse(string);
};

#endif // !MACROPARSING_H

#pragma once

#ifndef TOUCHCATPARSING_H
#define TOUCHCATPARSING_H

#include "AbstractParsingStrategy.h"

class TouchCatParsing : public AbstractParsingStrategy {
public:
	virtual vector<string> parse(string);
};

#endif // !TOUCHCATPARSING_H
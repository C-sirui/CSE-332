#pragma once

#ifndef RENAMEPARSINGSTRATEGY_H
#define RENAMEPARSINGSTRATEGY_H
	
#include "AbstractParsingStrategy.h"

class RenameParsingStrategy : public AbstractParsingStrategy {
public:
	virtual vector<string> parse(string);
};

#endif // !RENAMEPARSINGSTRATEGY_H

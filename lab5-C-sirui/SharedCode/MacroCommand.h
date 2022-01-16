#pragma once

#ifndef MACROCOMMAND_H
#define MACROCOMMAND_H

#include "AbstractCommand.h"
#include "AbstractParsingStrategy.h"
#include "AbstractFileSystem.h"
#include <vector>


class MacroCommand : public AbstractCommand {
private:
	
	AbstractParsingStrategy* parsingStrategy;
	vector<AbstractCommand*> commandList;
	AbstractFileSystem* fileSystem;

public:
// initializers
	MacroCommand(AbstractFileSystem* a) : fileSystem(a) {};
	virtual void addCommand(AbstractCommand*);
	void setParseStrategy(AbstractParsingStrategy*);


// functions
	virtual int execute(string);
	virtual void displayInfo();
};

#endif // !MACROCOMMAND_H


#pragma once

#ifndef MACROCOMMAND_H
#define MACROCOMMAND_H

#include "CommandPrompt.h"
#include "AbstractCommand.h"
#include "AbstractParsingStrategy.h"
#include "AbstractFileSystem.h"
#include <vector>


class MacroCommand : public AbstractCommand {
private:
	
	AbstractParsingStrategy* parsingStrategy;
	vector<AbstractCommand*> commandList;
	CommandPrompt* commandPrompt;
	AbstractFileSystem* rubbish;

public:
// initializers
	MacroCommand(AbstractFileSystem* a) : rubbish(a) {};
	virtual void addCommand(AbstractCommand*);
	void setParseStrategy(AbstractParsingStrategy*);
	void setCommandPrompt(CommandPrompt*);

// functions
	virtual int execute(string);
	virtual void displayInfo();
};

#endif // !MACROCOMMAND_H


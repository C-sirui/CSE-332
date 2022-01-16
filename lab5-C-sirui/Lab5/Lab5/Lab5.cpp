// Lab5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "CommandPrompt.h"
#include <iostream>
#include "SimpleFileSystem.h"
#include "SimpleFileFactory.h"
#include "TouchCommand.h"
#include <string>
#include "LSCommand.h"
#include "RemoveCommand.h"
#include "CatCommand.h"
#include "DisplayCommand.h"
#include "CopyCommand.h"
#include "MacroCommand.h"
#include "TouchCatParsing.h"
#include "RenameParsingStrategy.h"

int main()
{
	CommandPrompt user;
	SimpleFileSystem* fileSystem = new SimpleFileSystem();
	SimpleFileFactory* fileFactory = new SimpleFileFactory();
	AbstractCommand* touchCommand = new TouchCommand(fileSystem, fileFactory);
	AbstractCommand* lsCommand = new LSCommand(fileSystem);
	AbstractCommand* rmCommand = new RemoveCommand(fileSystem);
	AbstractCommand* catCommand = new CatCommand(fileSystem);
	AbstractCommand* displayCommand = new DisplayCommand(fileSystem);
	AbstractCommand* copyCommand = new CopyCommand(fileSystem);

	AbstractParsingStrategy* renameParse = new RenameParsingStrategy();
	MacroCommand* renameCommand = new MacroCommand(fileSystem);
	renameCommand->setParseStrategy(renameParse);
	renameCommand->addCommand(copyCommand);
	renameCommand->addCommand(rmCommand);

	AbstractParsingStrategy* touchCatParse = new TouchCatParsing();
	MacroCommand* touchCatCommand = new MacroCommand(fileSystem);
	touchCatCommand->setParseStrategy(touchCatParse);
	touchCatCommand->addCommand(touchCommand);
	touchCatCommand->addCommand(catCommand);

	user.setFileFactory(fileFactory);
	user.setFileSystem(fileSystem);
	string touch = "touch";
	string ls = "ls";
	string rm = "rm";
	string cat = "cat";
	string ds = "ds";
	string cp = "cp";
	string mc = "mc";
	string rn = "rn";
	string tc = "tc";
	user.addCommand(touch, touchCommand);
	user.addCommand(ls, lsCommand);
	user.addCommand(rm, rmCommand);
	user.addCommand(cat, catCommand);
	user.addCommand(ds, displayCommand);
	user.addCommand(cp, copyCommand);
	user.addCommand(rn, renameCommand);
	user.addCommand(tc, touchCatCommand);

	user.run();


	return 0;
}



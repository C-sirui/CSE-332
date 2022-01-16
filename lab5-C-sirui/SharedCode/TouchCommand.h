#pragma once

#ifndef TOUCHCOMMAND_H
#define TOUCHCOMMAND_H

#include "AbstractCommand.h"

class TouchCommand : public AbstractCommand
{
private:
	AbstractFileSystem* fileSystem;
	AbstractFileFactory* fileFactory;
public:
	TouchCommand(AbstractFileSystem* a, AbstractFileFactory* b) : fileSystem(a), fileFactory(b) {};
	void displayInfo();
	int execute(string);

private:

};

#endif // !TOUCHCOMMAND_H

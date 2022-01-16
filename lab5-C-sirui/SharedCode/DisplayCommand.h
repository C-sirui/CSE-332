#pragma once

#ifndef DISPLAYCOMMAND_H
#define DISPLAYCOMMAND_H

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

class DisplayCommand : public AbstractCommand {
private:
	AbstractFileSystem* fileSystem;
public:
	DisplayCommand(AbstractFileSystem* a) : fileSystem(a) {};
	void displayInfo();
	int execute(string);
};


#endif // DISPLAYCOMMAND_H

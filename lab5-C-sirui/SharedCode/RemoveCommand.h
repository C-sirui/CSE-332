#pragma once

#ifndef REMOVECOMMAND_H
#define REMOVECOMMAND_H

#include "AbstractCommand.h"

class RemoveCommand : public AbstractCommand {
private:
	AbstractFileSystem* fileSystem;
public:
	RemoveCommand(AbstractFileSystem* a) : fileSystem(a) {};
	void displayInfo();
	int execute(string);
};



#endif // !REMOVECOMMAND_H


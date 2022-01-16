// CatCommand is defined here: cat <filename> [-a] -- it writes or appends the file
#pragma once

#ifndef CATCOMMAND_H
#define CATCOMMAND_H

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

class CatCommand : public AbstractCommand {
private:
	AbstractFileSystem* fileSystem;
public:
	CatCommand(AbstractFileSystem* a) : fileSystem(a){};
	virtual int execute(std::string);
	virtual void displayInfo();
	string promptInput();
};


#endif // ! CATCOMMAND_H

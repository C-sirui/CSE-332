#pragma once

#ifndef COPYCOMMAND_H
#define COPYCOMMAND_H

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
class CopyCommand : public AbstractCommand{
private:
	AbstractFileSystem* fileSystem;
public:
	CopyCommand(AbstractFileSystem* a) : fileSystem(a){};
	virtual int execute(std::string);
	virtual void displayInfo();
};


#endif // !COPYCOMMAND_H

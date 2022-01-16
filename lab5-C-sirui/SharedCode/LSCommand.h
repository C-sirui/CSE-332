#pragma once

#ifndef LSCOMMAND_H
#define LSCOMMAND_H

#include "CommandPrompt.h"

class LSCommand : public AbstractCommand{
private:
	AbstractFileSystem* fileSystem;
public:
	LSCommand(AbstractFileSystem* a) : fileSystem(a) {};
	void displayInfo();
	int execute(string);

private:
};

#endif // !LSCOMMAND_H

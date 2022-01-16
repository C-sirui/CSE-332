#pragma once

#ifndef ABSTRACTCOMMAND_H
#define ABSTRACTCOMMAND_H

#include <string>	
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

class AbstractCommand {
public:
	virtual int execute(std::string) = 0;
	virtual void displayInfo() = 0;
	virtual ~AbstractCommand() = default;

};


#endif // !ABSTRACTCOMMAND_H

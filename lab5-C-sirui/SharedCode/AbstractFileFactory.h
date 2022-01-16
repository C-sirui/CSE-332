#pragma once
// studio 18 - file factory interface declared here

#ifndef ABSTRACTFILEFACTORY_H
#define ABSTRACTFILEFACTORY_H
#include <string>
#include "AbstractFile.h"

class AbstractFileFactory {
public:
	virtual AbstractFile* createFile(string input) = 0;
};


#endif // !ABSTRACTFILEFACTORY_H


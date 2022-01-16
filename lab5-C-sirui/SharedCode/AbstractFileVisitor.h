#pragma once
// declaration of the file visitor interface here

#ifndef ABSTRACTFILEVISITOR_H
#define ABSTRACTFILEVISITOR_H

#include "AbstractFile.h"
#include "TextFile.h"
#include "ImageFile.h"

class AbstractFileVisitor {

public:
	virtual void visit_TextFile(AbstractFile* file) = 0;
	virtual void visit_ImageFile(AbstractFile* file) = 0;
};




#endif
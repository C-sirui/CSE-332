#pragma once
// declaration of BasicDisplayVisitor here


#ifndef BASICDISPLAYVISITOR_H
#define BASICDISPLAYVISITOR_H

#include "AbstractFileVisitor.h"

class BasicDisplayVisitor : public AbstractFileVisitor {

public:
	virtual void visit_TextFile(AbstractFile* file);
	virtual void visit_ImageFile(AbstractFile* file);
	
};

#endif
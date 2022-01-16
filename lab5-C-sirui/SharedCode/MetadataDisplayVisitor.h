#pragma once
// declaration of MetadataDisplayVisitor here



#ifndef MATADATADISPLAYVISITOR_H
#define MATADATADISPLAYVISITOR_H

#include "AbstractFileVisitor.h"

class MetadataDisplayVisitor : public AbstractFileVisitor {

public:
	virtual void visit_TextFile(AbstractFile* file);
	virtual void visit_ImageFile(AbstractFile* file);

};

#endif
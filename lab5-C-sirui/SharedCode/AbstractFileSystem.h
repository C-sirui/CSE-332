#pragma once
// declaration of the interface all file systems provide goes here
#ifndef ABSTRATCFILESYSTEM_H
#define ABSTRATCFILESYSTEM_H

#include "AbstractFile.h"
#include <set>

class AbstractFileSystem {
public:
	// member functions
	virtual int addFile(string fileName, AbstractFile* file) = 0;
	//virtual int createFile(string fileName) = 0;
	virtual int deleteFile(string fileName) = 0;
	virtual AbstractFile* openFile(string fileName) = 0;
	virtual int closeFile(AbstractFile* file) = 0;
	virtual set<string>  getFileNames() = 0;
	virtual AbstractFile* getFile(string fileName) = 0;
};

#endif // ABSTRATCFILESYSTEM_HS

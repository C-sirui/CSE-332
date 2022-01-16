#pragma once
// declaration of SimpleFileSystem class goes here
#ifndef SIMPLEFILESYSTEM_H
#define SIMPLEFILESYSTEM_H

#include "AbstractFileSystem.h"
#include "ImageFile.h"
#include "TextFile.h"
#include <map>
#include <set>
using namespace std;

class SimpleFileSystem: public AbstractFileSystem {

// member variables
private:
	map<string, AbstractFile*> files;
	set<AbstractFile*> openFiles;

// member functions
public:
	int addFile(string fileName, AbstractFile* file);
	//int createFile(string fileName);
	AbstractFile* openFile(string fileName);
	int closeFile(AbstractFile* file);
	int deleteFile(string fileName);
	set<string> getFileNames();
	AbstractFile* getFile(string fileName);
};


#endif // SIMPLEFILESYSTEM_H


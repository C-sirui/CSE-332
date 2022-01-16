#pragma once
// Image file class declaration here

#ifndef IMAGEFILE_H
#define IMAGEFILE_H
#include "AbstractFile.h"
#include <string>
#include <vector>
#include <iostream>

class AbstractFileVisitor;

class ImageFile : public AbstractFile{
private:
// member variables
	string name;
	vector<char> contents;
	char size;
public:
// constructor
	ImageFile(string input);
	ImageFile(string, AbstractFile*); // copy constructor
// member functions
	virtual unsigned int getImageSize();
	virtual unsigned int getSize();
	virtual string getName();
	virtual int write(vector<char> input);
	virtual int append(vector<char>);
	virtual vector<char> read();
	virtual void accept(AbstractFileVisitor*);
	virtual bool isPasswordProxy();
	virtual bool isImg();
	virtual bool isText();
	virtual vector<char> getContent();
	virtual AbstractFile* clone(string, AbstractFile*);
	virtual AbstractFile* getgetProtectedFile();
	virtual string getPassword();
};

#endif // !IMAGEFILE_H

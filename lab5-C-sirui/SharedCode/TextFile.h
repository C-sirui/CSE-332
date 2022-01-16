#pragma once
// Define txt file class inheritance in abstract file system


#ifndef TEXTFILE_H
#define TEXTFILE_H
#include "AbstractFile.h"
#include <vector>
#include <string>
#include <iostream>

class AbstractFileVisitor;

class TextFile : public AbstractFile {
private:
	// member variables
	vector<char> contents;
	string name;
public:
	// constructor
	TextFile(string); 
	TextFile(string, AbstractFile*); // copy constructor
	// functions
	virtual void accept(AbstractFileVisitor*);
	virtual unsigned int getSize();
	virtual string getName();
	virtual int write(vector<char>);
	virtual int append(vector<char>);
	virtual vector<char>  read();
	virtual bool isPasswordProxy();
	virtual bool isImg();
	virtual bool isText();
	virtual unsigned int getImageSize();
	virtual vector<char> getContent();
	virtual AbstractFile* clone(string, AbstractFile*);
	virtual string getPassword();
protected:
	AbstractFile* getgetProtectedFile();
};


#endif // !TEXTFILE_H



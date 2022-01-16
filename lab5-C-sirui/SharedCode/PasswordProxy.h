#pragma once

#ifndef PASSWORDPROXY_H
#define PASSWORDPROXY_H

#include "AbstractFile.h"
#include <string>

class PasswordProxy : public AbstractFile {
private:
	AbstractFile* protectedFile;
	string password;
protected:
	string passwordPrompt();
	int checkPassword(string input);
	virtual AbstractFile* getgetProtectedFile();
	virtual string getPassword();
public:
	PasswordProxy(AbstractFile* protectedFile_, string password_) : protectedFile(protectedFile_), password(password_) {};
	PasswordProxy(string, AbstractFile*); // copy constructor
	virtual vector<char> read();
	virtual int write(vector<char>);
	virtual int append(vector<char>);
	virtual unsigned int getSize();
	virtual string getName();
	virtual void accept(AbstractFileVisitor*);
	virtual bool isPasswordProxy();
	virtual bool isImg();
	virtual bool isText();
	virtual unsigned int getImageSize();
	virtual vector<char> getContent();
	virtual AbstractFile* clone(string, AbstractFile*);
	~PasswordProxy() {
		delete protectedFile;
	}		
};

#endif // PASSWORDPROXY

// Studio20.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "PasswordProxy.h"
#include <iostream>
#include "AbstractFileFactory.h"
#include "AbstractFileVisitor.h"
#include "BasicDisplayVisitor.h"
#include "SimpleFileFactory.h"



int main()
{
	AbstractFileFactory* a = new SimpleFileFactory;
	AbstractFile* txt = a->createFile("text.txt");
	vector<char> v = { 'X', ' ', 'X', ' ', 'X', ' ', 'X',' ', 'X', '3' };


	PasswordProxy txtProxy(txt, "password is no password");
	AbstractFileVisitor* read = new BasicDisplayVisitor;
	txtProxy.write(v);
	txtProxy.accept(read);
	return 0;
}


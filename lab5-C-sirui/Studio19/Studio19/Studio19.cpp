// Studio19.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>

#include "TextFile.h"
#include "ImageFile.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"
#include "AbstractFileVisitor.h"
#include "SimpleFileFactory.h"
#include "BasicDisplayVisitor.h"
#include "MetadataDisplayVisitor.h"

#include "pch.h"
#include <sstream>


int main()
{
	AbstractFileFactory* a = new SimpleFileFactory;
	AbstractFile * txt = a->createFile("uxeyrgtnfu.txt");

	//AbstractFileVisitor *visitor = new BasicDisplayVisitor;
	//AbstractFileVisitor* meta = new MetadataDisplayVisitor;

	//vector<char> w = { 'h', 'i' };
	//txt->write(w);
	//txt->accept(visitor);

	//vector<char> v = { 'X', ' ', 'X', ' ', 'X', ' ', 'X',' ', 'X', '3' };
	//AbstractFile* img = a->createFile("123.img");

	//img->write(v);
	//img->accept(visitor);

	//img->accept(meta);
	//txt->accept(meta);
	std::string fileName = "FileName.img";
	ImageFile t(fileName);
	std::string fileNames = "FileName.txt";
	TextFile f(fileNames);
	vector<char> v = { 'X', ' ', 'X', ' ', 'X', ' ', 'X',' ', 'X', '3' };
	t.write(v);
	f.write(v);
	AbstractFileVisitor* bdv = new MetadataDisplayVisitor;
	t.accept(bdv);
	f.accept(bdv);




	return 0;
}

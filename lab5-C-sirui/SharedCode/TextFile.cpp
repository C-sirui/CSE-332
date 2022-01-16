//  Define the TextFile class here
#include "AbstractFileVisitor.h"
#include <iostream>
#include <vector>
#include "TextFile.h"

using namespace std;

TextFile::TextFile(string input): name(input) {}

TextFile::TextFile(string new_name_with_no_extension, AbstractFile* file)
{
	this->name = new_name_with_no_extension + ".txt";
	this->contents = file->getContent();
}

unsigned int TextFile::getSize()
{
	return this->contents.size();
}

string TextFile::getName()
{
	return this->name;
}

int TextFile::write(vector<char> input)
{
	this->contents = input;
	return 0;
}

int TextFile::append(vector<char> input)
{
	auto it = input.begin();
	auto end = input.end();
	while(it != end){
		this->contents.push_back(*it);
		++it;
	}
	return SUCCESS;
}

vector<char> TextFile::read()
{
	//auto it = this->contents.begin();
	//auto end = this->contents.end();
	//while(it != end) {
	//	cout << *it;
	//	++it;
	//}
	//cout << endl;
	return this->contents;
}

bool TextFile::isPasswordProxy()
{
	return false;
}

bool TextFile::isImg()
{
	return false;
}

bool TextFile::isText()
{
	return true;
}

unsigned int TextFile::getImageSize()
{
	return NOT_SUPPORTED;
}

vector<char> TextFile::getContent()
{
	return this->contents;
}

AbstractFile* TextFile::clone(string new_name_with_no_extension, AbstractFile* file)
{
	AbstractFile* temp = new TextFile(new_name_with_no_extension, file);
	return temp;
}

string TextFile::getPassword()
{
	// NOT SUPPORTED
	string empty;
	return empty;
}

AbstractFile* TextFile::getgetProtectedFile()
{
	// NOT SUPPORTED
	return nullptr;
}

void TextFile :: accept(AbstractFileVisitor* AbstractFileVisitor) {
	AbstractFileVisitor->visit_TextFile(this);
}


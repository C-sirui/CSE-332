#include "ImageFile.h"
#include "AbstractFileVisitor.h"
// definition of ImageFile class here
#include <vector>
#include <iostream>

unsigned int ImageFile::getImageSize()
{
	return this->size;
}

ImageFile::ImageFile(string input)
{
	this->name = input;
	this->size = 0;
}

ImageFile::ImageFile(string new_name_with_no_extension, AbstractFile* file)
{
	this->name = new_name_with_no_extension + ".img";
	this->contents = file->getContent();
	this->size = file->getImageSize();
}

unsigned int ImageFile::getSize()
{
	return this->contents.size();
}

string ImageFile::getName()
{
	return this->name;
}

int ImageFile::write(vector<char> input)
{
	this->size = *(input.end() - 1);
	int size_int = this->size - 48;

	// if size_int is not from 0 to 9
	if (size_int > 9 || size_int < 0) {
		this->contents.clear();
		this->size = 0;
		return outcome_image::INVALID_INPUT;
	}

	// if size doesn't match num of chars in input file
	if ( input.size() - 1 != size_int * size_int ) {

		this->contents.clear();
		this->size = 0;
		return outcome_image::INVALID_INPUT;
	}

	// read input into content
	auto it = input.begin();
	auto end = input.end() - 1;
	while (it != end) {
		// if content is neither 'X' or ' '
		if (*it != ' ' && *it != 'X') {
			this->contents.clear();
			this->size = 0;
			return outcome_image::INVALID_INPUT;
		}

		this->contents.push_back(*it);
		++it;
	}

	return SUCCESS;
}


int ImageFile::append(vector<char>)
{
	return APPEND_NOT_SUPPORTED;
}

vector<char> ImageFile::read()
{	
	//int size_int = this->size - 48;
	//for (int i = 0; i < size_int * size_int; i+=size_int) {
	//	for (int j = 0; j < size_int; ++j) {
	//		cout << this->contents[j + i];
	//	}
	//	cout << endl;
	//}
	vector<char> temp = contents;
	return temp;

}
void ImageFile::accept(AbstractFileVisitor* AbstractFileVisitor)
{
	AbstractFileVisitor->visit_ImageFile(this);
}

bool ImageFile::isPasswordProxy()
{
	return false;
}

bool ImageFile::isImg()
{
	return true;
}

bool ImageFile::isText()
{
	return false;
}

vector<char> ImageFile::getContent()
{
	return contents;
}

AbstractFile* ImageFile::clone(string new_name_with_no_extension, AbstractFile* file)
{
	AbstractFile* temp = new ImageFile(new_name_with_no_extension, file);
	return temp;
}

AbstractFile* ImageFile::getgetProtectedFile()
{
	// not supported
	return nullptr;
}

string ImageFile::getPassword()
{
	// NOT SUPPORTED
	string empty;
	return empty;
}



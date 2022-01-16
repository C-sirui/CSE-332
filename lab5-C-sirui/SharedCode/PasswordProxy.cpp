#include "PasswordProxy.h"
#include <iostream>
#include "BasicDisplayVisitor.h"


string PasswordProxy::passwordPrompt()
{
	string input;
	cout.clear();
	getline(cin, input);
	return input;
}

int PasswordProxy::checkPassword(string input)
{
	if (this->password == input) {
		return 1;
	}
	else {
		return 0;
	}
}

AbstractFile* PasswordProxy::getgetProtectedFile()
{
	return this->protectedFile;
}

string PasswordProxy::getPassword()
{
	return this->password;
}

PasswordProxy::PasswordProxy(string new_name_with_no_extension, AbstractFile* file)
{
	AbstractFile* temp = file->getgetProtectedFile();
	AbstractFile* temp_copy = temp->clone(new_name_with_no_extension, temp);
	this->protectedFile = temp_copy;
	this->password = file->getPassword();
}

vector<char> PasswordProxy::read()
{
	cout << "enter password to continue" << endl;
	string password_prompted = this->passwordPrompt();
	if (this->password == password_prompted) {
		return this->protectedFile->read();
	}
	else {
		vector<char> empty;
		empty.clear();
		return empty;
	}
}

int PasswordProxy::write(vector<char> input)
{
	cout << "enter password to continue" << endl;
	string password_prompted = this->passwordPrompt();
	if (this->password == password_prompted) {
		return this->protectedFile->write(input);
	}
	else {
		return outcomes_PasswordProxy::WRONG_PASSWORD;
	}
}

int PasswordProxy::append(vector<char> input)
{
	cout << "enter password to continue" << endl;
	string password_prompted = this->passwordPrompt();
	if (this->password == password_prompted) {
		return this->protectedFile->append(input);
	}
	else {
		return outcomes_PasswordProxy::WRONG_PASSWORD;
	}
}

unsigned int PasswordProxy::getSize()
{
	return this->protectedFile->getSize();
}

string PasswordProxy::getName()
{
	return this->protectedFile->getName();
}

void PasswordProxy::accept(AbstractFileVisitor* AbstractFileVisitor)
{
	cout << "enter password to continue" << endl;
	string password_prompted = this->passwordPrompt();
	if (this->password == password_prompted) {
		this->protectedFile->accept(AbstractFileVisitor);
	}
}

bool PasswordProxy::isPasswordProxy()
{
	return true;
}

bool PasswordProxy::isImg()
{
	return false;
}

bool PasswordProxy::isText()
{
	return false;
}

unsigned int PasswordProxy::getImageSize()
{
	return NOT_SUPPORTED;
}

vector<char> PasswordProxy::getContent()
{
	return this->protectedFile->getContent();
}

AbstractFile* PasswordProxy::clone(string new_name_with_no_extension, AbstractFile* file)
{
	AbstractFile* temp = new PasswordProxy(new_name_with_no_extension, file);
	return temp;
}

	 
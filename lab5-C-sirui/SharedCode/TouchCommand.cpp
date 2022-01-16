#include "TouchCommand.h"
#include "PasswordProxy.h"
#include <iostream>
#include <sstream>

void TouchCommand::displayInfo()
{
	cout << "enter 'touch <filename>' to create file, or 'touch <filename> -p' to create encrypted file" << endl;
	cout << endl;
}

int TouchCommand::execute(string input)
{
	// IF INPUT IS EMPTY
	if (input.empty()) {
		this->displayInfo();
		return TOUCHCOMMAND_EMPTY_IPUT;
	}

	AbstractFile* file;
	istringstream commandLineInput(input);
	string flag;
	string parameter;
	string unnecessaryParameter;
	commandLineInput >> parameter >> flag >> unnecessaryParameter;

	// IF THE FILE ALREADY EXIST
	if (this->fileSystem->getFile(parameter) != nullptr) {
		cout << "File Creation fail: already exist" << endl << endl;
		return TOUCHCOMMAND_FILE_ALREADY_EXIST;
	}

	// IF GIVEN NOT NEEDED PARAMETER
	if (!unnecessaryParameter.empty()) {
		cout << "File Creation fail: too many parameters" << endl << endl;
		this->displayInfo();
		return TOUCHCOMMAND_UNNECESSARY_PARAMETER;
	}		
	
	// CREATE FILE BY FILE FACTORY
	file = fileFactory->createFile(parameter);
	if (file != nullptr)
	{
		cout << "File Creation Sucess" << endl << endl;
	}
	else
	{
		cout << "File Creation Fail" << endl << endl;
		return TOUCHCOMMAND_CREATION_FAILED;
	}

	// ADD PASSWORD
	if (flag == "-p") {
		string password;
		cout.clear();
		cout << "What is the password?" << endl;
		getline(cin, password);
		AbstractFile* encryptedFile = new PasswordProxy(file, password);
		cout << endl;

		// ADD ENCRYPTED FILE TO FILE SYSTEM
		int addFile = fileSystem->addFile(parameter, encryptedFile);
		if (addFile == SUCCESS) {
			return SUCCESS;
		}
		else if (addFile == outcome_simpleFile::FILE_ALREADY_EXIST) {
			return FILE_ALREADY_EXIST;
		}
		else if (addFile == outcome_simpleFile::FILE_NAME_ALREADY_EXIST) {
			return FILE_NAME_ALREADY_EXIST;
		}
		else if (addFile == outcome_simpleFile::FILE_NULLPOINTER) {
			return FILE_NULLPOINTER;
		}
	}

	// ADD NORMAL FILE TO FILE SYSTEM
	else if (flag.empty()) {
		int addFile = fileSystem->addFile(parameter, file);
		if (addFile == SUCCESS) {
			return SUCCESS;
		}
		else if (addFile == outcome_simpleFile::FILE_ALREADY_EXIST) {
			return FILE_ALREADY_EXIST;
		}
		else if (addFile == outcome_simpleFile::FILE_NAME_ALREADY_EXIST) {
			return FILE_NAME_ALREADY_EXIST;
		}
		else if (addFile == outcome_simpleFile::FILE_NULLPOINTER) {
			return FILE_NULLPOINTER;
		}
	}
}



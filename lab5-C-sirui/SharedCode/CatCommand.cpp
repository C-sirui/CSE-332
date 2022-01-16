// CatCommand is implemented here: cat <filename> [-a] -- it writes or appends the file
#include "CatCommand.h"
#include "ImageFile.h"
#include "BasicDisplayVisitor.h"
#include "AbstractFileVisitor.h"
#include <iostream>
#include <sstream>
#include <vector>


void CatCommand::displayInfo()
{
	cout << "Append the file with 'cat <filename> -a' or write the file with 'cat <filename>' " << endl;
	cout << endl;
}

int CatCommand::execute(std::string input)
{
	// IF INPUT IS EMPTY
	if (input.empty()) {
		cout << "cat: empty parameters" << endl;
		this->displayInfo();
		return CATCOMMAND_EMPTY_IMPUT;
	}

	istringstream commandLineInput(input);
	string parameter; // file name
	string flag; // [-a]
	string unnecessaryParameter;
	commandLineInput >> parameter >> flag >> unnecessaryParameter;

	// IF INPUT FILE DO NOT EXIST
	AbstractFile* file = this->fileSystem->getFile(parameter);
	if (file == nullptr) {
		cout << "cat: cannot find given file" << endl << endl;
		return CATCOMMAND_CANNOT_FIND_FILE;
	}

	// IF THERE IS NOT NEEDED PARAMETER
	if (!unnecessaryParameter.empty()) {
		cout << "cat: too mant parameters" << endl;
		this->displayInfo();
		return CATCOMMAND_UNNECESSARY_PARAMETER;
	}

	// HOLDING USER INPUT
	string userInput;
	string temp;

	// APPEND
	if (!parameter.empty() && flag == "-a") {

		// print the file first
		if (this->fileSystem->getFile(parameter)->getSize() == 0) {
			cout << endl << "curren file: " << endl;
			cout << "file is empty" << endl;;
		}
		else {
			vector<char> currentFileContent = this->fileSystem->getFile(parameter)->read();
			string str(currentFileContent.begin(), currentFileContent.end());
			cout << endl << "curren file: " << endl;
			cout << str << endl;
		}

		// NOW APPEND THE FILE
		cout << "Appending the file: " << file->getName() << ", enter ':wq' to save and exit or ':q' to exit without saving" << endl;
		cout << "your input is following the end of current file directly without newline" << endl;
		temp = promptInput();
		while (temp != ":wq" && temp != ":q") {
			userInput += temp;
			temp = promptInput();
			if (temp == ":wq" || temp == ":q") {
				break;
			}
			else {
				userInput += "\n";
			}
		}
		// CHECK USER WANT TO SAVE OR NOT
		if (temp == ":wq") {
			vector<char> temp(userInput.begin(), userInput.end());
			int result = file->append(temp);
			if (result == SUCCESS) {
				cout << "exited and saved" << endl << endl;
				return SUCCESS;
			}
			else if (result == APPEND_NOT_SUPPORTED){
				cout << "cat: img cannot append" << endl << endl;
				return APPEND_NOT_SUPPORTED;
			}
		}
		else {
			cout << "exited and not saved" << endl << endl;
			return SUCCESS;
		}
	}

	else if (!parameter.empty() && flag.empty()) {
		// NOW WRITE THE FILE
		cout << "Writing the file: " << file->getName() << ", enter ':wq' to save and exit or ':q' to exit without saving" << endl;
		temp = promptInput();
		while (temp != ":wq" && temp != ":q") {
			userInput += temp;
			temp = promptInput();
			if (temp == ":wq" || temp == ":q") {
				break;
			}
			else {
				userInput += "\n";
			}
		}

		// CHECK USER WANT TO SAVE OR NOT
		if (temp == ":wq") {
			vector<char> temp(userInput.begin(), userInput.end());
			// writing img file can fail
			if (file->write(temp) == SUCCESS) {
				cout << "exited and saved" << endl << endl;
				return SUCCESS;
			}
			else
			{
				cout << "cat: write file failed" << endl << endl;
				return CATCOMMAND_IMG_WRITE_FAIL;
			}
		}
		else {
			cout << "exited and not saved" << endl << endl;
			return SUCCESS;
		}
	}

	else {
		cout << "cat fail" << endl;
		this->displayInfo();
		return CATCOMMAND_UNKOWN;
	}
}

string CatCommand::promptInput()
{
	string input;
	cout.clear();
	getline(cin, input);
	return input;
}
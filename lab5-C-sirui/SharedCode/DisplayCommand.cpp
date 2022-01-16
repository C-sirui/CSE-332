#include "DisplayCommand.h"
#include "AbstractFileVisitor.h"
#include "BasicDisplayVisitor.h"
#include <iostream>
#include <sstream>


void DisplayCommand::displayInfo()
{
	cout << "enter 'ds <filename>' to diplay file foramttedly or 'ds <filename> -d' to display unformattedly" << endl;
	cout << endl;
}

int DisplayCommand::execute(string input)
{
	// IF INPUT IS EMPTY
	if (input.empty()) {
		cout << "ds: empty parameters" << endl;
		this->displayInfo();
		return DISPLAYCOMMAND_EMPTY_INPUT;
	}

	istringstream commandLineInput(input);
	string parameter; // file name
	string flag; // [-d]
	string unnecessaryParameter;
	commandLineInput >> parameter >> flag >> unnecessaryParameter;

	// IF INPUT FILE DO NOT EXIST
	AbstractFile* file = this->fileSystem->getFile(parameter);
	if (file == nullptr) {
		cout << "ds: cannot find given file" << endl << endl;
		return DISPLAYCOMMAND_CANNOT_FIND_FILE;
	}

	// IF THERE IS NOT NEEDED PARAMETER
	if (!unnecessaryParameter.empty()) {
		cout << "ds: too mant parameters" << endl;
		this->displayInfo();
		return DISPLACOMMAND_UNNECESSARY_PARAMETER;
	}

	// formatly display
	if (!parameter.empty() && flag.empty()) {
		AbstractFileVisitor* display = new BasicDisplayVisitor();
		this->fileSystem->getFile(parameter)->accept(display);
		cout << endl;
		return SUCCESS;
	}
	else if ( !parameter.empty() && (flag == "-d") ) {
		vector<char> currentFileContent = this->fileSystem->getFile(parameter)->read();
		string str(currentFileContent.begin(), currentFileContent.end());
		cout << str << endl;
		return SUCCESS;
	}	
	else {
		cout << "ds fail" << endl;
		this->displayInfo();
		return DISPLACOMMAND_UNKOWN;
	}
}


#include "CopyCommand.h"
#include "TouchCommand.h"
#include <iostream>
#include <sstream>

int CopyCommand::execute(std::string input)
{
	// IF INPUT IS EMPTY
	if (input.empty()) {
		cout << "cp: empty parameters" << endl;
		this->displayInfo();
		return COPYOMMAND_EMPTY_IPUT;
	}

	istringstream commandLineInput(input);
	string name1; // file1 name (being copied)
	string name2; // file2 name
	string unnecessaryParameter;
	commandLineInput >> name1 >> name2 >> unnecessaryParameter;

	// IF INPUT FILE1 DO NOT EXIST
	AbstractFile* file1 = this->fileSystem->getFile(name1);
	if (file1 == nullptr) {
		cout << "cp: cannot find given file" << endl << endl;
		return COPYOMMAND_CANNOT_FINE_FILE;
	}

	// IF INPUT FILE2 ALREADY EXIST
	string file2name;
	if (file1->isImg()) {file2name = name2 + ".img";}
	else {file2name = name2 + ".txt";}
	AbstractFile* file2 = this->fileSystem->getFile(name2);
	if (file2 != nullptr) {
		cout << "cp: new name overlaps with existing file" << endl << endl;
		return COPYOMMAND_NEW_NAME_ALREADY_EXIST;
	}

	// IF THERE IS NOT NEEDED PARAMETER
	if (!unnecessaryParameter.empty()) {
		cout << "cat: too mant parameters" << endl;
		this->displayInfo();
		return COPYOMMAND_UNNECESSARY_PARAMETER;
	}

	// COPY
	if (!name1.empty() && !name2.empty()) {

		// create file by prototype pattern
		AbstractFile* newFile = file1->clone(name2, file1);

		// add file to system
		int addFile = fileSystem->addFile(file2name, newFile);
		if (addFile == SUCCESS) {
			cout << "cp success" << endl << endl;
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
	else {
		cout << "cp failed" << endl;
		this->displayInfo();
		return COPYOMMAND_UNKOWN;
	}



}

void CopyCommand::displayInfo()
{
	cout << "enter 'cp <file_to_copy> <new_name_with_no_extension>' to create a duplicate of <file_to_copy>" << endl;
	cout << endl;
}

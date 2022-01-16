#include "RemoveCommand.h"
#include <iostream>


void RemoveCommand::displayInfo()
{
	cout << "enter 'rm <filename>' to remove the file from fileSystem" << endl;
	cout << endl;
}

int RemoveCommand::execute(string input)
{
	if (input.empty()) {
		cout << "rm: the file to remove wasn't not given" << endl;
		this->displayInfo();
		return outcome_removeommand::REMOVECOMMAND_EMPTY_INPUT;
	}
	else if (this->fileSystem->deleteFile(input) == SUCCESS) {
		cout << "rm: succes" << endl << endl;
		return SUCCESS;
	}
	else {
		cout << "rm: cannot find file" << endl << endl;
		return outcome_removeommand::REMOVECOMMAND_CREATION_FAILED;
	}
}

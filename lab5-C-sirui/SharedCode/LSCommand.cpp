#include "LSCommand.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include "MetadataDisplayVisitor.h"
#include "AbstractFileVisitor.h"

void LSCommand::displayInfo()
{
	cout << "eneter 'ls' to see files / enter 'ls - m' to see files and their metadata" << endl;
	cout << endl;
}

int LSCommand::execute(string input)
{
	if (input.empty()) {
		string names;
		for (auto const& i : this->fileSystem->getFileNames()) {
			names += i + " ";
		}
		istringstream fileNames(names);
		string print1;
		string print2;
		while (fileNames >> print1 ) {
			cout << setw(25) << setiosflags(ios::left) <<  print1;
			if (fileNames >> print2) {
				cout  <<print2 << endl;
			}
			else {
				cout << endl;
			}
		};
		cout << endl;
		return SUCCESS;
	}
	else if (input == "-m") {
		string names;
		for (auto const& i : this->fileSystem->getFileNames()) {
			names += i + " ";
		}
		istringstream fileNamess(names);
		string print3;
		AbstractFileVisitor* display = new MetadataDisplayVisitor;
		while (fileNamess >> print3) {
			AbstractFile* file = this->fileSystem->getFile(print3);
			file->accept(display);
			if (file->isPasswordProxy()) {
				cout << setw(10) << setiosflags(ios::left) << "encrypted";
			}
			cout << endl;
		};
		cout << endl;
		return SUCCESS;
	}
	else {
		cout << "ls failed" << endl << endl;
		return outcome_lscommand::LSCOMMAND_CREATION_FAILED;
	}
}

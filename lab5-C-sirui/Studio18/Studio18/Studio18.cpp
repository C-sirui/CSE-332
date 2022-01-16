// Studio18.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "..\..\\SharedCode\AbstractFileSystem.h"
#include "..\..\\SharedCode\AbstractFileFactory.h"
#include "..\..\\SharedCode\SimpleFileSystem.h"
#include "..\..\\SharedCode\SimpleFileFactory.h"
#include "..\..\\SharedCode\AbstractFile.h"


using namespace std;

int main() {
	AbstractFileFactory* a = new SimpleFileFactory;
	AbstractFileSystem* b = new SimpleFileSystem;
	AbstractFile* temp = a->createFile("1.txt");
	vector<char> content;
	content.push_back('1');
	content.push_back('2');
	content.push_back('3');
	temp->write(content);
	b->addFile("1.txt", temp);
	b->openFile("1.txt");
	temp->read();
	cout << temp->getName() << endl;
	b->deleteFile("1.txt");
	b->closeFile(temp);
	b->deleteFile("1.txt");

	
	return 0;
}



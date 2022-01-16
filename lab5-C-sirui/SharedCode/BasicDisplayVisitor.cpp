// definitions of basic display visitor here

#include "BasicDisplayVisitor.h"
#include <iostream>
using namespace std;

void BasicDisplayVisitor::visit_TextFile(AbstractFile* file)
{
	vector<char> contents = file->read();
	auto it = contents.begin();
	auto end = contents.end();
	while(it != end) {
		cout << *it;
		++it;
	}
	cout << endl;
}

void BasicDisplayVisitor::visit_ImageFile(AbstractFile* file)
{
	
	int size_int = file->getImageSize() - 48;
	vector<char> contents = file->read();
	for (int i = 0; i < size_int * size_int; i+=size_int) {
		for (int j = 0; j < size_int; ++j) {
			cout << contents[j + i];
		}
		cout << endl;
	}
}

// definitions of metadata visitor here

#include "MetadataDisplayVisitor.h"
#include "PasswordProxy.h"
#include <iostream>
#include <iomanip>
using namespace std;

class PasswordProxy;

void MetadataDisplayVisitor::visit_TextFile(AbstractFile* file)
{
	cout << setw(25) << setiosflags(ios::left) << file->getName();
	cout << setw(10) << setiosflags(ios::left) << "text";
	cout << setw(10) << setiosflags(ios::left) << file->getSize();

}

void MetadataDisplayVisitor::visit_ImageFile(AbstractFile* file)
{
	// unit test is doing ugly on this case
	// it doesn't accept formated display like
	// cout << file->getName() << " : has size" << file->getSize() << " and type: " << "text" << endl;
	cout << setw(25) << setiosflags(ios::left) << file->getName();
	cout << setw(10) << setiosflags(ios::left) << "image";
	cout << setw(10) << setiosflags(ios::left) << file->getSize();
}

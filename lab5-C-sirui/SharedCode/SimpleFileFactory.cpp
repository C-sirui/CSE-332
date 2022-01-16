// studio 18 - simple file factory definitions
#include "SimpleFileFactory.h"
#include "SimpleFileSystem.h"
#include "ImageFile.h"
#include "TextFile.h"
#include <string>




AbstractFile* SimpleFileFactory::createFile(string fileName)
{
	string textType = "txt";
	string imageType = "img";
	if (fileName.find(textType) != fileName.npos) {
		AbstractFile* temp = new TextFile(fileName);
		return temp;
	}
	else if (fileName.find(imageType) != fileName.npos) {
		AbstractFile* temp = new ImageFile(fileName);
		return temp;
	}
	else {
		return nullptr;
	}
}


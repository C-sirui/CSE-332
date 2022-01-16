#include "SimpleFileSystem.h"

#include <iostream>
// define methods of SimpleFileSystem class here

int SimpleFileSystem::addFile(string fileName, AbstractFile* file)
{
	if (files.find(fileName) != files.end()) {
		return FILE_NAME_ALREADY_EXIST;
	}
	if (openFiles.find(file) != openFiles.end()) {
		return FILE_ALREADY_EXIST;
	}

	if(file == nullptr){
		return FILE_NULLPOINTER;
	}

	files.emplace(fileName, file);
	return SUCCESS;
}

//int SimpleFileSystem::createFile(string fileName)
//{
//	string textType = "txt";
//	string imageType = "img";
//	if (files.find(fileName) != files.end()) {
//		return FILE_NAME_ALREADY_EXIST;
//	}
//	else if (fileName.find(textType) != fileName.npos) {
//		auto temp = new TextFile(fileName);
//		addFile(fileName, temp);
//		return SUCCESS;
//	}
//	else if (fileName.find(imageType) != fileName.npos) {
//		auto temp = new TextFile(fileName);
//		addFile(fileName, temp);
//		return SUCCESS;
//	}
//	else {
//		return FILE_EXTENTION_NOT_DEFINED;
//	}
//}

AbstractFile* SimpleFileSystem::openFile(string fileName)
{
	if (files.find(fileName) != files.end()){
		if (openFiles.find(files[fileName]) == openFiles.end()) {
			openFiles.insert(files[fileName]);
			return files[fileName];
		}
		else {
			return nullptr;
		}
	}
	else {
		return nullptr;
	}
}

int SimpleFileSystem::closeFile(AbstractFile* file)
{
	if (openFiles.find(file) != openFiles.end()) {
		openFiles.erase(file);
		return SUCCESS;
	}
	return FILE_NOT_OPEN;
}


int SimpleFileSystem::deleteFile(string fileName)
{
	if (files.find(fileName) != files.end()) {
		if (openFiles.find(files[fileName]) != openFiles.end()) {
			return FILE_OPEN_CANNOT_DELETE;
		}
		else
		{
			delete files[fileName];
			files.erase(fileName);
			return SUCCESS;
		}
	}
	else {
		return FILE_NOT_EXIST;
	}
}

set<string>  SimpleFileSystem::getFileNames()
{
	set<string> ans;
	for (auto const& file : this->files) {
		ans.insert(file.first);
	}
	return ans;
}

AbstractFile* SimpleFileSystem::getFile(string fileName)
{
	if (files.find(fileName) != files.end()) {
		return files[fileName];
	}
	else {
		return nullptr;
	}
}

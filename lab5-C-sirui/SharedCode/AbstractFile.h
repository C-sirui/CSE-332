#pragma once
// Define base class abstract file system, no cpp file
// Define return values

#ifndef ABSTRACTFILE_H
#define ABSTRACTFILE_H

#include <string>
#include <vector>


using namespace std;

class AbstractFileVisitor;

class AbstractFile{
public:
	virtual int write(vector<char>) = 0;
	virtual int append(vector<char>) = 0;
	virtual unsigned int getSize() = 0;
	virtual string getName() = 0;
	virtual vector<char> read() = 0;
	virtual ~AbstractFile() = default;
	virtual void accept(AbstractFileVisitor*) = 0;
	virtual bool isPasswordProxy() = 0;
	virtual bool isImg() = 0;
	virtual bool isText() = 0;
	virtual unsigned int getImageSize() = 0; // only for img since it has two sizes, one the NxN size, the other contents.size()
	virtual vector<char> getContent() = 0; 
	virtual AbstractFile* clone(string, AbstractFile*) = 0;
	virtual AbstractFile* getgetProtectedFile() = 0; // only for passwordProxy, protected
	virtual string getPassword() = 0; // only for passwordProxy, protected
};



enum outcome {
	SUCCESS = 0,
	FAIL_TO_READ = -1,
	NOT_SUPPORTED = -1000,
	CLONE_ITSELF_ERROR = -1101,
};

enum outcome_catcommand {
	CATCOMMAND_CANNOT_FIND_FILE = -403,
	CATCOMMAND_IMG_CANNOT_APPEND = -401,
	CATCOMMAND_EMPTY_IMPUT = -402,
	CATCOMMAND_UNNECESSARY_PARAMETER = -404,
	CATCOMMAND_IMG_WRITE_FAIL = -405,
	CATCOMMAND_UNKOWN = -406,
};

enum outcome_commandprompt {
	FILE_EXIST_IN_MAP = -111,
	QUIT_FROM_COMMAND_LINE = -222,
	COMMAND_FAIL = -444,
};

enum outcome_displaycommand {
	DISPLAYCOMMAND_CANNOT_FIND_FILE = -503,
	DISPLAYCOMMAND_EMPTY_INPUT = -502,
	DISPLACOMMAND_UNNECESSARY_PARAMETER = -504,
	DISPLACOMMAND_UNKOWN = -501,
};

enum outcome_lscommand {
	LSCOMMAND_CREATION_FAILED = -999,
};

enum outcome_touchcommand {
	TOUCHCOMMAND_CREATION_FAILED = -333,
	TOUCHCOMMAND_EMPTY_IPUT = -429,
	TOUCHCOMMAND_FILE_ALREADY_EXIST = -371,
	TOUCHCOMMAND_UNNECESSARY_PARAMETER = -381,
};

enum outcome_copycommand {
	COPYOMMAND_CANNOT_FINE_FILE = -604,
	COPYOMMAND_EMPTY_IPUT = -601,
	COPYOMMAND_FILE_ALREADY_EXIST = -602,
	COPYOMMAND_UNNECESSARY_PARAMETER = -603,
	COPYOMMAND_NEW_NAME_ALREADY_EXIST = -605,
	COPYOMMAND_UNKOWN = -606,
};

enum outcome_simpleFile {
	FILE_ALREADY_EXIST = -3,
	FILE_NULLPOINTER = -4,
	FILE_NAME_ALREADY_EXIST = -5,
	FILE_EXTENTION_NOT_DEFINED = -6,
	FILE_NOT_EXIST = -7,
	FILE_NOT_OPEN = -8,
	FILE_OPEN_CANNOT_DELETE = -9,

};

enum outcome_image {
	INVALID_INPUT = -1,
	APPEND_NOT_SUPPORTED = -2,
};

enum outcomes_PasswordProxy {
	WRONG_PASSWORD = -101,
};

enum outcome_removeommand {
	REMOVECOMMAND_EMPTY_INPUT = -192,
	REMOVECOMMAND_CREATION_FAILED = -361,
};

enum outcome_macrocommand {
	NOT_ALL_SUCCESS = -909,
};

#endif // !ABSTRACTFILE_H

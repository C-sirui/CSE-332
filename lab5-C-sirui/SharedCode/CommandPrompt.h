#pragma once

#ifndef COMMANDPROMPT_H
#define COMMANDPROMPT_H

#include <map>
#include <iterator>
#include "AbstractCommand.h"



using namespace std;

class CommandPrompt {
private:
	map<string, AbstractCommand*> map;
	AbstractFileSystem* fileSystem;
	AbstractFileFactory* fileFactory;
	bool printUsage = true;
protected:
	std::string prompt();
public:
	void listCommands(); //  there is not need to set it protected since MacroCommand will have to access it
	CommandPrompt() : fileSystem(nullptr), fileFactory(nullptr) {};
	void setFileSystem(AbstractFileSystem*);
	void setFileFactory(AbstractFileFactory*);
	int addCommand(std::string, AbstractCommand*);
	int run();
	// helper
	void runCommand(string, string);
	std::map<string, AbstractCommand*> getMap(); // MacroCommand will use it
};

#endif // !COMMANDPROMPT+H



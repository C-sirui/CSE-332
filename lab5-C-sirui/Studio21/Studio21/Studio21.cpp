// Studio21.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "CommandPrompt.h"
#include <iostream>
#include "SimpleFileSystem.h"
#include "SimpleFileFactory.h"
#include "TouchCommand.h"
#include <string>
int main()
{
	SimpleFileSystem* fileSystem = new SimpleFileSystem();
	SimpleFileFactory* fileFactory = new SimpleFileFactory();
	AbstractCommand* touchCommand = new TouchCommand(fileSystem, fileFactory);

	CommandPrompt user;
	user.setFileFactory(fileFactory);
	user.setFileSystem(fileSystem);
	string touch = "touch";
	user.addCommand(touch, touchCommand);
	user.run();
	

	return 0;
}


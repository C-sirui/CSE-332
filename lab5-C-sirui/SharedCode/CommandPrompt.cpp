#include "CommandPrompt.h"
#include <iostream>
#include <sstream>

// HELPER FUNCTION
// run a command in map, if not found print not found, if command fail print command fail
void CommandPrompt::runCommand(string command, string parameter) {
	auto it = this->map.find(command);
	if (it != this->map.end())
	{
		if (it->second->execute(parameter) != SUCCESS)
		{
			// NO PRINTS, ERROR MESSAGE SHOULD BE HANDLED BY COMMAND ITSELF
		}
	}
	else {
		cout << "Command Doesn't Exist" << endl << endl;
	}
}

map<string, AbstractCommand*> CommandPrompt::getMap()
{
	return this->map;
}

// sets the AbstractFileSystem pointer member variable equal to the parameter passed to this method
void CommandPrompt::setFileSystem(AbstractFileSystem* input)
{
	fileSystem = input;
}

// sets the AbstractFileFactory pointer
void CommandPrompt::setFileFactory(AbstractFileFactory* input)
{
	fileFactory = input;
}

// nserts the parameters passed to this function as a pair into the map of commands, 
// returns success if the insertion was successful, returns a non zero value otherwise.
int CommandPrompt::addCommand(std::string input_string, AbstractCommand* input_command)
{
	if ( this->map.insert( pair<string, AbstractCommand*>(input_string, input_command) ).second ) {
		return SUCCESS;
	}
	else {
		return FILE_EXIST_IN_MAP;
	}
}

// iterates over each command in the map and prints the command¡¯s name
void CommandPrompt::listCommands()
{
	for (auto const& command : this->map) {
		cout << command.first << endl;
	}
}

// prompt user for input
std::string CommandPrompt::prompt()
{
	if (this->printUsage) {
		cout << "Enter a command, q to quit, help for a list of commands, \
or help followed by a command name for more information about that command. DO NOT INCLUDE EMPTY SPACES BEFORE COMMAND" << endl;

		this->printUsage = false;
	}
	cout << "lab5 $ ";
	string command;	
	getline(cin, command);
	
	return command;
}

// run prompt forever
int CommandPrompt::run()
{
	while (true)
	{
		string command = this->prompt();

		//// EMPTY INPUT FROPM COMMAND LINE
		//if (command.empty()) {

		//}

		// QUIT
		if (command == "q")
		{
			return QUIT_FROM_COMMAND_LINE;
		}

		// HELP
		else if (command == "help")
		{
			this->listCommands();
		}

		// SINGLE COMMAND
		else if (command.find(" ") == string::npos && !command.empty()) // " " wasn't found
		{	
			string empty;
			runCommand(command, empty);
		}

		// COMPOUNEDED COMMAND
		else if (command.find(" ") != string::npos && !command.empty()) // " " was found
		{
			istringstream input(command);
			string first_word;
			input >> first_word;

			// HELP + COMMAND: RUN displayInfo() OF COMMAND
			if(first_word == "help")
			{
				string second_word;
				input >> second_word;
				auto it = this->map.find(second_word);
				if (it != this->map.end())
				{
					it->second->displayInfo();
				}
				else {
					cout << "Command Doesn't Exist" << endl << endl;
				}
			}

			// COMMAND + PARAMETER: RUN 
			else if (first_word != "help")
			{
				string parameter = input.str();
				int length = first_word.end() - first_word.begin() + 1;
				parameter.replace(parameter.begin(), parameter.begin() + length, "");
				//cout << "two input: " << parameter << " hhh" << endl;
				runCommand(first_word, parameter);
			}
		}
	}
	return 0;
}

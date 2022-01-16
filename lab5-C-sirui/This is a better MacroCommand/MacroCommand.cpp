#include "MacroCommand.h"
#include <iostream>	
#include <sstream>

void MacroCommand::displayInfo()
{
	cout << "enter 'mc' + commands seperated by ';', the command will execute by order, no matter previous command success or not" << endl;
	cout << "for ex: 'mc touch txt; cat txt; ds txt' " << endl;
	cout << endl;
}

int MacroCommand::execute(string Userinput)
{
	vector<string> rawCommands = this->parsingStrategy->parse(Userinput);

	for (string rawCommand : rawCommands) {

		string command = rawCommand;

		// QUIT
		if (command == "q")
		{
			return QUIT_FROM_COMMAND_LINE;
		}

		// HELP
		else if (command == "help")
		{
			this->commandPrompt->listCommands();
		}

		// SINGLE COMMAND
		else if (command.find(" ") == string::npos && !command.empty()) // " " wasn't found
		{
			string empty;
			this->commandPrompt->runCommand(command, empty);
		}

		// COMPOUNEDED COMMAND
		else if (command.find(" ") != string::npos && !command.empty()) // " " was found
		{
			istringstream input(command);
			string first_word;
			input >> first_word;

			// HELP + COMMAND: RUN displayInfo() OF COMMAND
			if (first_word == "help")
			{
				string second_word;
				input >> second_word;
				auto it = this->commandPrompt->getMap().find(second_word);
				if (it != this->commandPrompt->getMap().end())
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
				this->commandPrompt->runCommand(first_word, parameter);
			}
		}
	}
}

void MacroCommand::addCommand(AbstractCommand* input)
{
	this->commandList.push_back(input);
}

void MacroCommand::setParseStrategy(AbstractParsingStrategy* input)
{
	this->parsingStrategy = input;
}

void MacroCommand::setCommandPrompt(CommandPrompt* user)
{
	this->commandPrompt = user;
}
	
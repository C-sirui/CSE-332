#include "MacroCommand.h"
#include <iostream>	
#include <sstream>

void MacroCommand::displayInfo()
{
	cout << "enter 'mc' + commands seperated by ';', the command will execute by order, no matter previous command success or not" << endl;
	cout << "for ex: 'mc touch txt; cat txt; ds txt' " << endl;
	cout << endl;
}

int MacroCommand::execute(string input)
{
	vector<string> parameters = this->parsingStrategy->parse(input);

	int count = 0;
	//int successCount = 0;
	//int expectedSuccessCount = parameters.size();
	for (const auto& command : this->commandList) {
		if (command->execute(parameters[count]) != SUCCESS) {
			return NOT_ALL_SUCCESS;
		}
		count++;
	}
	return SUCCESS;

	//if (successCount == expectedSuccessCount) {
	//	return SUCCESS;
	//}
	//else{
	//	NOT_ALL_SUCCESS;
	//}
	
}

void MacroCommand::addCommand(AbstractCommand* input)
{
	this->commandList.push_back(input);
}

void MacroCommand::setParseStrategy(AbstractParsingStrategy* input)
{
	this->parsingStrategy = input;
}


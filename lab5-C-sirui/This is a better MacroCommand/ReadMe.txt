	// macro command set up: this is a lot better, you don't need to add AbsractCommand, just adhere to the following usage
	// 
	// enter 'mc' + 'commands seperated by ;', the command will execute by order, no matter previous command success or not
	// Ex: mc touch txt; cat txt; ds txt
	CommandPrompt user;
	MacroParing* macroParse = new MacroParing();
	MacroCommand* macroCommand = new MacroCommand(fileSystem);
	macroCommand->setCommandPrompt(&user);
	macroCommand->setParseStrategy(macroParse);

	AbstractParsingStrategy* renameParse = new RenameParsingStrategy();
	MacroCommand* renameCommand = new MacroCommand(fileSystem);
	renameCommand->setCommandPrompt(&user);
	renameCommand->setParseStrategy(renameParse);
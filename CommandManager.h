#pragma once
#include "ICommand.h"
#include <list>

class CommandManager {
private:
	std::list<I_Command*> cmds;
	bool lock = false;
	CommandManager() { }
	static CommandManager* _instance;
public:
	static CommandManager* getInstance();
	void Registry(I_Command* command);
	void Undo();
};

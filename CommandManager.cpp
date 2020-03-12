#include "stdafx.h"
#include "CommandManager.h"

CommandManager* CommandManager::_instance = 0;

CommandManager* CommandManager::getInstance() {
	if (_instance == 0) {
		_instance = new CommandManager();
	}
	return _instance;
}


void CommandManager::Registry(I_Command* command) {
	if (lock) {
		delete command;	
		return;
	}
	cmds.push_back(command);
}

void CommandManager::Undo(){
	if (cmds.size() > 1) {
		cmds.pop_back();
		lock = true;
		for (auto c : cmds) {
			c->Execute();
		}
		lock = false;
	}
}

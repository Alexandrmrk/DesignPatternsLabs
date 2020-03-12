#include "stdafx.h"
#include"ACommand.h"
#include"CommandManager.h"

void ACommand::Execute() {
	doExecute();
	CommandManager::getInstance()->Registry(this->clone());
}
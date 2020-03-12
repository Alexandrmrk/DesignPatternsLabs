#pragma once
#include "ICommand.h"

class ACommand : public I_Command {
public:
	void Execute();
protected:
	virtual void doExecute() = 0;
};
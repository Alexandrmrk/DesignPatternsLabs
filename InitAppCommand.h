#pragma once
#include "Acommand.h"
#include "IMatrix.h"
class InitAppCommand : public ACommand {
public:
	InitAppCommand(IMatrix* m) : _matrix(m) {    }
private:
	IMatrix* _matrix;
protected:
	void doExecute();
	I_Command* clone();

};
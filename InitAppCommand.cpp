#include"stdafx.h"
#include"InitAppCommand.h"

void InitAppCommand::doExecute()
{
	_matrix->Iterate([this](int r, int c, int v){
		this->_matrix->SetValue(r, c, 0);
	});
}


I_Command* InitAppCommand::clone() {
	return new InitAppCommand(_matrix);
}
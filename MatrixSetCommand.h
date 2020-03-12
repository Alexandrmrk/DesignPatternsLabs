#pragma once
#include "ACommand.h"
#include "IMatrix.h"
#include <memory>
class MatrixSetCommand : public ACommand {
public:
	MatrixSetCommand(IMatrix* m, int row, int col, int val);
private:
	IMatrix* _matrix;
	int _row;
	int _col;
	int _value;
protected:
	void doExecute();
	I_Command* clone();

};
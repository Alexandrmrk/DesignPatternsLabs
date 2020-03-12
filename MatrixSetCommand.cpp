#include"stdafx.h"
#include"MatrixSetCommand.h"
MatrixSetCommand::MatrixSetCommand(IMatrix* m, int row, int col, int val){
	_matrix = m;
	_row = row;
	_col = col;
	_value = val;

}

void MatrixSetCommand::doExecute() {
	_matrix->SetValue(_row, _col, _value);
}

I_Command* MatrixSetCommand::clone() {
	return new MatrixSetCommand(_matrix, _row, _col, _value);
}
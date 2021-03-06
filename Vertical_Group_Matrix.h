#pragma once
#include"A_Group_Matrix.h"
class Vertical_Group_Matrix :public A_Group_Matrix {
public:
	Vertical_Group_Matrix() = default;
	Vertical_Group_Matrix(std::vector<AMatrix*> list) {
		this->_list = list;
		this->_size = list.size();
	}
	virtual int GetRows();
	virtual int GetCols();
	virtual int GetValue(int row, int col);
	virtual void SetValue(int row, int col, int value);
	virtual void Draw();
	virtual void Iterate(std::function<void(int, int, int)> f);
};
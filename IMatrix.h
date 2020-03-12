#pragma once
#include<vector>
#include"IDrawable.h"
#include"IIterable.h"
class IMatrix:public IIterable{
public:
	virtual int GetRows() = 0;
	virtual int GetCols() = 0;
	virtual int GetValue(int row, int col) = 0;
	virtual void SetValue(int row, int col,int value) = 0;
};
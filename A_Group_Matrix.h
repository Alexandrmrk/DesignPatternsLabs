#pragma once
#include"AMatrix.h"
class A_Group_Matrix :public AMatrix {
protected:
	std::vector<AMatrix*> _list;
	int _size;
public:
	virtual int GetRows()=0;
	virtual int GetCols()=0;
	virtual int GetValue(int row, int col)=0;
	virtual void SetValue(int row, int col, int value)=0;
	virtual void SetDrawer(IDrawer *d);
	virtual void Draw()=0;
	virtual void Iterate(std::function<void(int, int, int)> f)=0;
	virtual void Add_Matrix(AMatrix* m);
};
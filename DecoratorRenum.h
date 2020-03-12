#pragma once
#include "VectorN.h"
#include "AMatrix.h"
#include "IDrawer.h"

class DecoratorRenum :public AMatrix{
private:
	AMatrix* m;

	int row_i;
	int row_j;
	int col_i;
	int col_j;

public:
	DecoratorRenum(AMatrix* m) {
		this->m = m;
		
		this->row_i = 0;
		this->row_j = 0;
		this->col_i = 0;
		this->col_j = 0;
	}
	~DecoratorRenum() { }

	virtual int GetRows();
	virtual int GetCols();
	virtual int GetValue(int row, int col);
	virtual void SetValue(int row, int col, int value);
	virtual void SetDrawer(IDrawer *d);
	virtual void Draw();
	virtual AMatrix* GetComponent();
	virtual void Iterate(std::function<void(int, int, int)> f);
	void RenumRows(int row_i, int row_j);
	void RenumCols(int col_i, int col_j);

};
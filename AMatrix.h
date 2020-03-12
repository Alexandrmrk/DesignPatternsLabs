#pragma once
#include"IMatrix.h"
#include"IVector.h"
#include<iostream>
#include"IVectorFactory.h"

 class AMatrix : public IMatrix,public IDrawable {
private:
	std::vector<IVector*> myMatrix;
	IDrawer* drawer;

protected:
	AMatrix() = default;

	virtual void DrawBorder(int rows, int cols);
	virtual void DrawItem(int row, int col, int val);

public:
	
	AMatrix(int rows, int cols, IVectorFactory* Vector, IDrawer* d) {
		this->myMatrix.resize(rows);
		for (long i = 0; i < rows; ++i)
		
			this->myMatrix[i] = Vector->CreateVector(cols);
		delete Vector;
		this->drawer = d;
		
	}

	~AMatrix() {
		for (int i = 0; i < (int)myMatrix.size(); i++) {
			delete myMatrix[i];
		}
	}

	virtual int GetRows();
	virtual int GetCols();
	virtual int GetValue(int row, int col);
	virtual void SetValue(int row, int col, int value);
	virtual void SetDrawer(IDrawer *d);
	virtual void Draw();
    virtual AMatrix* GetComponent();

};
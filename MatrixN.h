#pragma once
#include"AMatrix.h"
#include"VectorFactoryN.h"
class MatrixN : public AMatrix {
public:
	MatrixN() = default;
	MatrixN(int rows, int cols, IDrawer* d) : AMatrix(rows, cols, new VectorFactoryN(), d) {}
	virtual void Iterate(std::function<void(int, int, int)> f);
	
	
};


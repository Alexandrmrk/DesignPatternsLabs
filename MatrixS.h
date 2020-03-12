#pragma once
#include"AMatrix.h"
#include"VectorFactoryS.h"
class MatrixS : public AMatrix {
public:
	MatrixS() = default;
	MatrixS(int rows, int cols, IDrawer* d) : AMatrix(rows, cols, new VectorFactoryS(), d) {}
	virtual void Iterate(std::function<void(int, int, int)> f);
	
};
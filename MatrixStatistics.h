#pragma once
#include"AMatrix.h"

class MatrixStatistics {
	private:
		IMatrix* matr;
		
public:
	MatrixStatistics(IMatrix* const matrix);
	long sum();
	long notZeroCount();
	int maxValue();
	double average();
};
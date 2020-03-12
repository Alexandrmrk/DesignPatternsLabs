#pragma once
#include "AMatrix.h"

class MatrixInitiator {
public:
	static void fillMatrix(IMatrix* const matrix, long nonZeroCount, long maxValue);
};

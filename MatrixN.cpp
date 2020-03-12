#include "stdafx.h"
#include"MatrixN.h"
#include"VectorN.h"
#include"AMatrix.h"


void MatrixN::Iterate(std::function<void(int, int, int)> f) {
	int rows = this->GetRows();
	int cols = this->GetCols();

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			f(i, j, this->GetValue(i, j));
		}
	}
}
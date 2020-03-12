#include "stdafx.h"
#include"MatrixS.h"
#include"VectorS.h"


void MatrixS::Iterate(std::function<void(int, int, int)> f) {
	int rows = this->GetRows();
	int cols = this->GetCols();
	
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (GetValue(i, j)) {
				f(i, j, this->GetValue(i, j));
			}
			
		}
	}
}
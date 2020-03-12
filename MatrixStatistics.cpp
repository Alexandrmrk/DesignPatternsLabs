#include "stdafx.h"
#include "MatrixStatistics.h"

MatrixStatistics::MatrixStatistics(IMatrix *const matrix) {
	matr = matrix;
}

long MatrixStatistics::sum(){
	
	long sum=0;
	long rows = matr->GetRows();
	long cols = matr->GetCols();
	for (long i = 0; i < rows; ++i) {
		for (long j = 0; j < cols; ++j) {
			int item = matr->GetValue(i, j);
			sum += item;
		}
	}
	return sum;
}


long MatrixStatistics::notZeroCount(){
	long _notZeroCount = 0;
	long rows = matr->GetRows();
	long cols = matr->GetCols();
	for (long i = 0; i < rows; ++i) {
		for (long j = 0; j < cols; ++j) {
			int item = matr->GetValue(i, j);
			if (item) _notZeroCount++;
		}
	}
	
	return _notZeroCount;
}

int MatrixStatistics::maxValue(){
	int _maxValue = 0;
	long rows = matr->GetRows();
	long cols = matr->GetCols();
	for (long i = 0; i < rows; ++i) {
		for (long j = 0; j < cols; ++j) {
			int item = matr->GetValue(i, j);
			_maxValue = item > _maxValue ? item : _maxValue;
		}
	}
	
	return _maxValue;
}

double MatrixStatistics::average(){
	double _average = 0.0;
	_average = this->sum() / (matr->GetRows()* matr->GetCols());
	return _average;
}

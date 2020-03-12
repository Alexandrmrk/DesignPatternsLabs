#include "stdafx.h"
#include"Horizontal_Group_Matrix.h"

int Horizontal_Group_Matrix::GetRows() {
	int maxrows = 0;
	for (long i = 0; i < _size; ++i) {
		int rows = _list[i]->GetRows();
		maxrows = rows > maxrows ? rows : maxrows;
	}
	return maxrows;
}

int Horizontal_Group_Matrix::GetCols() {
	int cols = 0;
	for (long i = 0; i < _size; ++i) {
		cols += _list[i]->GetCols();
	}
	return cols;
}

int Horizontal_Group_Matrix::GetValue(int row, int col) {
	int offset = 0;
	for (int i = 0; i < _size; i++) {
		if (col < offset + _list[i]->GetCols()) {
			if (row < _list[i]->GetRows()) {
				return _list[i]->GetValue(row , col - offset);
			}
			else {
				return 0;
			}
		}
		offset += _list[i]->GetCols();
	}
	return 0;
}

void Horizontal_Group_Matrix::SetValue(int row, int col, int value) {
	int offset = 0;
	for (int i = 0; i < _size; i++) {
		if (col < offset + _list[i]->GetCols()) {
			if (row < _list[i]->GetRows()) {
			 _list[i]->SetValue(row, col - offset,value);
			}
			else {
				return ;
			}
		}
		offset += _list[i]->GetCols();
	}
	return ;
}

void Horizontal_Group_Matrix::Draw() {
	DrawBorder(GetRows(), GetCols());
	int col_group = 0;
	
	for (int i = 0; i < _size; i++) {

		_list[i]->Iterate([this, i, col_group](int row, int col, int val) {

			DrawItem(row, col + col_group, val);

		});
		col_group += _list[i]->GetCols();
	}

}

void  Horizontal_Group_Matrix::Iterate(std::function<void(int, int, int)> f) {
	int col_group = 0;

	for (int i = 0; i < _size; i++) {

		_list[i]->Iterate([this, i, col_group, f](int row, int col, int val) {

			f(row, col + col_group, val);

		});
		col_group += _list[i]->GetCols();
	}
}



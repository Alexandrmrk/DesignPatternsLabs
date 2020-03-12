#include "stdafx.h"
#include"Vertical_Group_Matrix.h"

int Vertical_Group_Matrix::GetRows() {
	int rows = 0;
	for (long i = 0; i <_size; ++i) {
		rows += _list[i]->GetRows();
	}
	return rows;
}

int Vertical_Group_Matrix::GetCols() {
	int maxcols = 0;
	for (long i = 0; i < _size; ++i) {
		int cols = _list[i]->GetCols();
		maxcols = cols > maxcols ? cols : maxcols;
	}
	return maxcols;
}

int Vertical_Group_Matrix::GetValue(int row, int col) {
	int offset = 0;
	for (int i = 0; i < _size; i++) {
		
		if (row < offset + _list[i]->GetRows()) {
			if (col < _list[i]->GetCols()) {
				return _list[i]->GetValue(row - offset, col);
			}
			else {
				return 0;
			}
		}
		offset += _list[i]->GetRows();
	}
	return 0;
}

void Vertical_Group_Matrix::SetValue(int row, int col, int value) {
	int offset = 0;
	for (int i = 0; i < _size; i++) {

		if (row < offset + _list[i]->GetRows()) {
			if (col < _list[i]->GetCols()) {
				_list[i]->SetValue(row - offset, col,value);
			}
			else {
				return;
			}
		}

		offset += _list[i]->GetRows();
	}
	return;
}

void Vertical_Group_Matrix::Draw() {
	DrawBorder(GetRows(), GetCols());
	int row_group = 0;

	for (int i = 0; i < _size; i++) {
			
		_list[i]->Iterate([this,i, row_group](int row, int col, int val) {
		
				DrawItem(row + row_group, col, val);
			
		});
		row_group += _list[i]->GetRows();
	}
}

void  Vertical_Group_Matrix::Iterate(std::function<void(int, int, int)> f) {
	int row_group = 0;

	for (int i = 0; i < _size; i++) {

		_list[i]->Iterate([this, i, row_group, f](int row, int col, int val) {

			f(row + row_group, col, val);

		});
		row_group += _list[i]->GetRows();
	}

}

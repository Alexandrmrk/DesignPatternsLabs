#include "stdafx.h"
#include"DecoratorRenum.h"


int DecoratorRenum::GetRows() {
	return m->GetRows();
}

int DecoratorRenum::GetCols() {
	return m->GetCols();
}

int DecoratorRenum::GetValue(int row, int col) {
	if (row == row_i) {
		row = row_j;
	}
	else if (row == row_j) {
		row = row_i;
	}

	if (col == col_i) {
		col = col_j;
	}
	else if (col == col_j) {
		col = col_i;
	}
	return m->GetValue(row, col);
}

void DecoratorRenum::SetValue(int row, int col, int value) {
	if (row == row_i) {
		row = row_j;
	}
	else if (row == row_j) {
		row = row_i;
	}

	if (col == col_i) {
		col = col_j;
	}
	else if (col == col_j) {
		col = col_i;
	}
	return m->SetValue(row, col,value);
}

void DecoratorRenum::SetDrawer(IDrawer *d) {

	AMatrix::SetDrawer(d);
	m->SetDrawer(d);

}

void DecoratorRenum::Draw() {
	
	DrawBorder(GetRows(), GetCols());

	m->Iterate([this](int row, int col, int val){

		if (row == row_i) {
			row = row_j;
		}
		else if (row == row_j) {
			row = row_i;
		}

		if (col == col_i) {
			col = col_j;
		}
		else if (col == col_j) {
			col = col_i;
		}
		DrawItem(row, col, val);
	});

}

void DecoratorRenum::RenumRows(int row_i, int row_j) {
	if ((row_i < GetRows()) || (row_j < GetRows())) {
		this->row_i = row_i;
		this->row_j = row_j;
	}
	else {
		return;
	}

}

void DecoratorRenum::RenumCols(int col_i, int col_j) {
	if ((col_i < GetCols()) || (col_j < GetCols())) {
		this->col_i = col_i;
		this->col_j = col_j;
	}
	else {
		return;
	}
}

AMatrix* DecoratorRenum::GetComponent() {
	return m->GetComponent();
}

void  DecoratorRenum::Iterate(std::function<void(int, int, int)> f){
	m->Iterate([this,f](int row, int col, int val) {

		if (row == row_i) {
			row = row_j;
		}
		else if (row == row_j) {
			row = row_i;
		}

		if (col == col_i) {
			col = col_j;
		}
		else if (col == col_j) {
			col = col_i;
		}
		f(row, col, val); });
	};
	

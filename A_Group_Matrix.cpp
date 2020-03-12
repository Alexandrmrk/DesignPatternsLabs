#include "stdafx.h"
#include"A_Group_Matrix.h"

void A_Group_Matrix::SetDrawer(IDrawer *d) {
	AMatrix::SetDrawer(d);
	for (int i = 0; i < _size; i++) {
		_list[i]->SetDrawer(d);
	}
}

void A_Group_Matrix::Add_Matrix(AMatrix* m) {
	this->_list.push_back(m);
	this->_size = _list.size();
}

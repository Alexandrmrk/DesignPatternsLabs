#include "stdafx.h"
#include"AMatrix.h"

int AMatrix::GetRows() {
	return myMatrix.size();
}

int AMatrix::GetCols() {
	return myMatrix[0]->GetSize();
}

int AMatrix::GetValue(int row, int col) {
	return myMatrix[row]->GetValue(col);
}

void AMatrix::SetValue(int row, int col, int value) {
	myMatrix[row]->SetValue(col, value);
}

void AMatrix::SetDrawer(IDrawer *d) {
	this->drawer = d;
}


AMatrix* AMatrix::GetComponent() {
	return this;
}

void AMatrix::DrawBorder(int rows, int cols) {
	this->drawer->DrawBorder(rows, cols);
}

void AMatrix::DrawItem(int row, int col,int val) {
	this->drawer->DrawItem(row, col, val);
}
void AMatrix::Draw() {

	DrawBorder(GetRows(), GetCols());
	Iterate([&](int row, int col, int val) { DrawItem(row, col, val); });
}

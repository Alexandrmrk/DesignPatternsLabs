#include "stdafx.h"
#include"VectorN.h"

VectorN::VectorN(int size) {
	myVector.resize(size);
}

int VectorN::GetSize() {
	return myVector.size();
}

int VectorN::GetValue(int pos) {
		return myVector[pos];
} 

void VectorN::SetValue(int pos, int value) {
	myVector[pos] = value;
}
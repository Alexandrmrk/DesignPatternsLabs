#pragma once
#include"IVector.h"
#include<vector>

class VectorN : public IVector {
private:
	std::vector<int> myVector; 
public:
	VectorN() = default;
	VectorN(int size);
	virtual int GetSize();
	virtual int GetValue(int pos);
	virtual void SetValue(int pos, int value);
};
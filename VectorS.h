#pragma once
#include"IVector.h"
#include<map>
class VectorS : public IVector {
private:
	std::map<int,int> myVector;
	int size;
public:
	VectorS() = default;
	VectorS(int size);
	virtual int GetSize();
	virtual int GetValue(int pos);
	virtual void SetValue(int pos, int value);
	
	
};
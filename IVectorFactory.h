#pragma once
#include"IVector.h"
class  IVectorFactory {
public:
	virtual IVector* CreateVector(int cols) = 0;
};
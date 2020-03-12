#pragma once
#include"IVectorFactory.h"
#include"VectorS.h"

class VectorFactoryS :public IVectorFactory {
	virtual IVector* CreateVector(int cols) {
		return new VectorS(cols);
	}
};
#pragma once
#include"IVectorFactory.h"
#include"VectorN.h"

class VectorFactoryN :public IVectorFactory {
	virtual IVector* CreateVector(int cols) {
		return new VectorN(cols);
	}
};
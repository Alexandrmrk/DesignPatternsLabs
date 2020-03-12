#pragma once
#include"IVector.h"
#include<iostream>

class IVector {
public:
	virtual int GetSize() = 0 ;
	virtual int GetValue(int pos) = 0;
	virtual void SetValue(int pos, int value) = 0;
};
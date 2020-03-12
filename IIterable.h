#pragma once

#include<functional>
#include<iostream>
class IIterable {
public:
	virtual void Iterate(std::function<void(int, int, int)> f = NULL) = 0;
};
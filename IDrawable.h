#pragma once
#include"IDrawer.h"
class IDrawable {
public:
	virtual void SetDrawer(IDrawer *d) = 0;
	virtual void Draw() = 0;
};
#pragma once
#include "IDrawer.h"
class ADrawer :public IDrawer {
protected:
	bool ShowBorder;
public:
	 ADrawer() { ShowBorder = false; }
	 void SetShowBorder(bool p);
};
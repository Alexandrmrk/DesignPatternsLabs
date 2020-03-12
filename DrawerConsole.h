#pragma once
#include"ADrawer.h"

class DrawerConsole : public ADrawer {
public:
	void DrawBorder(int rows,int cols);
	void DrawItem(int row, int col, int val);
};


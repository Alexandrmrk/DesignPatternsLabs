#pragma once
#include<iostream>
#include <stdio.h>
#include <Windows.h>

class IDrawer {
public:
	virtual void DrawBorder(int rows,int cols) = 0;
	virtual void DrawItem(int row,int col,int val) = 0;
};
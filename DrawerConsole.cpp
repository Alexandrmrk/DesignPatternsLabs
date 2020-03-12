#include "stdafx.h"
#include"DrawerConsole.h"
#include <iomanip>

void DrawerConsole::DrawBorder(int rows, int cols) {
	system("cls");
	if (!ShowBorder) {
		return;
	}
	else {
		std::cout << " ";
		for (int i = 0; i <= rows; i++) {
			for (int j = 0; j < cols; j++) {
				std::cout << "+------";
			}

			std::cout << "+";
			std::cout << "\n";
			if (i != rows) {
				for (int j = 0; j < cols; j++) {
					std::cout << " |";
					std::cout << std::setw(7);
				}

				std::cout << " |";
				std::cout << "\n";
				std::cout << " ";
			}
		}
	}
}

void DrawerConsole::DrawItem(int row, int col, int val) {
	
	// ���������� ����������� ���������
	COORD position;						
	// ��������� ����������� ���������� ������������ ������
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	
	// ��������� ���������� X
	if (col != 0) {
		position.X = 7 * (col + 1) - 5;
	}
	else {
		position.X = 2;
	}

	// ��������� ���������� Y
	position.Y = 2*(row)+1;	

	// ����������� ������� �� �������� �����������
	SetConsoleCursorPosition(hConsole, position);		
	std::cout << val;
	std::cout << "\n";
}


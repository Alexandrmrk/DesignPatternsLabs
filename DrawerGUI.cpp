#include "stdafx.h"
#include"DrawerGUI.h"

void DrawerGUI::DrawBorder(int rows, int cols) {
	if (!ShowBorder) {
		return;
	}
	else {
		CClientDC dc(AfxGetApp()->m_pMainWnd);

		LOGBRUSH logBrush;
		logBrush.lbStyle = BS_HOLLOW;
		
		CBrush brush;
		brush.CreateBrushIndirect(&logBrush);

		CPen newPen;
		newPen.CreatePen(PS_SOLID, 1, RGB(70, 130, 180));
		
		CBrush* pOldBrush = (CBrush*)dc.SelectObject(&brush);
		CPen* pOldPen = (CPen*)dc.SelectObject(&newPen);

		int X = 0;
		int Y = 0;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				dc.Rectangle(X, Y, 50 + X, 30 + Y);
				X += 50;
			}
			X = 0;
			Y += 30;
		}
		dc.SelectObject(pOldBrush);
		dc.SelectObject(pOldPen);

		newPen.DeleteObject();
		brush.DeleteObject();
	
	}
}

void DrawerGUI::DrawItem(int row, int col, int val) {
	CClientDC dc(AfxGetApp()->m_pMainWnd);
	SetBkMode(dc, TRANSPARENT);
	CString str;
	str.Format("%i", val); 

	int X = 50 * (col + 1) - 40;
	int Y = 30 * (row + 1) - 25;
	dc.TextOutA(X, Y, str);
}



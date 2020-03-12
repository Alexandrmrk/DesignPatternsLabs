
// lab2Dlg.h : файл заголовка
//

#pragma once
#include "afxwin.h"
#include "AMatrix.h"
#include "DecoratorRenum.h"
#include "DrawerConsole.h"
#include "DrawerGUI.h"
#include"ICommand.h"

// диалоговое окно Clab2Dlg
class Clab2Dlg : public CDialog
{
// Создание
public:
	Clab2Dlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LAB2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	AMatrix* Amatr;
	DrawerConsole* c;
	DrawerGUI* d;
	I_Command* cmd;
	bool m_genMatrix;
	int m_rows;
	int m_cols;
	int m_nonZero;
	int m_maxval;

	afx_msg void OnBnClickedGenMatrixN();
	afx_msg void OnBnClickedGenMatrixS();
	afx_msg void OnBnClickedCheckkk();
	afx_msg void OnBnClickedSet();
	afx_msg void OnBnClickedUndo();
};

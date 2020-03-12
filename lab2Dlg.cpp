
// lab2Dlg.cpp : файл реализации
//

#include "stdafx.h"

#include "lab2.h"
#include "lab2Dlg.h"
#include "afxdialogex.h"
#include "MatrixN.h"
#include "MatrixS.h"
#include "MatrixInitiator.h"
#include "DrawerConsole.h"
#include "DrawerGUI.h"
#include "DecoratorRenum.h"
#include"Horizontal_Group_Matrix.h"
#include"Vertical_Group_Matrix.h"
#include"A_Group_Matrix.h"
#include"ICommand.h"
#include"MatrixSetCommand.h"
#include"InitAppCommand.h"
#include"CommandManager.h"
#include <ctime>
#include<vector>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// диалоговое окно Clab2Dlg



Clab2Dlg::Clab2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_LAB2_DIALOG, pParent)
	, m_rows(0)
	, m_cols(0)
	, m_nonZero(0)
	, m_maxval(0)
	
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Clab2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ROWS, m_rows);
	DDX_Text(pDX, IDC_EDIT_COLS, m_cols);
	DDX_Text(pDX, IDC_EDIT_NONZERO, m_nonZero);
	DDX_Text(pDX, IDC_EDIT_MAX_VAL, m_maxval);

}

BEGIN_MESSAGE_MAP(Clab2Dlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_GEN_MATRIX_N, &Clab2Dlg::OnBnClickedGenMatrixN)
	ON_BN_CLICKED(IDC_GEN_MATRIX_S, &Clab2Dlg::OnBnClickedGenMatrixS)
	ON_BN_CLICKED(IDC_CHECKKK, &Clab2Dlg::OnBnClickedCheckkk)
	ON_BN_CLICKED(IDC_RENUM, &Clab2Dlg::OnBnClickedSet)
	ON_BN_CLICKED(IDC_GETCOMPONENT, &Clab2Dlg::OnBnClickedUndo)
END_MESSAGE_MAP()


// обработчики сообщений Clab2Dlg

BOOL Clab2Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
SetIcon(m_hIcon, TRUE);			// Крупный значок
SetIcon(m_hIcon, FALSE);		// Мелкий значок

// TODO: добавьте дополнительную инициализацию
m_rows = 10;
m_cols = 10;
m_nonZero = 0;
m_maxval = 10000;
c = new DrawerConsole();
d = new DrawerGUI();
Amatr = new MatrixN(10, 10, d);
I_Command* init_cmd = new InitAppCommand(Amatr);
init_cmd->Execute();

cmd = NULL;

UpdateData(FALSE);

return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void Clab2Dlg::OnPaint()
{
	Amatr->Draw();
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR Clab2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Clab2Dlg::OnBnClickedGenMatrixN()
{/*
	UpdateData(TRUE);
	InvalidateRect(NULL);
	UpdateWindow();
	
	if (Amatr) {
		delete Amatr;
		Amatr = NULL;
	}

	Amatr = new MatrixN(m_rows, m_cols, d);
	MatrixInitiator::fillMatrix(Amatr, m_nonZero, m_maxval);
	Amatr->Draw();
	Amatr->SetDrawer(c);
	Amatr->Draw();
	*/
}

void Clab2Dlg::OnBnClickedGenMatrixS()
{/*
	UpdateData(TRUE);
	InvalidateRect(NULL);
	UpdateWindow();
	if (Amatr) {
		delete Amatr;
		Amatr = NULL;
	}

	Amatr = new MatrixS(m_rows, m_cols, d);
	MatrixInitiator::fillMatrix(Amatr, m_nonZero, m_maxval);
	Amatr->Draw();
	//Amatr->SetDrawer(c);
	//Amatr->Draw();

	*/
}
	

void Clab2Dlg::OnBnClickedCheckkk()
{
	InvalidateRect(NULL);
	UpdateWindow();
	
	if (((CButton*)(GetDlgItem(IDC_CHECKKK)))->GetCheck() == BST_CHECKED) {
		d->SetShowBorder(true);
		c->SetShowBorder(true);
	}
	else {
		d->SetShowBorder(false);
		c->SetShowBorder(false);		
	}
	if (Amatr) {
		//Amatr->SetDrawer(c);
		//Amatr->Draw();
		Amatr->SetDrawer(d);
		Amatr->Draw();
		
	}
}



void Clab2Dlg::OnBnClickedSet()
{
	srand((unsigned int)time(nullptr));

	if(Amatr){
		InvalidateRect(NULL);
		UpdateWindow();
		I_Command* set_cmd = new MatrixSetCommand(this->Amatr, rand() % this->Amatr->GetRows(), rand() % this->Amatr->GetCols(),rand()% this->m_maxval);
		set_cmd->Execute();
		Amatr->SetDrawer(d);
		Amatr->Draw();
		//Amatr->SetDrawer(c);
		//Amatr->Draw();
	}
	else {
		return;
	}
	
}


void Clab2Dlg::OnBnClickedUndo()
{
	if (Amatr) {
		InvalidateRect(NULL);
		UpdateWindow();
		CommandManager::getInstance()->Undo();
		Amatr->SetDrawer(d);
		Amatr->Draw();
		//Amatr->SetDrawer(c);
		//Amatr->Draw();
	}
}

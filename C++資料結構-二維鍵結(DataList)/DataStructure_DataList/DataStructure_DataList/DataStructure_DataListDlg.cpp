
// DataStructure_DataListDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DataStructure_DataList.h"
#include "DataStructure_DataListDlg.h"
#include "afxdialogex.h"
#include "DataDefine.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDataStructure_DataListDlg dialog



CDataStructure_DataListDlg::CDataStructure_DataListDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DATASTRUCTURE_DATALIST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDataStructure_DataListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDataStructure_DataListDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CDataStructure_DataListDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CDataStructure_DataListDlg message handlers

BOOL CDataStructure_DataListDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDataStructure_DataListDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDataStructure_DataListDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDataStructure_DataListDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDataStructure_DataListDlg::OnBnClickedButton1()
{
	//----- Initial ...
	CString       Msg_cstr = _T("");

	DataList_CS    A_DataList_cs;
	int   ListCount_i = 0;
	int   ListDataCount_i = 0;
	int   ListName_i = 0;
	int   ListData_i = 0;
	CString   Data_cstr = _T("");
	CString   ListData_cstr = _T("");
	//-------------------------------

	A_DataList_cs.Create_Fn(100);
	A_DataList_cs.Create_Fn(200);
	A_DataList_cs.AddListData_Fn(1, 11);
	A_DataList_cs.AddListData_Fn(1, 12);
	A_DataList_cs.AddListData_Fn(1, 13);
	A_DataList_cs.AddListData_Fn(2, 21);
	A_DataList_cs.AddListData_Fn(2, 22);
	A_DataList_cs.AddListData_Fn(2, 23);
	A_DataList_cs.AddListData_Fn(2, 24);
	A_DataList_cs.AddListData_Fn(2, 25);
	MessageBox(_T("DataList create completely"));

	ListCount_i = A_DataList_cs.GetListCount_Fn();
	for (int i_i = 1; i_i <= ListCount_i; i_i++)
	{
		ListName_i = A_DataList_cs.GetListName_Fn(i_i);

		ListDataCount_i = A_DataList_cs.GetListDataCount_Fn(i_i);
		ListData_cstr = _T("");
		Data_cstr = _T("");
		for (int j_i = 1; j_i <= ListDataCount_i; j_i++)
		{
			ListData_i = A_DataList_cs.GetListData_Fn(i_i, j_i);
			if (j_i != ListDataCount_i)
				Data_cstr.Format(_T("%d,"), ListData_i);
			else
				Data_cstr.Format(_T("%d"), ListData_i);
			ListData_cstr = ListData_cstr + Data_cstr;
		}
		Msg_cstr.Format(_T("TotalListCount:%d, List[%d] - name:%d,{%s}"), ListCount_i, i_i, ListName_i, ListData_cstr);
		MessageBox(Msg_cstr);
	}
	
	A_DataList_cs.FreeListData_Fn(1);
	A_DataList_cs.AddListData_Fn(1, 1);
	A_DataList_cs.AddListData_Fn(1, 2);
	A_DataList_cs.AddListData_Fn(1, 3);
	MessageBox(_T("After free list1 data and add list1 new data"));

	ListCount_i = A_DataList_cs.GetListCount_Fn();
	for (int i_i = 1; i_i <= ListCount_i; i_i++)
	{
		ListName_i = A_DataList_cs.GetListName_Fn(i_i);

		ListDataCount_i = A_DataList_cs.GetListDataCount_Fn(i_i);
		ListData_cstr = _T("");
		Data_cstr = _T("");
		for (int j_i = 1; j_i <= ListDataCount_i; j_i++)
		{
			ListData_i = A_DataList_cs.GetListData_Fn(i_i, j_i);
			if (j_i != ListDataCount_i)
				Data_cstr.Format(_T("%d,"), ListData_i);
			else
				Data_cstr.Format(_T("%d"), ListData_i);
			ListData_cstr = ListData_cstr + Data_cstr;
		}
		Msg_cstr.Format(_T("TotalListCount:%d, List[%d] - name:%d,{%s}"), ListCount_i, i_i, ListName_i, ListData_cstr);
		MessageBox(Msg_cstr);
	}
}

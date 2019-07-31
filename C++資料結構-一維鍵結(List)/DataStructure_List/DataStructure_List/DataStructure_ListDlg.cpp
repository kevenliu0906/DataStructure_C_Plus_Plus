
// DataStructure_ListDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DataStructure_List.h"
#include "DataStructure_ListDlg.h"
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


// CDataStructure_ListDlg dialog



CDataStructure_ListDlg::CDataStructure_ListDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DATASTRUCTURE_LIST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDataStructure_ListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDataStructure_ListDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_DATASTRUCTURE_LIST, &CDataStructure_ListDlg::OnBnClickedBtnDatastructureList)
END_MESSAGE_MAP()


// CDataStructure_ListDlg message handlers

BOOL CDataStructure_ListDlg::OnInitDialog()
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

void CDataStructure_ListDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDataStructure_ListDlg::OnPaint()
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
HCURSOR CDataStructure_ListDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDataStructure_ListDlg::OnBnClickedBtnDatastructureList()
{
	//----- Initial...
	CString     Msg_cstr = _T("");
	List_CS     List_i_cs;
	int         DataCount_i = 5;
	int         ListDataCount_i = 0;
	int         TempData_i = 0;
	int         ListDataPos_i = 0;
	//---------------------------------------

	for (int i_i = 1; i_i <= DataCount_i; i_i++)
	{
		List_i_cs.Create_Fn(i_i * 10);
	}
	MessageBox(_T("After List create completely"));

	ListDataCount_i = List_i_cs.GetListDataCount_Fn();
	for (int i_i = 1; i_i <= ListDataCount_i; i_i++)
	{
		TempData_i = List_i_cs.GetListData_Fn(i_i);
		Msg_cstr.Format(_T("TotalCount:%d, List_i_cs(%d):%d"), ListDataCount_i, i_i, TempData_i);
		MessageBox(Msg_cstr);
	}

	ListDataPos_i = List_i_cs.GetListDataPosition_Fn(30);
	Msg_cstr.Format(_T("Num:30 is in the pos:%d of the list"), ListDataPos_i);
	MessageBox(Msg_cstr);


	MessageBox(_T("After Delete 2,3 listdata"));
	List_i_cs.Delete_Fn(2, 2);

	ListDataCount_i = List_i_cs.GetListDataCount_Fn();
	for (int i_i = 1; i_i <= ListDataCount_i; i_i++)
	{
		TempData_i = List_i_cs.GetListData_Fn(i_i);
		Msg_cstr.Format(_T("(After Delete)TotalCount:%d, List_i_cs(%d):%d"), ListDataCount_i, i_i, TempData_i);
		MessageBox(Msg_cstr);
	}

	ListDataPos_i = List_i_cs.GetListDataPosition_Fn(30);
	Msg_cstr.Format(_T("(After Delete)Num:30 is in the pos:%d of the list"), ListDataPos_i);
	MessageBox(Msg_cstr);

	MessageBox(_T("After insert listdata"));
	List_i_cs.Insert_Fn(1, 90);
	ListDataCount_i = List_i_cs.GetListDataCount_Fn();
	for (int i_i = 1; i_i <= ListDataCount_i; i_i++)
	{
		TempData_i = List_i_cs.GetListData_Fn(i_i);
		Msg_cstr.Format(_T("(After insert)TotalCount:%d, List_i_cs(%d):%d"), ListDataCount_i, i_i, TempData_i);
		MessageBox(Msg_cstr);
	}

	ListDataPos_i = List_i_cs.GetListDataPosition_Fn(30);
	Msg_cstr.Format(_T("(After insert)Num:30 is in the pos:%d of the list"), ListDataPos_i);
	MessageBox(Msg_cstr);


	MessageBox(_T("After new create listdata"));
	List_i_cs.Create_Fn(60);
	List_i_cs.Create_Fn(80);
	ListDataCount_i = List_i_cs.GetListDataCount_Fn();
	for (int i_i = 1; i_i <= ListDataCount_i; i_i++)
	{
		TempData_i = List_i_cs.GetListData_Fn(i_i);
		Msg_cstr.Format(_T("(After new create)TotalCount:%d, List_i_cs(%d):%d"), ListDataCount_i, i_i, TempData_i);
		MessageBox(Msg_cstr);
	}

	ListDataPos_i = List_i_cs.GetListDataPosition_Fn(30);
	Msg_cstr.Format(_T("(After new create)Num:30 is in the pos:%d of the list"), ListDataPos_i);
	MessageBox(Msg_cstr);
}

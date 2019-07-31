
// DataStructure_List_TemplateDlg.h : header file
//

#pragma once


// CDataStructure_List_TemplateDlg dialog
class CDataStructure_List_TemplateDlg : public CDialogEx
{
// Construction
public:
	CDataStructure_List_TemplateDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DATASTRUCTURE_LIST_TEMPLATE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};

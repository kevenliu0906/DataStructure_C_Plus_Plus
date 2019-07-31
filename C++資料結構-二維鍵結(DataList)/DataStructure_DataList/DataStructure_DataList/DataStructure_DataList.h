
// DataStructure_DataList.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CDataStructure_DataListApp:
// See DataStructure_DataList.cpp for the implementation of this class
//

class CDataStructure_DataListApp : public CWinApp
{
public:
	CDataStructure_DataListApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CDataStructure_DataListApp theApp;
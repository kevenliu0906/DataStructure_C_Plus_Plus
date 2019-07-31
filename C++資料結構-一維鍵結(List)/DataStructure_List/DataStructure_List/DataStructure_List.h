
// DataStructure_List.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CDataStructure_ListApp:
// See DataStructure_List.cpp for the implementation of this class
//

class CDataStructure_ListApp : public CWinApp
{
public:
	CDataStructure_ListApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CDataStructure_ListApp theApp;
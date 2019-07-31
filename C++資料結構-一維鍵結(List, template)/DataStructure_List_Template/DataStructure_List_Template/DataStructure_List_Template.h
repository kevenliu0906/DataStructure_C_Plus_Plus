
// DataStructure_List_Template.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CDataStructure_List_TemplateApp:
// See DataStructure_List_Template.cpp for the implementation of this class
//

class CDataStructure_List_TemplateApp : public CWinApp
{
public:
	CDataStructure_List_TemplateApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CDataStructure_List_TemplateApp theApp;
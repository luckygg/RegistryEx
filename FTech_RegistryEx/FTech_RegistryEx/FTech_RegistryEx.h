
// FTech_RegistryEx.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CFTech_RegistryExApp:
// See FTech_RegistryEx.cpp for the implementation of this class
//

class CFTech_RegistryExApp : public CWinApp
{
public:
	CFTech_RegistryExApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CFTech_RegistryExApp theApp;
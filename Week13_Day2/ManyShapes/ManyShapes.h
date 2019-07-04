
// ManyShapes.h : main header file for the ManyShapes application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CManyShapesApp:
// See ManyShapes.cpp for the implementation of this class
//

class CManyShapesApp : public CWinApp
{
public:
	CManyShapesApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CManyShapesApp theApp;

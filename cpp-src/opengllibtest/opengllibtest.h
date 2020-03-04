// opengllibtest.h : main header file for the OPENGLLIBTEST application
//

#if !defined(AFX_OPENGLLIBTEST_H__C4E27241_A577_4115_B366_15AC1683F494__INCLUDED_)
#define AFX_OPENGLLIBTEST_H__C4E27241_A577_4115_B366_15AC1683F494__INCLUDED_

#include <cppunit/ui/mfc/TestRunner.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// COpengllibtestApp:
// See opengllibtest.cpp for the implementation of this class
//

class COpengllibtestApp : public CWinApp
{
public:
	COpengllibtestApp();
	void runUnitTests();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COpengllibtestApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

public:
	//{{AFX_MSG(COpengllibtestApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPENGLLIBTEST_H__C4E27241_A577_4115_B366_15AC1683F494__INCLUDED_)

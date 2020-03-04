// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__BC292FB8_6B50_4FF8_A9FA_568E7E1E1260__INCLUDED_)
#define AFX_STDAFX_H__BC292FB8_6B50_4FF8_A9FA_568E7E1E1260__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <math.h>
#include "utillib/Log.h"
using namespace utillib;
#include "memorylib/gc_ptr2.h"
using namespace memorylib;
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__BC292FB8_6B50_4FF8_A9FA_568E7E1E1260__INCLUDED_)

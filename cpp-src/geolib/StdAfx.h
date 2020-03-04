// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__6D36351F_345A_4D16_9D2A_5CF30F4A0A33__INCLUDED_)
#define AFX_STDAFX_H__6D36351F_345A_4D16_9D2A_5CF30F4A0A33__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#pragma warning( default : 4996 )
#pragma warning (disable : 4786)
#pragma warning( disable : 4530 )
#pragma warning( disable : 4509 )

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
// TODO: reference additional headers your program requires here
#pragma warning (disable: 4786)

#include "memorylib/gc_ptr.h"
using namespace memorylib;

#include "teologlib///Log.h"
#include "teologlib/LogFactory.h"
using namespace teologlib;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__6D36351F_345A_4D16_9D2A_5CF30F4A0A33__INCLUDED_)

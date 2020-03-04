//-----------------------------------------------------------------------------
// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//
//-----------------------------------------------------------------------------
#pragma once

#pragma warning (disable: 4786)
#pragma warning (disable: 4996)
#pragma warning (disable: 4717)
#pragma warning (disable: 4244)
#pragma warning (disable: 4018)
#pragma warning (disable: 4927)
#pragma warning (disable: 4530)
#pragma warning (disable: 4509)

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
//#define _CRTDBG_MAP_ALLOC
//#include <stdlib.h>
//#include <crtdbg.h>

#include <stdio.h>
#include <wchar.h>
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
// TODO: reference additional headers your program requires here
#pragma warning (disable: 4786)
#define M_PI (3.1415926)
#include <teologlib/Log.h>
#include <teologlib/LogFactory.h>
using namespace teologlib;

#include <utillib/Cronometer.h>
#include <utillib/Util.h>
using namespace utillib;

#include <math.h>
#ifndef SAFE_DELETE
#define SAFE_DELETE(p)       { if(p) { delete (p);     (p)=NULL; } }
#endif    
#ifndef SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(p) { if(p) { delete[] (p);   (p)=NULL; } }
#endif    
#ifndef SAFE_RELEASE
#define SAFE_RELEASE(p)      { if(p) { (p)->Release(); (p)=NULL; } }
#endif
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.
//-----------------------------------------------------------------------------

// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#ifndef _WIN32_WINNT		// Allow use of features specific to Windows XP or later.                   
#define _WIN32_WINNT 0x0501	// Change this to the appropriate value to target other versions of Windows.
#endif						

#pragma warning(disable : 4530)
#pragma warning (disable: 4786)
#pragma warning (disable: 4786)
#pragma warning (disable: 4996)
#pragma warning (disable: 4717)
#pragma warning (disable: 4244)
#pragma warning (disable: 4018)
#pragma warning (disable: 4927)
#pragma warning (disable: 4530)
#pragma warning (disable: 4509)

#include "../utillib/Util.h"
using namespace utillib;

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers

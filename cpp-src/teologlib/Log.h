//-----------------------------------------------------------------------------
// 
// Copyright (C) 2007 Abacasoft Limited
// 
// 
//-----------------------------------------------------------------------------
#pragma once
//-----------------------------------------------------------------------------
#include <iostream>
#include <fstream>
using namespace std;
#include <string>
using namespace std;
#include <windows.h>
//-----------------------------------------------------------------------------
#ifdef UNICODE
typedef wstring tstring;
#else
typedef string tstring;
#endif
//-----------------------------------------------------------------------------
#define TEOLOG_ERRORFILE TEXT("")
//-----------------------------------------------------------------------------
namespace teologlib
{
//-----------------------------------------------------------------------------
enum LOGLEVEL {NONE_LEVEL, ERROR_LEVEL, DEBUG_LEVEL, INFO_LEVEL};
//-----------------------------------------------------------------------------
class Log
{
	wfstream out;
	bool bHasStream; 
	tstring m_tstrFileName;
public:
	tstring m_tstrName;
	int		m_level;
	void setFileName(tstring tstrFileName);
	tstring getFileName(){return m_tstrFileName;}
	
	Log(void);
	virtual ~Log(void);

	tstring toString();

	void info	(const TCHAR *fmt, ...);
	void debug	(const TCHAR *fmt, ...);
	void error	(const TCHAR *fmt, ...);

};

//-----------------------------------------------------------------------------
}//namespace teologlib
//-----------------------------------------------------------------------------

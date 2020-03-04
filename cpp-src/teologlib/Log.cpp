// ----------------------------------------------------------------------------
//
//	Copyright (C) 2007 Abacasoft limited
//
// flush the buffeer to be able to tail the logs.
// if not it logs after the program exists
//
// ----------------------------------------------------------------------------
#include "StdAfx.h"
#include "Log.h"
#include <windows.h>
#include <tchar.h>
#include <sys/timeb.h>
#include <time.h>
namespace teologlib
{
// ----------------------------------------------------------------------------
Log::Log(void)
{
	m_tstrName = TEXT("Default log name");
	m_tstrFileName = TEOLOG_ERRORFILE;
	m_level = DEBUG_LEVEL;
	bHasStream = false;
}
// ----------------------------------------------------------------------------
void Log::setFileName(tstring tstrFileName)
{
	m_tstrFileName = tstrFileName;
	out.open(m_tstrFileName.c_str(), ios::app | ios::out);
	if(!out)
	{
		::MessageBox(::GetForegroundWindow (), TEXT("Can't open log file"), m_tstrFileName.c_str(), MB_OK);
		bHasStream = false;
		return;
	}
	bHasStream = true;
}
// ----------------------------------------------------------------------------
Log::~Log(void)
{
	out.close();
}
// ----------------------------------------------------------------------------
tstring Log::toString()
{
	tstring tstrAll;
	tstrAll.append(TEXT("[m_tstrName = ")).append(m_tstrName).append(TEXT("]\n"));
	tstrAll.append(TEXT("[m_tstrFileName = ")).append(m_tstrFileName).append(TEXT("]\n"));
	tstring tstrDebugLevel;
	switch(m_level)
	{
	case INFO_LEVEL:
		tstrDebugLevel = TEXT("INFO_LEVEL");
		break;
	case DEBUG_LEVEL:
		tstrDebugLevel = TEXT("DEBUG_LEVEL");
		break;
	case ERROR_LEVEL:
		tstrDebugLevel = TEXT("ERROR_LEVEL");
		break;
	default:
		tstrDebugLevel = TEXT("NONE_LEVEL");
		break;
	}

	tstrAll.append(TEXT("[m_debuglevel = ")).append(tstrDebugLevel).append(TEXT("]\n"));

	return tstrAll;
}
#ifdef LOGGING
// ----------------------------------------------------------------------------
void Log::info	(const TCHAR *fmt, ...)
{
	if(!bHasStream)
		return;

	TCHAR* buffer = new TCHAR[1024];
	for(int i =0; i<1024; i++)buffer[i] = (TCHAR)NULL;
	TCHAR* buffer2 = new TCHAR[2048];
	for(int i =0; i<2048; i++)buffer2[i] = (TCHAR)NULL;

	//get the time
	TCHAR tmpbuf1[100] = {(TCHAR)NULL};
	TCHAR tmpbuf2[100] = {(TCHAR)NULL};
	struct _timeb tstruct;
	__try
	{
		_ftime_s( &tstruct );
		_tstrdate_s( tmpbuf1 );
		_tstrdate_s( tmpbuf2 );
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		::MessageBox(::GetForegroundWindow (), TEXT("Exception in Log::info"), TEXT("get time"), MB_OK);
	}

	int nSize = 0;
	va_list args;

	__try
	{
		if( m_level >= INFO_LEVEL)
		{
			va_start(args, fmt);
			nSize = _vsntprintf_s( buffer, 1024, _TRUNCATE, fmt, args);
			//this debugs to stdout
//			_tprintf(L"nSize: %d, buffer: %s\n", nSize, buffer);
			_stprintf_s(buffer2, 2048, TEXT("[%s %s.%d] INFO : \"%s\"\n"), 
				tmpbuf1, tmpbuf2, tstruct.millitm, buffer);
			out << buffer2;
			out.flush();
		}
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		::MessageBox(::GetForegroundWindow (), TEXT("Exception in Log::info"), TEXT(""), MB_OK);

		//		Util::casualException(GetExceptionCode(), TEXT(__FILE__), __LINE__);
	}

	__try
	{
		delete[] buffer;
		delete[] buffer2;
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		::MessageBox(::GetForegroundWindow (), TEXT("Exception in Log debug deleting buffers"), TEXT(""), MB_OK);
		
//		Util::casualException(GetExceptionCode(), TEXT(__FILE__), __LINE__);
	}

}
// ----------------------------------------------------------------------------
void Log::debug	(const TCHAR *fmt, ...)
{
	if(!bHasStream)
	{
		return;
	}

	TCHAR* buffer = new TCHAR[1024];
	for(int i =0; i<1024; i++)buffer[i] = (TCHAR)NULL;
	TCHAR* buffer2 = new TCHAR[2048];
	for(int i =0; i<2048; i++)buffer2[i] = (TCHAR)NULL;

	//get the time
	TCHAR tmpbuf1[100];
	TCHAR tmpbuf2[100];
	struct _timeb tstruct;

	__try
	{
		_ftime_s( &tstruct );
		_tstrdate_s( tmpbuf1 );
		_tstrtime_s( tmpbuf2 );
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		::MessageBox(::GetForegroundWindow (), TEXT("Exception in Log::debug"), TEXT("get time"), MB_OK);
	}

	int nSize = 0;
	va_list args;

	__try
	{
		if( m_level >= DEBUG_LEVEL)
		{
			va_start(args, fmt);
			nSize = _vsntprintf_s( buffer, 1024, _TRUNCATE, fmt, args);
			//this debugs to stdout
//			_tprintf(L"nSize: %d, buffer: %s\n", nSize, buffer);
			_stprintf_s(buffer2, 2048,TEXT("[%s %s.%d] DEBUG: \"%s\"\n"), 
				tmpbuf1, tmpbuf2, tstruct.millitm, buffer);
			out << buffer2;
			out.flush();
		}
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		::MessageBox(::GetForegroundWindow (), TEXT("Exception in Log::debug"), TEXT("m_level>=..."), MB_OK);
		
//		Util::casualException(GetExceptionCode(), TEXT(__FILE__), __LINE__);
	}

	__try
	{
		delete[] buffer;
		delete[] buffer2;
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		::MessageBox(::GetForegroundWindow (), TEXT("Exception in Log::debug deleting buffers"), TEXT(""), MB_OK);
		
//		Util::casualException(GetExceptionCode(), TEXT(__FILE__), __LINE__);
	}
}
// ----------------------------------------------------------------------------
void Log::error	(const TCHAR *fmt, ...)
{
	if(!bHasStream)
	{
		return;
	}

	TCHAR* buffer = new TCHAR[1024];
	for(int i =0; i<1024; i++)buffer[i] = (TCHAR)NULL;
	TCHAR* buffer2 = new TCHAR[2048];
	for(int i =0; i<2048; i++)buffer2[i] = (TCHAR)NULL;

	//get the time
	TCHAR tmpbuf1[100] = {(TCHAR)NULL};
	TCHAR tmpbuf2[100] = {(TCHAR)NULL};
	struct _timeb tstruct;

	__try
	{
		_ftime_s( &tstruct );
		_tstrdate_s( tmpbuf1 );
		_tstrtime_s( tmpbuf2 );
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		::MessageBox(::GetForegroundWindow (), TEXT("Exception in Log::error"), TEXT("get time"), MB_OK);
	}

	int nSize = 0;
	va_list args;

	__try
	{
		if( m_level >= ERROR_LEVEL)
		{
			va_start(args, fmt);
			nSize = _vsntprintf_s( buffer, 1024, _TRUNCATE, fmt, args);
			//this debugs to stdout
//			_tprintf_(TEXT("nSize: %d, buffer: %s\n"), nSize, buffer);
			_stprintf_s(buffer2, 2048,TEXT("[%s %s.%d] ERROR: \"%s\"\n"), 
				tmpbuf1, tmpbuf2, tstruct.millitm, buffer);
			out << buffer2;
			out.flush();
		}
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		::MessageBox(::GetForegroundWindow (), TEXT("Exception in Log::error"), TEXT(""), MB_OK);

		//		Util::casualException(GetExceptionCode(), TEXT(__FILE__), __LINE__);
	}

	__try
	{
		delete[] buffer;
		delete[] buffer2;
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		::MessageBox(::GetForegroundWindow (), TEXT("Exception in Log::error deleting buffers"), TEXT(""), MB_OK);
		
//		Util::casualException(GetExceptionCode(), TEXT(__FILE__), __LINE__);
	}
}
// ----------------------------------------------------------------------------
#else
void Log::info		(const TCHAR *fmt, ...){}
void Log::debug		(const TCHAR *fmt, ...){}
void Log::error		(const TCHAR *fmt, ...){}
#endif
}//namespace teolog
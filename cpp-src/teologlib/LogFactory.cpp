// ----------------------------------------------------------------------------
//
//
//
// ----------------------------------------------------------------------------
#include "StdAfx.h"
#include "LogFactory.h"
#include <windows.h>
#include <iostream>
#include <fstream>
using namespace std;
#ifdef UNICODE
typedef wfstream tfstream;
#else
typedef fstream tfstream;
#endif
namespace teologlib
{
tfstream in;
// ----------------------------------------------------------------------------
LogFactory* LogFactory::m_pFactory = NULL;
//tstring LogFactory::m_tstrConfigDirectory;
//bool LogFactory::bConfigRead = false;
//list<Log*> LogFactory::m_listLogs;
//list<Log*>::iterator LogFactory::m_itLogs;
// ----------------------------------------------------------------------------
/*LogFactory* LogFactory::getInstance()
{
	if(NULL == m_pLogFactory)
	{
		m_pLogFactory = new LogFactory();
	}
	return m_pLogFactory;
}
*/
// ----------------------------------------------------------------------------
LogFactory::LogFactory(void) :
	m_tstrConfigDirectory(),
	bConfigRead(false),
	m_listLogs(),
	m_itLogs()
{
//	bConfigRead = false;

//	setLogDirectory(L"D:/dev/abagraph/build_debug/log");
//	setConfigDirectory(L"d:/dev/abagraph/build_debug/config/");

//	readConfig();
}
// ----------------------------------------------------------------------------
void LogFactory::setLogs()
{
	Log* pLog = new Log;
	pLog->m_tstrName = TEXT("Log1");
	pLog->setFileName(TEXT("d:/Log1.txt"));
	pLog->m_level = INFO_LEVEL;
	addLog(pLog);

	pLog = new Log;
	pLog->m_tstrName = TEXT("Log2");
	pLog->setFileName(TEXT("d:/Log2.txt"));
	pLog->m_level = ERROR_LEVEL;
	addLog(pLog);

}
// ----------------------------------------------------------------------------
void LogFactory::addLog(Log* pLog)
{
	m_listLogs.push_back(pLog);
}
// ----------------------------------------------------------------------------
LogFactory::~LogFactory(void)
{
}
// ----------------------------------------------------------------------------
Log* LogFactory::getLog(tstring tstrName)
{
	LogFactory* pLogFactory = getStaticInstance();
	
	for(pLogFactory->m_itLogs = pLogFactory->m_listLogs.begin();
		pLogFactory->m_itLogs != pLogFactory->m_listLogs.end();
		pLogFactory->m_itLogs++)
	{
		if((*pLogFactory->m_itLogs)->m_tstrName == tstrName)
			return (*pLogFactory->m_itLogs);
	}

	return new Log;
}
// ----------------------------------------------------------------------------
//void LogFactory::setLogDirectory(tstring strLogDirectory)
//{
//	m_tstrLogDirectory = strLogDirectory;
//}
// ----------------------------------------------------------------------------
int LogFactory::init(tstring tstrConfigDirectory)
{
	setConfigDirectory(tstrConfigDirectory);
	readConfig();

	return 0;
}
// ----------------------------------------------------------------------------
void LogFactory::setConfigDirectory(tstring strConfigDirectory)
{
	m_tstrConfigDirectory = strConfigDirectory;
}
// ----------------------------------------------------------------------------
#ifdef LOGGING
int LogFactory::readConfig()
{
	tstring strConfigFile;
	tstring strLogFile;
	int error = 0;
	Log* temp;
	wfstream out;

	if(bConfigRead)//already read
	{
		return -1;
	}

	__try
	{
		bConfigRead = true;
		tstring next;

		strConfigFile.append(m_tstrConfigDirectory);
		strConfigFile.append(TEOLOG4CPP_CONFIG_FILE);
		in.open(strConfigFile.c_str(), ios::in);
//		temp = new Log;
		if(!in)
		{
			return 0;
		}

		in >> next;
		while(next == (tstring)TEXT("next"))
		{
			temp = new Log;
			tstring strLogLevel;
			strLogFile=TEXT("");
			in >> next >> next;
			temp->m_tstrName = next;
			in >> next >> next;
			temp->setFileName(next);
			in >> next >> strLogLevel;
			if(strLogLevel == TEXT("INFO"))
				temp->m_level=INFO_LEVEL;
			else if(strLogLevel == TEXT("DEBUG"))
				temp->m_level=DEBUG_LEVEL;
			else if(strLogLevel == TEXT("ERROR"))
				temp->m_level=ERROR_LEVEL;
			else
				temp->m_level=NONE_LEVEL;

			in >> next;

			const tstring strLogFile = temp->getFileName();
			TCHAR mode[2] = {TCHAR('a'), (TCHAR)NULL};
			out.open(strLogFile.c_str(), ios::app |ios::out);

			if(!out )
			{
				tstring strMessage;
				strMessage.append(TEXT("Open failed on output file: "));
				strMessage.append(strLogFile);
				MessageBox(::GetForegroundWindow (), strMessage.c_str(), TEXT("Text"), MB_OK);
//				Util::message(strMessage);
			}
			else
			{
				out << TEXT("\n-------------------------- new run -------------------------\n") << endl;
				out.close();
			}
			addLog(temp);
		}
		if(in)
		{
			in.close();
		}
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		MessageBox(::GetForegroundWindow (), TEXT("Exception in read config"), TEXT("Text"), MB_OK);
//		Util::casualException(GetExceptionCode(), TEXT(__FILE__), __LINE__);
		if(in)
		{
			in.close();
		}
		return -1;
	}
	if(in)
	{
		in.close();
	}
	return 0;
}
#else
int LogFactory::readConfig()
{
	return 0;
}
#endif

}//namespace teolog
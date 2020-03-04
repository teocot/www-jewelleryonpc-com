//-----------------------------------------------------------------------------
//
// Copyright (C) 2007 Abacasoft Limited
//
//
//-------------------------------------------------------------------------------------------------------------
// HIGH performance logging, it just writes to an open stream.
// this is the file appended to the directory passed in init, that will contain the logging setup information
// here is an example. You have to use next to mark a new record and we have to use next on the first line
// no comments allowed.
//-------------------------------------------------------------------------------------------------------------
/*
next
LogName abagraph
LogFile d:/dev/abagraph/build_debug/log/abagraph.log
LogLevel DEBUG
next
LogName utillibtest
LogFile d:/dev/abagraph/build_debug/log/utillibtest.log
LogLevel DEBUG
*/
//-----------------------------------------------------------------------------
#pragma once
//-----------------------------------------------------------------------------
#include <list>
using namespace std;
#include "Log.h"
//-------------------------------------------------------------------------------------------------------------
#define TEOLOG4CPP_CONFIG_FILE TEXT("teolog.conf")
//-------------------------------------------------------------------------------------------------------------
namespace teologlib
{
//-----------------------------------------------------------------------------
class LogFactory
{
	tstring m_tstrConfigDirectory;
	bool bConfigRead;
	list<Log*> m_listLogs;
	list<Log*>::iterator m_itLogs;

//	static LogFactory* m_pLogFactory;
	LogFactory();
//	static LogFactory* getInstance();
	static LogFactory* m_pFactory;
public:
	static LogFactory* getStaticInstance()
	{
		if(NULL == m_pFactory)
		{
			m_pFactory = new LogFactory();
		}
		return m_pFactory;
	}

	//memory
	virtual ~LogFactory(void);

	//methods
	//this will read the teolog.conf from the directory and init all the log files
	//as required from the teolog.conf file.
	int init(tstring tstrConfigDirectory);
	//this will return the log that you require and you can use it to write to log
	static Log* getLog(tstring tstrName);
private:
	void addLog(Log* pLog);
	void setLogs(); //used for test only
	int readConfig();//0 success, anything else is failure
	void setConfigDirectory(tstring strConfigDirectory);
};
//-----------------------------------------------------------------------------
}//namespace teolog
//-------------------------------------------------------------------------------------------------------------



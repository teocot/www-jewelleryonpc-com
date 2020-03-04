//
// teolog.cpp : Defines the entry point for the console application.
//
// Example using teolg loggin classes
//
/*
#include "stdafx.h"
#include "Log.h"
#include "LogFactory.h"
#include <Windows.h>

#include <iostream>
using namespace std;

#ifdef UNICODE
#define tcout wcout
#else
#define tcout cout
#endif

void initLogging()
{
	LogFactory::init(TEXT("d:/dev/abagraph/build_debug/config/"));
}
void secondFunction()
{
	Log* pLog = LogFactory::getLog(TEXT("abagraph"));
	pLog->debug(TEXT("SECOND FUNCTION CALLED"));

	pLog = LogFactory::getLog(TEXT("pipelinelib"));
	pLog->debug(TEXT("SECOND FUNCTION CALLED IN PIPELINELIB"));
}

int _tmain(int argc, _TCHAR* argv[])
{
	initLogging();

	Log* pLog = LogFactory::getLog(TEXT("abagraph"));

	tcout << LogFactory::getLog(TEXT("No match"))->toString() << endl;
	tcout << LogFactory::getLog(TEXT("Log1"))->toString()		<< endl;
	tcout << LogFactory::getLog(TEXT("Log2"))->toString()		<< endl;

	pLog->debug(TEXT("This is number %d"), 43);
	pLog->debug(TEXT("This is number %d"), 432);
	pLog->debug(TEXT("Next INOF shouldn be there %d"), 433);
	pLog->info(TEXT("This is number %d"), 433);
	pLog->debug(TEXT("Next ERROR should be there"));
	pLog->error(TEXT("I hope you did well"));

	Log* pLog2 = LogFactory::getLog(TEXT("abagraph"));
	pLog2->error(TEXT("Success"));

	secondFunction();

	return 0;
}
*/

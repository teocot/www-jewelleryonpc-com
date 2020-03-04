// TestLog.cpp: implementation of the TestLog class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
//#include "Loglibtest.h"
#include "TestLog.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CPPUNIT_TEST_SUITE_REGISTRATION(TestLog);
//----------------------------------------------------------------------

TestLog::TestLog()
{

}

TestLog::~TestLog()
{

}

void 
TestLog::tearDown()
{

}

void 
TestLog::setUp()
{

}

void 
TestLog::testLog()
{
	CPPUNIT_ASSERT(true);
}

void 
TestLog::testLogCopy()
{
	CPPUNIT_ASSERT(true);
}

void 
TestLog::testLogDestructor()
{
	CPPUNIT_ASSERT(true);
}

void 
TestLog::testOperatorAssignment()
{
	CPPUNIT_ASSERT(true);
}

void 
TestLog::testOperatorNoEqualCompare()
{
	CPPUNIT_ASSERT(true);
}

void 
TestLog::testOperatorEqualCompare()
{
	CPPUNIT_ASSERT(true);
}

void 
TestLog::testExecute()
{
	CPPUNIT_ASSERT(true);
}

void 
TestLog::testUnexecute()
{
	CPPUNIT_ASSERT(true);
}

void 
TestLog::testGetType()
{
	CPPUNIT_ASSERT(true);
}

void 
TestLog::testSetToString()
{
	CPPUNIT_ASSERT(true);
}

void 
TestLog::testGetFromString()
{
	CPPUNIT_ASSERT(true);
}


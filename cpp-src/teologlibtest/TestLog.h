// TestLog.h: interface for the TestLog class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TestLog_H__35E4348A_7609_471B_AB8B_8D543C58C341__INCLUDED_)
#define AFX_TestLog_H__35E4348A_7609_471B_AB8B_8D543C58C341__INCLUDED_

#include <cppunit/extensions/HelperMacros.h>

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class TestLog  : public CPPUNIT_NS::TestFixture
{
//----------------------------------------------------------------------
	CPPUNIT_TEST_SUITE(TestLog);
	CPPUNIT_TEST(testLog);
	CPPUNIT_TEST(testLog);
	CPPUNIT_TEST(testLogCopy);
	CPPUNIT_TEST(testLogDestructor);
	CPPUNIT_TEST(testOperatorAssignment);
	CPPUNIT_TEST(testOperatorNoEqualCompare);
	CPPUNIT_TEST(testOperatorEqualCompare);
	CPPUNIT_TEST(testExecute);
	CPPUNIT_TEST(testUnexecute);
	CPPUNIT_TEST(testGetType);
	CPPUNIT_TEST(testSetToString);
	CPPUNIT_TEST(testGetFromString);
	CPPUNIT_TEST(testGetType);
	CPPUNIT_TEST_SUITE_END();
//----------------------------------------------------------------------
public:
	void tearDown();
	void setUp();
	void testLog();
	void testLogCopy();
	void testLogDestructor();
	void testOperatorAssignment();
	void testOperatorNoEqualCompare();
	void testOperatorEqualCompare();
	void testExecute();
	void testUnexecute();
	void testGetType();
	void testSetToString();
	void testGetFromString();
public:
	TestLog();
	virtual ~TestLog();

};

#endif // !defined(AFX_TestLog_H__35E4348A_7609_471B_AB8B_8D543C58C341__INCLUDED_)

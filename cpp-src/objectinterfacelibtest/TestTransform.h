// TestTransform.h: interface for the TestTransform class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TestTransform_H__35E4348A_7609_471B_AB8B_8D543C58C341__INCLUDED_)
#define AFX_TestTransform_H__35E4348A_7609_471B_AB8B_8D543C58C341__INCLUDED_

#include <cppunit/extensions/HelperMacros.h>

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class TestTransform  : public CPPUNIT_NS::TestFixture
{
//----------------------------------------------------------------------
	CPPUNIT_TEST_SUITE(TestTransform);
	CPPUNIT_TEST(testTransform);
	CPPUNIT_TEST(testTransform);
	CPPUNIT_TEST(testTransformCopy);
	CPPUNIT_TEST(testTransformDestructor);
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
	void testTransform();
	void testTransformCopy();
	void testTransformDestructor();
	void testOperatorAssignment();
	void testOperatorNoEqualCompare();
	void testOperatorEqualCompare();
	void testExecute();
	void testUnexecute();
	void testGetType();
	void testSetToString();
	void testGetFromString();
public:
	TestTransform();
	virtual ~TestTransform();

};

#endif // !defined(AFX_TestTransform_H__35E4348A_7609_471B_AB8B_8D543C58C341__INCLUDED_)

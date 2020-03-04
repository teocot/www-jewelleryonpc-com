// TestSphere.h: interface for the TestSphere class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TESTSPHERE_H__86877AFF_EBBD_4559_9695_E95D7E7C0B92__INCLUDED_)
#define AFX_TESTSPHERE_H__86877AFF_EBBD_4559_9695_E95D7E7C0B92__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <cppunit/extensions/HelperMacros.h>

class TestSphere : public CPPUNIT_NS::TestFixture  
{
	CPPUNIT_TEST_SUITE(TestSphere);
	CPPUNIT_TEST(testSphere);
	CPPUNIT_TEST(testSphereCopy);
	CPPUNIT_TEST(testSphereDestructor);
	CPPUNIT_TEST(testAssignmentOperator);
	CPPUNIT_TEST(testEqualityOperator) ;
	CPPUNIT_TEST(testNotEqualOperator);
	CPPUNIT_TEST(testSaveToFile);
	CPPUNIT_TEST(testLoadFromFile);
	CPPUNIT_TEST(testCreateFaces);
	CPPUNIT_TEST_SUITE_END();
public:
	void tearDown();
	void setUp();
	void testSphere();
	void testSphereCopy();
	void testSphereDestructor();
	void testAssignmentOperator();
	void testEqualityOperator() ;
	void testNotEqualOperator();
	void testSaveToFile();
	void testLoadFromFile();
	void testCreateFaces();
public:
	TestSphere();
	virtual ~TestSphere();

};

#endif // !defined(AFX_TESTSPHERE_H__86877AFF_EBBD_4559_9695_E95D7E7C0B92__INCLUDED_)

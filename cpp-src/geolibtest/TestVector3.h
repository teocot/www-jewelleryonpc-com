// TestVector3.h: interface for the TestVector3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TESTVECTOR3_H__278BF0D1_0CE6_4CCD_A129_EEC5097D3119__INCLUDED_)
#define AFX_TESTVECTOR3_H__278BF0D1_0CE6_4CCD_A129_EEC5097D3119__INCLUDED_

#include <cppunit/extensions/HelperMacros.h>

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class TestVector3 : public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE(TestVector3);
	CPPUNIT_TEST(testVector3);
	CPPUNIT_TEST(testVector3Copy);
	CPPUNIT_TEST(testVector3Destructor);
	CPPUNIT_TEST(testAssignmentOperator);
	CPPUNIT_TEST(testEqualityOperator) ;
	CPPUNIT_TEST(testNotEqualOperator);
	CPPUNIT_TEST(testAdd);
	CPPUNIT_TEST(testCrossVector);
	CPPUNIT_TEST(testCrossVectorVector);
	CPPUNIT_TEST(testDiff);
	CPPUNIT_TEST(testDot);
	CPPUNIT_TEST(testGetAbsoluteLength);
	CPPUNIT_TEST(testGetArray);
	CPPUNIT_TEST(testGetX);
	CPPUNIT_TEST(testGetY);
	CPPUNIT_TEST(testGetZ);
	CPPUNIT_TEST(testLoadFromFile);
	CPPUNIT_TEST(testNormalize);
	CPPUNIT_TEST(testNegate);
	CPPUNIT_TEST(testSaveToFile);
	CPPUNIT_TEST(testSet);
	CPPUNIT_TEST(testSetArray);
	CPPUNIT_TEST(testSetX);
	CPPUNIT_TEST(testSetY);
	CPPUNIT_TEST(testSetZ);
	CPPUNIT_TEST_SUITE_END();
public:
	void tearDown();
	void setUp();
	void testVector3();
	void testVector3Copy();
	void testVector3Destructor();
	void testAssignmentOperator();
	void testEqualityOperator() ;
	void testNotEqualOperator();
	void testAdd();
	void testCrossVector();
	void testCrossVectorVector();
	void testDiff();
	void testDot();
	void testGetAbsoluteLength();
	void testGetArray();
	void testGetX();
	void testGetY();
	void testGetZ();
	void testLoadFromFile();
	void testNormalize();
	void testNegate();
	void testSaveToFile();
	void testSet();
	void testSetArray();
	void testSetX();
	void testSetY();
	void testSetZ();

public:
	TestVector3();
	virtual ~TestVector3();

};

#endif // !defined(AFX_TESTVECTOR3_H__278BF0D1_0CE6_4CCD_A129_EEC5097D3119__INCLUDED_)

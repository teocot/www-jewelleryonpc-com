// TestScaleAxes.h: interface for the TestScaleAxes class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TESTSCALEAXES_H__E5B946FA_0D57_4A53_B2AE_189DCD44C39E__INCLUDED_)
#define AFX_TESTSCALEAXES_H__E5B946FA_0D57_4A53_B2AE_189DCD44C39E__INCLUDED_

#include <cppunit/extensions/HelperMacros.h>

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class TestScaleAxes  : public CPPUNIT_NS::TestFixture
{
//----------------------------------------------------------------------
	CPPUNIT_TEST_SUITE(TestScaleAxes);
	CPPUNIT_TEST(testScaleAxes);
	CPPUNIT_TEST(testScaleAxesCopy);
	CPPUNIT_TEST(testScaleAxesDestructor);
	CPPUNIT_TEST(testAssignmentOperator);
	CPPUNIT_TEST(testEqualityOperator) ;
	CPPUNIT_TEST(testNotEqualOperator);
	CPPUNIT_TEST(testDraw );
	CPPUNIT_TEST(testDrawSelection );
	CPPUNIT_TEST(testDrawSolid );
	CPPUNIT_TEST(testDrawVertices );
	CPPUNIT_TEST(testDrawWire);
	CPPUNIT_TEST(testDrawX);
	CPPUNIT_TEST(testDrawY);
	CPPUNIT_TEST(testDrawZ);
	CPPUNIT_TEST(testRotate );
	CPPUNIT_TEST(testMove );
	CPPUNIT_TEST(testScale );
	CPPUNIT_TEST(testSelect);
	CPPUNIT_TEST(testGetCenter);
	CPPUNIT_TEST(testXSelected);
	CPPUNIT_TEST(testYSelected);
	CPPUNIT_TEST(testZSelected);
	CPPUNIT_TEST_SUITE_END();
public:
	void tearDown();
	void setUp();
	void testScaleAxes();
	void testScaleAxesCopy();
	void testScaleAxesDestructor();
	void testAssignmentOperator();
	void testEqualityOperator() ;
	void testNotEqualOperator();
	void testDraw ();
	void testDrawSelection ();
	void testDrawSolid ();
	void testDrawVertices ();
	void testDrawWire();
	void testDrawX();
	void testDrawY();
	void testDrawZ();
	void testRotate ();
	void testMove ();
	void testScale ();
	void testSelect();
	void testGetCenter();
	void testXSelected();
	void testYSelected();
	void testZSelected();
public:
	TestScaleAxes();
	virtual ~TestScaleAxes();

};

#endif // !defined(AFX_TESTSCALEAXES_H__E5B946FA_0D57_4A53_B2AE_189DCD44C39E__INCLUDED_)

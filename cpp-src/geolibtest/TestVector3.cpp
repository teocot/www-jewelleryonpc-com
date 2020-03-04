// TestVector3.cpp: implementation of the TestVector3 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "geolibtest.h"
#include "TestVector3.h"
#include <math.h>
#include "geolib/Vector3.h"
using namespace geolib;

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CPPUNIT_TEST_SUITE_REGISTRATION(TestVector3);
//----------------------------------------------------------------------
TestVector3::TestVector3()
{

}
//----------------------------------------------------------------------
TestVector3::~TestVector3()
{

}
//----------------------------------------------------------------------
void TestVector3::tearDown(){CPPUNIT_ASSERT(true);}
//----------------------------------------------------------------------
void TestVector3::setUp(){CPPUNIT_ASSERT(true);}
//----------------------------------------------------------------------
void TestVector3::testVector3()
{
	//there are 2 constructors
	Vector3 vector1;

	CPPUNIT_ASSERT(vector1.getX() == 0.00);
	CPPUNIT_ASSERT(vector1.getY() == 0.00);
	CPPUNIT_ASSERT(vector1.getZ() == 0.00);

	Vector3 vector2(2.34, 2.09, 0.98);

	CPPUNIT_ASSERT(vector2.getX() == 2.34);
	CPPUNIT_ASSERT(vector2.getY() == 2.09);
	CPPUNIT_ASSERT(vector2.getZ() == 0.98);

}
//----------------------------------------------------------------------
void TestVector3::testVector3Copy()
{
	Vector3 vector2(2.34, -0.987, 25.34);

	Vector3 vector1(vector2);
	CPPUNIT_ASSERT(vector1 == vector2);
}
//----------------------------------------------------------------------
void TestVector3::testVector3Destructor(){CPPUNIT_ASSERT(true);}
//----------------------------------------------------------------------
void TestVector3::testAssignmentOperator()
{
	CPPUNIT_ASSERT(true);
}
//----------------------------------------------------------------------
void TestVector3::testEqualityOperator()
{
	Vector3 vector1;
	Vector3 vector2;
	vector1.set(1.00, 4.00, -2.00);
	vector2.set(1.00, 4.00, -2.00);

	CPPUNIT_ASSERT(vector1 == vector2);
}
//----------------------------------------------------------------------
void TestVector3::testNotEqualOperator()
{
	Vector3 vector1;
	Vector3 vector2;
	vector1.set(1.00, 4.00, -2.00);
	vector2.set(1.00, 4.00, -2.00);

	CPPUNIT_ASSERT(!(vector1 != vector2));

	vector2.setX(0.09);
	CPPUNIT_ASSERT((vector1 != vector2));

	vector2.set(1.00, 4.00, -2.00);
	vector2.setY(0.2);
	CPPUNIT_ASSERT((vector1 != vector2));
	vector2.set(1.00, 4.00, -2.00);
	vector2.setZ(0.2);
	CPPUNIT_ASSERT((vector1 != vector2));
}
//----------------------------------------------------------------------
void TestVector3::testAdd()
{
	Vector3 vector1;
	Vector3 vector2;
	Vector3 result;
	vector1.set(1.00, 4.00, -2.00);
	vector2.set(-21.00, 2.00, 89.00);

	result.set(-20.00, 6.00, 87.00);
	
	CPPUNIT_ASSERT(result == vector1.add(vector2));
}
//----------------------------------------------------------------------
void TestVector3::testCrossVector()
{
	//test ixj=k
	Vector3 i(1.00, 0.00, 0.00);
	Vector3 minus_i(-1.00, 0.00, 0.00);
	Vector3 j(0.00, 1.00, 0.00);
	Vector3 minus_j(0.00, -1.00, 0.00);
	Vector3 k(0.00, 0.00, 1.00);
	Vector3 minus_k(0.00, 0.00, -1.00);

	CPPUNIT_ASSERT(i.cross(j) == k);
	CPPUNIT_ASSERT(j.cross(i) == minus_k);
	CPPUNIT_ASSERT(j.cross(k) == i);
	CPPUNIT_ASSERT(k.cross(j) == minus_i);
	CPPUNIT_ASSERT(k.cross(i) == j);
	CPPUNIT_ASSERT(i.cross(k) == minus_j);

}
//----------------------------------------------------------------------
void TestVector3::testCrossVectorVector()
{
	//test ixj=k
	Vector3 i(1.00, 0.00, 0.00);
	Vector3 minus_i(-1.00, 0.00, 0.00);
	Vector3 j(0.00, 1.00, 0.00);
	Vector3 minus_j(0.00, -1.00, 0.00);
	Vector3 k(0.00, 0.00, 1.00);
	Vector3 minus_k(0.00, 0.00, -1.00);

	Vector3 result;

	result.cross(i, j);
	CPPUNIT_ASSERT(result == k);
	result.cross(j, i);
	CPPUNIT_ASSERT(result == minus_k);

	result.cross(j, k);
	CPPUNIT_ASSERT(result == i);
	result.cross(k, j);
	CPPUNIT_ASSERT(result == minus_i);

	result.cross(k, i);
	CPPUNIT_ASSERT(result == j);
	result.cross(i, k);
	CPPUNIT_ASSERT(result == minus_j);
}
//----------------------------------------------------------------------
void TestVector3::testDiff()
{
	Vector3 vector1;
	vector1.set(1.00, 1.00, 1.00);
	Vector3 vector2;
	Vector3 vector3 = vector2.diff(vector1);

	CPPUNIT_ASSERT(vector3.getX() == -1.00);
	CPPUNIT_ASSERT(vector3.getY() == -1.00);
	CPPUNIT_ASSERT(vector3.getZ() == -1.00);

	vector1 = vector2;
	vector3.set(*(new Vector3));
	CPPUNIT_ASSERT(vector2.diff(vector1) == vector3);
}
//----------------------------------------------------------------------
void TestVector3::testDot()
{
	Vector3 vector1;
	Vector3 vector2;
	vector1.set(1.00, -2.00, .50);
	vector2.set(2.00, 1.00, 7.00);

	Vector3 result;
	CPPUNIT_ASSERT(3.50 == vector1.dot(vector2));
}
//----------------------------------------------------------------------
void TestVector3::testGetAbsoluteLength()
{
	Vector3 vector1;
	vector1.set(1.00, 1.00, 1.00);

	CPPUNIT_ASSERT(vector1.getAbsoluteLength() == sqrt(3));

	vector1.set(543.32, -23.89, 0.983);
	CPPUNIT_ASSERT(vector1.getAbsoluteLength() == sqrt(543.32*543.32 + (-23.89)*(-23.89) + 0.983*0.983));
}
//----------------------------------------------------------------------
void TestVector3::testGetArray()
{
	CPPUNIT_ASSERT(true);
}
//----------------------------------------------------------------------
void TestVector3::testGetX(){CPPUNIT_ASSERT(true);}
//----------------------------------------------------------------------
void TestVector3::testGetY(){CPPUNIT_ASSERT(true);}
//----------------------------------------------------------------------
void TestVector3::testGetZ(){CPPUNIT_ASSERT(true);}
//----------------------------------------------------------------------
void TestVector3::testLoadFromFile()
{
	CPPUNIT_ASSERT(true);
}
//----------------------------------------------------------------------
void 
TestVector3::testNormalize()
{
	Log* pLog = Log::getInstance("geolibtest");
	pLog->debug("TestVector3::testNormalize()"); 
	// -----------------------------------------------
	// let's see this one if it is working
	// -----------------------------------------------
	Vector3 vector(1.00, 1.00, 1.00);
	vector.normalize();
	CPPUNIT_ASSERT(vector.getAbsoluteLength() == 1.00);

	// -----------------------------------------------
	// this one is tuff, becaseu
	// the errors in caclulation
	// -----------------------------------------------
	vector.set(2309.09, 3289.09, 0.023);
	vector.normalize();
	pLog->debug("Assert %.2f - 1.00 < 0.1", vector.getAbsoluteLength());
	CPPUNIT_ASSERT((vector.getAbsoluteLength() - 1.00) < 0.0001);
}
//----------------------------------------------------------------------
void TestVector3::testNegate()
{
	double x = 23.09;
	double y = -345.09;
	double z = -345543.09;
	Vector3 vector;
	vector.set(x, y, z);
	vector.negate();
	CPPUNIT_ASSERT(vector.getX() == -x);
	CPPUNIT_ASSERT(vector.getY() == -y);
	CPPUNIT_ASSERT(vector.getZ() == -z);
}
//----------------------------------------------------------------------
void TestVector3::testSaveToFile()
{
	gc_ptr2<Vector3> vector1 = new Vector3;
	ofstream out("c:\\dev\\testfiles\\TestVector3.txt", ios::out);
	vector1->set(-34.24, -0.45, 1.23);
	vector1->saveToFile(out, 0);
	out.close();

	ifstream in("c:\\dev\\testfiles\\TestVector3.txt", ios::in);
	gc_ptr2<Vector3> vector2 = new Vector3;
	vector2->loadFromFile(in);
	in.close();

	ofstream out2("c:\\dev\\testfiles\\TestVector3_loaded.txt", ios::out);
	vector2->saveToFile(out2, 0);
	out2.close();

}
//----------------------------------------------------------------------
void TestVector3::testSet()
{
	CPPUNIT_ASSERT(true);
}
//----------------------------------------------------------------------
void TestVector3::testSetArray(){CPPUNIT_ASSERT(true);}
//----------------------------------------------------------------------
void TestVector3::testSetX(){CPPUNIT_ASSERT(true);}
//----------------------------------------------------------------------
void TestVector3::testSetY(){CPPUNIT_ASSERT(true);}
//----------------------------------------------------------------------
void TestVector3::testSetZ(){CPPUNIT_ASSERT(true);}
//----------------------------------------------------------------------

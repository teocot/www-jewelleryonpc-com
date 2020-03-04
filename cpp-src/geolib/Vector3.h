//-----------------------------------------------------------------------------
// Source file: geolib\Vector3.h
//-----------------------------------------------------------------------------
#ifndef _VECTOR3_H_
#define _VECTOR3_H_
//-----------------------------------------------------------------------------
#include <iostream>
using namespace std;
//-----------------------------------------------------------------------------
namespace geolib {
//-----------------------------------------------------------------------------
class Vector3 
{
public:
	Vector3();
	Vector3(const Vector3 &right);
	Vector3 (double x, double y, double z);
	virtual ~Vector3();
	Vector3 & operator=(const Vector3 &right);
	int operator==(const Vector3 &right) const;
	int operator!=(const Vector3 &right) const;
	double dot (Vector3& value);
	void diff (Vector3& value);
	void add (Vector3& value);
	int normalize ();
	void set (double x, double y, double z);
	void set (const Vector3& value);
	void cross (Vector3& a, Vector3& b);
	void cross (Vector3& b);
	bool saveToFile (wfstream& out, int noTabs);
	bool loadFromFile (wfstream& in);
	void negate ();
	double getAbsoluteLength ();
	//attributes
	double m_X;
	double m_Y;
	double m_Z;
};
//-----------------------------------------------------------------------------
} // namespace geolib
//-----------------------------------------------------------------------------
#endif

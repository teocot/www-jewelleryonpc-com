//-----------------------------------------------------------------------------
//
// Source file: geolib\Point3.h
//
//-----------------------------------------------------------------------------
#ifndef _POINT3_H_
#define _POINT3_H_
//-----------------------------------------------------------------------------
#include <iostream>
using namespace std;
//-----------------------------------------------------------------------------
namespace geolib {
//-----------------------------------------------------------------------------
class Point3 
{
public:
	float m_array[3]; 
	Point3();
	Point3(const Point3 &right);
	virtual ~Point3();
	Point3 & operator=(const Point3 &right);
	int operator==(const Point3 &right) const;
	int operator!=(const Point3 &right) const;
	void set (double x, double y, double z);
	void set (const Point3& value);
	void move (double dx, double dy, double dz);
	bool saveToFile (wfstream& out, int noTabs);
	bool loadFromFile (wfstream& in);
	double distanceTo (Point3 point);
	double m_X;
	double m_Y;
	double m_Z;
};
//-----------------------------------------------------------------------------
} // namespace geolib
//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------

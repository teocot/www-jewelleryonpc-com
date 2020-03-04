//-----------------------------------------------------------------------------
// Source file: geolib\Point3.cpp
//-----------------------------------------------------------------------------
#include "stdafx.h"
#include <math.h>
#include "geolib\Point3.h"
//-----------------------------------------------------------------------------
namespace geolib {
//-----------------------------------------------------------------------------
Point3::Point3() : 
	m_X(0.0),
	m_Y(0.0),
	m_Z(0.0)
{
	m_array[0] = m_array[1] = m_array[2] = 0.0f; 
}
//-----------------------------------------------------------------------------
Point3::Point3(const Point3 &right) : 
	m_X(0.0),
	m_Y(0.0),
	m_Z(0.0)
{
	m_array[0] = m_array[1] = m_array[2] = 0.0f; 
	this->m_X = right.m_X;
	this->m_Y = right.m_Y;
	this->m_Z = right.m_Z;
}
//-----------------------------------------------------------------------------
Point3::~Point3()
{
}
//-----------------------------------------------------------------------------
Point3 & Point3::operator=(const Point3 &right)
{
	m_array[0] = m_array[1] = m_array[2] = 0.0f; 
	set(right);
	return *this;
}
//-----------------------------------------------------------------------------
int Point3::operator==(const Point3 &right) const
{
	if(		((double)this->m_X != (double)right.m_X )
		||	((double)this->m_Y != (double)right.m_Y )
		||	((double)this->m_Z != (double)right.m_Z ))
		return 0;
	return 1;
}
//-----------------------------------------------------------------------------
int Point3::operator!=(const Point3 &right) const
{
	if( *this == right)
		return 0;
	return 1;
}
//-----------------------------------------------------------------------------
void Point3::set (double x, double y, double z)
{
	m_X = x;
	m_Y = y;
	m_Z = z;
	m_array[0] = x;
	m_array[1] = y;
	m_array[2] = z;
}
//-----------------------------------------------------------------------------
void Point3::set (const Point3& value)
{
	m_X=value.m_X;
	m_Y=value.m_Y;
	m_Z=value.m_Z;
}
//-----------------------------------------------------------------------------
void Point3::move (double dx, double dy, double dz)
{
	m_X += dx;
	m_Y += dy;
	m_Z += dz;
}
//-----------------------------------------------------------------------------
bool Point3::saveToFile (wfstream& out, int noTabs)
{
	tstring tabs = TEXT("");
	if(0 != noTabs)
	for(int i=0; i<noTabs; i++)
	{
		tabs.append(TEXT("  "));
	}
	out << tabs << TEXT("Point3 ") << m_X << TEXT(" ") << m_Y << TEXT(" ") << m_Z << endl;
	return true;
}
//-----------------------------------------------------------------------------
  bool Point3::loadFromFile (wfstream& in)
  {
	  tstring temp;
	  in >> temp; //"Point3: " 
	  in >> m_X ; // << " " << 
	  in >> m_Y ; // << " " << 
	  in >> m_Z ; // << endl;
	  return true;
  }
//-----------------------------------------------------------------------------
double Point3::distanceTo (Point3 point)
{
	double distance = 0.00;
	distance = 
		sqrt(
				(point.m_X - this->m_X)*(point.m_X - this->m_X) +  
				(point.m_Y - this->m_Y)*(point.m_Y - this->m_Y) +  
				(point.m_Z - this->m_Z)*(point.m_Z - this->m_Z)
			);
	return distance;
}
//-----------------------------------------------------------------------------
} // namespace geolib
//-----------------------------------------------------------------------------

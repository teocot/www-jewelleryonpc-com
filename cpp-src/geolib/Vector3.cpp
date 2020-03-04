//-----------------------------------------------------------------------------
//
// Source file: geolib\Vector3.cpp
//
//-----------------------------------------------------------------------------
#include "stdafx.h"
#include "math.h"
#include "geolib\Vector3.h"
//-----------------------------------------------------------------------------
namespace geolib {
//-----------------------------------------------------------------------------
Vector3::Vector3()
    : m_X(0.0),
      m_Y(0.0),
      m_Z(0.0)
{
}
//-----------------------------------------------------------------------------
Vector3::Vector3(const Vector3 &right)
    : m_X(0.0),
      m_Y(0.0),
      m_Z(0.0)
{
	m_X = right.m_X;
	m_Y = right.m_Y;
	m_Z = right.m_Z;
}
//-----------------------------------------------------------------------------
Vector3::Vector3 (double x, double y, double z)
    : m_X(0.0),
      m_Y(0.0),
      m_Z(0.0)
{
	set(x, y, z);
}
//-----------------------------------------------------------------------------
Vector3::~Vector3()
{
}
//-----------------------------------------------------------------------------
Vector3 & Vector3::operator=(const Vector3 &right)
{
	set(right);
	return *this;
}
//-----------------------------------------------------------------------------
int Vector3::operator==(const Vector3 &right) const
{
	// --------------------------------------------------------------
	// we deal with precision here.
	// we should define it in the save/load to/from files,
	// there is a point of error
	// --------------------------------------------------------------
	if(		(fabs((double)this->m_X - (double)right.m_X ) > 0.01)
		||	(fabs((double)this->m_Y - (double)right.m_Y ) > 0.01)
		||	(fabs((double)this->m_Z - (double)right.m_Z ) > 0.01))
	{
		return 0;
	}

	return 1;
}
//-----------------------------------------------------------------------------
int Vector3::operator!=(const Vector3 &right) const
{
	if( *this == right)
	{
		return 0;
	}
	return 1;
}
//-----------------------------------------------------------------------------
double Vector3::dot (Vector3& value)
{
	return m_X*value.m_X + m_Y*value.m_Y + m_Z*value.m_Z;
}
//-----------------------------------------------------------------------------
void Vector3::diff (Vector3& value)
{
	m_X = m_X - value.m_X;
	m_Y = m_Y - value.m_Y;
	m_Z = m_Z - value.m_Z;
}
//-----------------------------------------------------------------------------
void Vector3::add (Vector3& value)
{
	m_X = m_X + value.m_X;
	m_Y = m_Y + value.m_Y;
	m_Z = m_Z + value.m_Z;
}
//-----------------------------------------------------------------------------
int Vector3::normalize ()
{
	double size = 0.00;
	double sizeSquare =		(this->m_X)*(this->m_X)
						+	(this->m_Y)*(this->m_Y)
						+	(this->m_Z)*(this->m_Z);

	if(sizeSquare < 0.0000001) 
		return 1;

	size = sqrt(sizeSquare);

	try
	{
		this->m_X = this->m_X/size;
		this->m_Y = this->m_Y/size;
		this->m_Z = this->m_Z/size;
	}
	catch(exception e)
	{
		throw e;
	}
	//------------------------------
	//is successfully normalized
	//------------------------------
	return 0;
}
//-----------------------------------------------------------------------------
void Vector3::set (double x, double y, double z)
{
	m_X = x;
	m_Y = y;
	m_Z = z;
}
//-----------------------------------------------------------------------------
void Vector3::set (const Vector3& value)
{
	m_X=value.m_X;
	m_Y=value.m_Y;
	m_Z=value.m_Z;
}
//-----------------------------------------------------------------------------
void Vector3::cross (Vector3& a, Vector3& b)
{
	double tempx, tempy, tempz;
	tempx = a.m_Y*b.m_Z - a.m_Z*b.m_Y;
	tempy = a.m_Z*b.m_X - a.m_X*b.m_Z;
	tempz = a.m_X*b.m_Y - a.m_Y*b.m_X;
	this->m_X = tempx;
	this->m_Y = tempy;
	this->m_Z = tempz;
}
//-----------------------------------------------------------------------------
void Vector3::cross (Vector3& b)
{
	double tempx, tempy, tempz;
	tempx = m_Y*b.m_Z - m_Z*b.m_Y;
	tempy = m_Z*b.m_X - m_X*b.m_Z;
	tempz = m_X*b.m_Y - m_Y*b.m_X;
	m_X = tempx;
	m_Y = tempy;
	m_Z = tempz;
}
//-----------------------------------------------------------------------------
bool Vector3::saveToFile (wfstream& out, int noTabs)
{
	tstring tabs = TEXT("");
	if(0 != noTabs)
	{
		for(int i=0; i<noTabs; i++)
		{
			tabs.append(TEXT("  "));
		}
	}
	out << tabs << TEXT("Vector3 ") << m_X << TEXT(" ") << m_Y << TEXT(" ") << m_Z << endl;

	return true;
}
//-----------------------------------------------------------------------------
bool Vector3::loadFromFile (wfstream& in)
{
	tstring temp;
	in >> temp; //"Vector3: " 
	in >> m_X ; // << " " << 
	in >> m_Y ; // << " " << 
	in >> m_Z ; // << endl;

	return true;
}
//-----------------------------------------------------------------------------
void Vector3::negate ()
{
	this->m_X = -this->m_X;
	this->m_Y = -this->m_Y;
	this->m_Z = -this->m_Z;
}
//-----------------------------------------------------------------------------
double Vector3::getAbsoluteLength ()
{
	return sqrt(this->m_X*this->m_X +
				this->m_Y*this->m_Y +
				this->m_Z*this->m_Z);
}
//-----------------------------------------------------------------------------
} // namespace geolib
//-----------------------------------------------------------------------------

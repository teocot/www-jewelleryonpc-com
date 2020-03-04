//-----------------------------------------------------------------------------
// Source file: geolib\Point3Matrix4.cpp
//-----------------------------------------------------------------------------
#include "stdafx.h"
#include "geolib\Point3Matrix4.h"
//-----------------------------------------------------------------------------
namespace geolib {
//-----------------------------------------------------------------------------
  Point3Matrix4::Point3Matrix4()
  {
  }
//-----------------------------------------------------------------------------
  Point3Matrix4::Point3Matrix4(const Point3Matrix4 &right)
  {
  }
//-----------------------------------------------------------------------------
  Point3Matrix4::~Point3Matrix4()
  {
  }
//-----------------------------------------------------------------------------
  Point3Matrix4 & Point3Matrix4::operator=(const Point3Matrix4 &right)
  {
	return *this;
  }
//-----------------------------------------------------------------------------
  void Point3Matrix4::M4MultiplyP3 (Matrix4 matrix, Point3 point)
  {
  }
//-----------------------------------------------------------------------------
  void Point3Matrix4::D16MultiplyD3 (double matrix[], double pointInput[], double pointOutput[])
  {
	try
	{
		pointOutput[0]= matrix[0]*pointInput[0]+
						matrix[1]*pointInput[1]+
						matrix[2]*pointInput[2]+
						matrix[3]*1.00;
		pointOutput[1]= matrix[4]*pointInput[0]+
						matrix[5]*pointInput[1]+
						matrix[6]*pointInput[2]+
						matrix[7]*1.00;
		pointOutput[2]= matrix[8]*pointInput[0]+
						matrix[9]*pointInput[1]+
						matrix[10]*pointInput[2]+
						matrix[11]*1.00;
		pointOutput[3]= matrix[12]*pointInput[0]+
						matrix[13]*pointInput[1]+
						matrix[14]*pointInput[2]+
						matrix[15]*1.00;
	}
	catch(exception e)
	{
		//Log->error("exception e = %s", e.what());
		//----------------------------------------------
		// don't let it hide, some index out of bounds
		//----------------------------------------------
		throw e;
	}
  }
//-----------------------------------------------------------------------------
} // namespace geolib
//-----------------------------------------------------------------------------

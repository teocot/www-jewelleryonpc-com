//-----------------------------------------------------------------------------
//
// Source file: geolib\Point3Matrix4.h
//
//-----------------------------------------------------------------------------
#ifndef _POINT3MATRIX4_H_
#define _POINT3MATRIX4_H_
//-----------------------------------------------------------------------------
#include "geolib\Matrix4.h"
#include "geolib\Point3.h"
//-----------------------------------------------------------------------------
namespace geolib {
//-----------------------------------------------------------------------------
class Point3Matrix4 
{
public:
	Point3Matrix4();
	virtual ~Point3Matrix4();
private:
	Point3Matrix4(const Point3Matrix4 &right);
	Point3Matrix4 & operator=(const Point3Matrix4 &right);

	static void M4MultiplyP3 (Matrix4 matrix, Point3 point);
	static void D16MultiplyD3 (double matrix[], double pointInput[], double pointOutput[]);
};
//-----------------------------------------------------------------------------
} // namespace geolib
//-----------------------------------------------------------------------------
#endif

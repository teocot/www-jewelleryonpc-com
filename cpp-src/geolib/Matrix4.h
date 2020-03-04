//-----------------------------------------------------------------------------
//
// Source file: c:\dev\src\geolib\Matrix4.h
//
//-----------------------------------------------------------------------------
#ifndef _MATRIX4_H_
#define _MATRIX4_H_
//-----------------------------------------------------------------------------
namespace geolib {
//-----------------------------------------------------------------------------
class Matrix4 
{
public:
	Matrix4();
	Matrix4(const Matrix4 &right);
	virtual ~Matrix4();
	Matrix4 & operator=(const Matrix4 &right);
	void inverse (Matrix4* in, Matrix4* out);
	double det4x4 (Matrix4* in);
	double det3x3 (double a1, double a2, double a3,
					double b1, double b2, double b3, 
					double c1, double c2, double c3);
	double det2x2 (double a, double b, double c, double d);
	void adjoint (Matrix4* in, Matrix4* out);
	void setElement (int i, int j, double value);
	void set (double n16value[16]);
	bool saveToFile (fstream& out, int noTabs);
	bool loadFromFile (fstream& in);
	double m_Element[4][4];
};
} // namespace geolib
#endif

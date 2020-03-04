//-----------------------------------------------------------------------------
// File Transform.h
//-----------------------------------------------------------------------------

#pragma once

#include <windows.h>
#include <string>
#include <list>
#include <fstream>
#include <iostream>
using namespace std;
#include <geolib/Matrix4.h>
#include <geolib/Vector3.h>
using namespace geolib;
// ----------------------------------------------------------------------------
#ifdef UNICODE
	typedef wfstream tfstream;
#else
	typedef fstream tfstream;
#endif
#ifdef UNICODE
	typedef wstring tstring;
#else
	typedef string tstring;
#endif
// ----------------------------------------------------------------------------
#include <memorylib/RefCount.h>
#include <memorylib/gc_ptr.h>
using namespace memorylib;
// ----------------------------------------------------------------------------
namespace objectinterfacelib 
{
// ----------------------------------------------------------------------------
class Transform : public RefCount
{
private:
	void normalRotation(Matrix4* pMatWorld );
	void arcballRotation(Matrix4* pMatWorld );
	
public:
	Transform();
	Transform(const Transform &right);
	virtual ~Transform();
	Transform & operator=(const Transform &right);

	int operator==(const Transform &right) const;
	int operator!=(const Transform &right) const;

	void move (double dx, double dy, double dz);
	void rotate (double xangle, double yangle, double zangle);
	void rotate (Matrix4& matRotation );
	void scale (double xscale, double yscale, double zscale);

	bool saveToFile (tfstream& out, int noTabs);
	bool loadFromFile (tfstream& in);

	void apply			( Matrix4* matrix );
	void applyMove		( Matrix4* matrixMove );
	void applyRotation	( Matrix4* matrixRotation );
	void applyScale		( Matrix4* matrixScaling );

	void rotatePoint (Vector3& input, double dx, double dy, double dz, 
						Vector3* output, 
						double centerX = 0.00, double centerY = 0.00, double centerZ = 0.00);
	void scalePoint (Vector3& input, double dx, double dy, double dz, 
					Vector3* output, 
					double centerX = 0.00, double centerY = 0.00, double centerZ = 0.00);

	//	the point should belong to the object,
	//	if it doesn't the actual transform is applied to the
	//	point and the result is output
	void getPointRelativeCoordinates (Vector3 input, Vector3* output, 
					double centerX = 0.00, double centerY = 0.00, double centerZ = 0.00);

	// Data Members for Class Attributes
	double m_XRotation;
	double m_YRotation;
	double m_ZRotation;
	double m_XMove;
	double m_YMove;
	double m_ZMove;
	double m_XScale;
	double m_YScale;
	double m_ZScale;
	Matrix4	m_matRotation;
	Matrix4  m_mModelLastRot;        // Last arcball rotation matrix for model 
	Matrix4  m_mModelRot;            // Rotation matrix of model

};
// ----------------------------------------------------------------------------
} // namespace opengllib
// ----------------------------------------------------------------------------


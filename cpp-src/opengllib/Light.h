//-----------------------------------------------------------------------------
// Source file: opengllib\Light.h
//-----------------------------------------------------------------------------
#pragma once;
//-----------------------------------------------------------------------------
#include <iostream>
using namespace std;
#include <windows.h>
#include <gl/gl.h>
#include "geolib\Point3.h"
#include "geolib\Vector3.h"
#include "opengllib\Color.h"
#include "memorylib\RefCount.h"
using namespace geolib;
namespace opengllib {
//-----------------------------------------------------------------------------
class Light : public memorylib::RefCount  
{
public:
	Light();
	Light(const Light &right);
	virtual ~Light();
	Light & operator=(const Light &right);
	void giveLight ();
	void giveWhiteLight();
	bool saveToFile (wfstream& out, int noTabs);
	bool loadFromFile (wfstream& in);

	Color m_Ambient;
	Color m_Diffuse;
	Color m_Specular;
	Color m_Emissive;

	GLfloat m_WhiteLightArray[4];
	GLfloat m_AmbientArray[4];
	GLfloat m_DiffuseArray[4];
	GLfloat m_SpecularArray[4];
	GLfloat m_EmissiveArray[4];

	GLfloat m_PositionArray[4];
	GLfloat m_SpotDirectionArray[3];
	GLenum m_AttenuationType;
	GLfloat m_SpotCutoff;
	GLfloat m_SpotExponent;
	bool m_On;
	GLenum m_Glname;

	GLfloat m_ConstantAttenuation;
	GLfloat m_LinearAttenuation;
	GLfloat m_QuadraticAttenuation;
};
//-----------------------------------------------------------------------------
} // namespace opengllib
//-----------------------------------------------------------------------------

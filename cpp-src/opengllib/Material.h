//-----------------------------------------------------------------------------
// Source file: c:\dev\src\opengllib\Material.h
//-----------------------------------------------------------------------------
#pragma once
//-----------------------------------------------------------------------------
#include <fstream>
using namespace std;
#include <windows.h>
#include <gl/gl.h>
#include "opengllib\Textures.h"
#include "opengllib\Color.h"
#include "memorylib\RefCount.h"
using namespace opengllib;
#include <sstream>
using namespace std;

//-----------------------------------------------------------------------------
namespace opengllib {
//-----------------------------------------------------------------------------
class Material : public memorylib::RefCount  
{
public:
	Material();
	Material(const Material &right);
	virtual ~Material();
	Material & operator=(const Material &right);
	int apply ();
	void set(Material& m);
	void setDefault ();
	bool saveToFile (wfstream& out, int noTabs);
	bool loadFromFile (wfstream& in);
	void loadFromSString(istringstream& iss);
	void setTexture (unsigned int id);
	Color m_Ambient;
	Color m_Diffuse;
	Color m_Specular;
	float m_SpecularExponent;
	Color m_Emissive;
	double m_Shininess;
	GLenum m_FrontAndBack;
	bool m_AmbientEqualDiffuse;
	static int m_NumberOfMaterials;
	int m_Id;
	tstring m_Name;
	static int getNumberOfMaterials ();
	static void setNumberOfMaterials (int value);

	//texture
	bool m_bHasTexture;
	tstring m_strTextureName;
	unsigned int m_TextureId;

	//helpers
	float amb[4],diff[4],spec[4], emiss[4];
	float zero[4] ;

};
//-----------------------------------------------------------------------------
} // namespace opengllib
//-----------------------------------------------------------------------------

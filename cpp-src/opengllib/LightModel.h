//-----------------------------------------------------------------------------
// Source file: opengllib/LightModel.h
//-----------------------------------------------------------------------------
#pragma once;
//-----------------------------------------------------------------------------
#include <iostream>
using namespace std;
#include <windows.h>
#include <gl/gl.h>
#include "memorylib/gc_ptr.h"
using namespace memorylib;
//-----------------------------------------------------------------------------
#include "opengllib\Color.h"
#include "memorylib\RefCount.h"
//-----------------------------------------------------------------------------
namespace opengllib {
  // Class: LightModel%3FD1419801E5
  //	GL_FRONT | GL_BACK | GL_FRONT_AND_BACK.
  //
  //	Nothing else?
//-----------------------------------------------------------------------------
class LightModel : public memorylib::RefCount  
{
private:
    LightModel();
    LightModel & operator=(const LightModel &right);
    LightModel(const LightModel &right);
    static gc_ptr<LightModel> getStaticInstance ();
    static gc_ptr<LightModel> m_Instance;
public:
	virtual ~LightModel();
    static void apply ();
    static bool isTwoSided ();
    static bool saveToFile (wfstream& out, int noTabs);
    static bool loadFromFile (wfstream& in);
	static bool init();
	static bool bIsInit;
//attributes
	static GLenum m_Side;
    static bool m_IsEnabled;
    static bool m_IsTwoSided;
    static Color m_AmbientColor;
    static bool m_IsLocalView;
};
//-----------------------------------------------------------------------------
} // namespace opengllib
//-----------------------------------------------------------------------------

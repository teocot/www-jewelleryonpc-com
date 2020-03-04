//-----------------------------------------------------------------------------
//
// Source file: c:\dev\src\opengllib\Color.h
//
//-----------------------------------------------------------------------------
#pragma once;
//-----------------------------------------------------------------------------
#include <iostream>
using namespace std;
#include <windows.h>
#include <gl/gl.h>
#include <sstream>
using namespace std;
//-----------------------------------------------------------------------------
//#include "utillib\RandomGenerator.h"
#include "memorylib\RefCount.h"
using namespace memorylib;
//using namespace utillib;
//-----------------------------------------------------------------------------
namespace opengllib {
//-----------------------------------------------------------------------------
class Color : public memorylib::RefCount  
{
public:
	GLfloat m_array[4];
    Color();
    Color(const Color &right);
    Color (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha = 1.0f);
    virtual ~Color();
    Color & operator=(const Color &right);
    void apply ();
    void set (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha = 0.0f);
    void build4tuple (GLfloat v[]);
    bool saveToFile (wfstream& out, int noTabs);
    bool loadFromFile (wfstream& in);
	bool loadFromSString(istringstream& iss);
	GLfloat m_Red;
    GLfloat m_Green;
    GLfloat m_Blue;
    GLfloat m_Alpha;
};
//-----------------------------------------------------------------------------
} // namespace opengllib
//-----------------------------------------------------------------------------

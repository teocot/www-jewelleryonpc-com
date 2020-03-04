//-----------------------------------------------------------------------------
// File ContourBox.h
//-----------------------------------------------------------------------------
#pragma once
//-----------------------------------------------------------------------------
#include <map>
#include <windows.h>
#include <string>
#include <list>
#include <fstream>
#include <iostream>
using namespace std;
#include <opengllib/Color.h>
using namespace opengllib;
// ----------------------------------------------------------------------------
#ifdef UNICODE
	typedef wofstream tofstream;
	typedef wifstream tifstream;
#else
	typedef ofstream tofstream;
	typedef ifstream tifstream;
#endif
//-----------------------------------------------------------------------------
namespace objectlib {
//-----------------------------------------------------------------------------
//	This is drawing the box for the selected items.
//	I wanted to customize the corners, but it takes too long.
//	Ayyway, the Color of the edges and the width of the
//	edges applies to the entire box for now.
//-----------------------------------------------------------------------------
class ContourBox 
{
public:
	ContourBox();
	virtual ~ContourBox();
private:
	ContourBox(const ContourBox &right);
	ContourBox & operator=(const ContourBox &right);
public:
	//static void draw (Mesh* mesh);
	static void draw (/*Object3d* gluObject*/);
	static void drawFace1 ();
	static void drawFace2 ();
	static void drawFace3 ();
	static void drawFace4 ();
	static void drawFace5 ();
	static void drawFace6 ();
	// Data Members for Class Attributes
	static double m_XMin;
	static double m_XMax;
	static double m_YMin;
	static double m_YMax;
	static double m_ZMin;
	static double m_ZMax;
	static bool m_HasCorners;
	static Color m_CornerColor;
	static double m_CornerWidth;
	static Color m_EdgeColor;
	static double m_EdgeWidth;
	static double m_RatioEdgeOverCorner;
};
//-----------------------------------------------------------------------------  
} // namespace objectlib
//-----------------------------------------------------------------------------  

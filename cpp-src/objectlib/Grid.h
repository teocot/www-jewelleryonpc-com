//-----------------------------------------------------------------------------  
// File Grid.h
//-----------------------------------------------------------------------------  
#pragma once
//-----------------------------------------------------------------------------  
#include <iostream>
using namespace std;
#include <opengllib/Color.h>
using namespace opengllib;
//-----------------------------------------------------------------------------  
namespace objectlib {
//-----------------------------------------------------------------------------  
//	when we set it to 2, we split the cells and redraw, when
//	we reset back we delete the small ones and redraw
//	the logic is in the calculate method, which calculates
//	everything and calls draw()
//
//	or better, draw calls calculate and then draws, but no,
//	because there will be a performance overhead.
//
//	Better, only when we create and change the No
//	SUbdivisions attribute
//-----------------------------------------------------------------------------  
class Grid 
{
public:
	Grid();
	virtual ~Grid();
private:
	Grid(const Grid &right);
	Grid & operator=(const Grid &right);
public:
	void draw ();
	void drawXY ();
	void drawYZ ();
	void drawZX ();
	void calculate ();
	void drawSolid ();
	void drawWire ();
	void drawSelection ();
	void drawVertices ();
	void drawContourBox () {}
//-----------------------------------------------------------------------------  
	double m_Heigth;
	double m_Width;
	double m_CellSize;
	int m_NoSubdivisions;
	tstring m_DrawPlane;
	Color m_Color;
};
//-----------------------------------------------------------------------------  
} // namespace objectlib
//-----------------------------------------------------------------------------  


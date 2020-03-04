//-----------------------------------------------------------------------------
// File Grid.cpp
//-----------------------------------------------------------------------------
#include "stdafx.h"
#include "objectlib\Grid.h"
//-----------------------------------------------------------------------------
namespace objectlib {
//-----------------------------------------------------------------------------
Grid::Grid() : 
	m_Heigth(20.00),
	m_Width(20.00),
	m_CellSize(25.00),
	m_NoSubdivisions(10),
	m_DrawPlane(TEXT("ZX")),
	m_Color()
{
}
//-----------------------------------------------------------------------------
Grid::Grid(const Grid &right) : 
	m_Heigth(20.00),
	m_Width(20.00),
	m_CellSize(25.00),
	m_NoSubdivisions(10),
	m_DrawPlane(TEXT("ZX")),
	m_Color()
{
}
//-----------------------------------------------------------------------------
Grid::~Grid()
{
}
//-----------------------------------------------------------------------------
void Grid::draw ()
{
	int i=0;
	GLboolean bLightWasEnabled = FALSE;
	bLightWasEnabled = glIsEnabled(GL_LIGHTING);

	glLineWidth(1.0);
	if(bLightWasEnabled)
	{
		glDisable(GL_LIGHTING);
	}
	// draw a grid, here we should have a custom grid class
	if(0 == _tcsncmp(m_DrawPlane.c_str(), TEXT("XY"),2 ))
		drawXY();
	else if(0 == _tcsncmp(m_DrawPlane.c_str(), TEXT("YZ"),2 ))
		drawYZ();
	else if(0 == _tcsncmp(m_DrawPlane.c_str(), TEXT("ZX"),2 ))
		drawZX();
	else
		drawZX();
//		glColor3d(.2, .2, .2);
	float colArray[4];
	m_Color.build4tuple(colArray);
	glColor3fv((const GLfloat*)colArray);

	glBegin(GL_LINES);
		for (	i = -m_NoSubdivisions*m_CellSize;
				i <= m_NoSubdivisions*m_CellSize; 
				i+=m_CellSize) 
		{
			glVertex3i(i, 0,  -m_NoSubdivisions*m_CellSize);//just simply setting up the square
			glVertex3i(i, 0, m_NoSubdivisions*m_CellSize);
		}
	glEnd();
	glBegin(GL_LINES);
		for (   i = -m_NoSubdivisions*m_CellSize; 
				i <= m_NoSubdivisions*m_CellSize; 
				i+=m_CellSize) 
		{
			glVertex3i(-m_NoSubdivisions*m_CellSize, 0, i);
			glVertex3i(m_NoSubdivisions*m_CellSize, 0, i);
		}
	glEnd();
	if(bLightWasEnabled)
	{
		glEnable(GL_LIGHTING);
	}
}
//-----------------------------------------------------------------------------
void Grid::drawXY ()
{
	glRotated(90, 1.0, 0.0, 0.0); 
}
//-----------------------------------------------------------------------------
void Grid::drawYZ ()
{
	glRotated(90, 0.0, 0.0, 1.0); 
}
//-----------------------------------------------------------------------------
void Grid::drawZX ()
{
	glRotated(0, 1.0, 0.0, 0.0); 
}
//-----------------------------------------------------------------------------
void Grid::calculate ()
{
}
//-----------------------------------------------------------------------------
void Grid::drawSolid ()
{
}
//-----------------------------------------------------------------------------
void Grid::drawWire ()
{
}
//-----------------------------------------------------------------------------
void Grid::drawSelection ()
{
}
//-----------------------------------------------------------------------------
void Grid::drawVertices ()
{
}
//-----------------------------------------------------------------------------
} // namespace objectlib
//-----------------------------------------------------------------------------




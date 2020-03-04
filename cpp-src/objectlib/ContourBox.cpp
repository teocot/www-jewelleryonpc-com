//-----------------------------------------------------------------------------
// File ContourBox.cpp
//-----------------------------------------------------------------------------
#include "stdafx.h"
#include "objectlib\ContourBox.h"
//-----------------------------------------------------------------------------
namespace objectlib {
//-----------------------------------------------------------------------------
double	ContourBox::m_XMin			= 0.00;
double	ContourBox::m_XMax			= 0.00;
double	ContourBox::m_YMin			= 0.00;
double	ContourBox::m_YMax			= 0.00;
double	ContourBox::m_ZMin			= 0.00;
double	ContourBox::m_ZMax			= 0.00;
bool	ContourBox::m_HasCorners	= true;
Color	ContourBox::m_CornerColor;// = Color_ARGB(0.0, 1.00, 0.0, 1.0);
double	ContourBox::m_CornerWidth	= 3.00;
Color	ContourBox::m_EdgeColor;//	= Color_ARGB(1.0, 0.0, 1.0, 1.0);
double	ContourBox::m_EdgeWidth		= 1.00;
double	ContourBox::m_RatioEdgeOverCorner = 5.00;
//-----------------------------------------------------------------------------
ContourBox::ContourBox()
{
}
//-----------------------------------------------------------------------------
ContourBox::ContourBox(const ContourBox &right)
{
}
//-----------------------------------------------------------------------------
ContourBox::~ContourBox()
{
}
//-----------------------------------------------------------------------------
ContourBox & ContourBox::operator=(const ContourBox &right)
{
	return *this;
}
//-----------------------------------------------------------------------------
/*
void ContourBox::draw (Mesh* mesh)
{

	if(mesh == NULL)
	{
		return;
	}
	GLboolean bLightWasEnabled;// = GL_FALSE;
	//disable the light, if enabled
	bLightWasEnabled = glIsEnabled(GL_LIGHTING);
	if(bLightWasEnabled )
		glDisable(GL_LIGHTING);

	mesh->getMinMax(&m_XMin, &m_XMax,
					&m_YMin, &m_YMax,
					&m_ZMin, &m_ZMax);

	glLineWidth(m_EdgeWidth);
	m_EdgeColor.apply();
	drawFace1();
	drawFace2();
	drawFace3();
	drawFace4();
	drawFace5();
	drawFace6();
	glLineWidth(1.0);
	glColor3f(0.0, 0.0, 0.0);


	//re-enable lighting if it was enabled, before
	if(bLightWasEnabled )
		glEnable(GL_LIGHTING);
}
*/
//-----------------------------------------------------------------------------
void ContourBox::draw (/*Object3d* gluObject*/)
{
/*	if(gluObject == NULL)
		return;
*/
	GLboolean bLightWasEnabled;// = GL_FALSE;
	//disable the light, if enabled
	bLightWasEnabled = glIsEnabled(GL_LIGHTING);
	if(bLightWasEnabled )
		glDisable(GL_LIGHTING);
/*
	gluObject->getMinMax(&m_XMin, &m_XMax,
					&m_YMin, &m_YMax,
					&m_ZMin, &m_ZMax);
*/
	glLineWidth(m_EdgeWidth);
	m_EdgeColor.apply();
	drawFace1();
	drawFace2();
	drawFace3();
	drawFace4();
	drawFace5();
	drawFace6();
	glLineWidth(1.0);
	glColor3f(0.0, 0.0, 0.0);


	//re-enable lighting if it was enabled, before
	if(bLightWasEnabled )
		glEnable(GL_LIGHTING);
}
//-----------------------------------------------------------------------------
void ContourBox::drawFace1 ()
{
	glBegin(GL_LINE_LOOP);
	//face 1
		glVertex3d(m_XMin, m_YMin, m_ZMax);
		glVertex3d(m_XMax, m_YMin, m_ZMax);
		glVertex3d(m_XMax, m_YMax, m_ZMax);
		glVertex3d(m_XMin, m_YMax, m_ZMax);
	glEnd();

	return;
	//the rest is for silly mans to have
	//corneres highlighted, when I will get old and 
	//have more time for bliz bliz-uri

	//firstLine
	//startCorner
	glLineWidth(m_CornerWidth);
	m_CornerColor.apply();
	glBegin(GL_LINES);
		glVertex3d(	m_XMin, m_YMin, m_ZMax);
		glVertex3d(	m_XMin + (m_XMax-m_XMin)/m_RatioEdgeOverCorner,
					m_YMin, 
					m_ZMax);
	glEnd();

	//middle
	glLineWidth(m_EdgeWidth);
	m_EdgeColor.apply();
	glBegin(GL_LINES);
		glVertex3d(	m_XMin + (m_XMax-m_XMin)/m_RatioEdgeOverCorner, 
					m_YMin, m_ZMax);
		glVertex3d(m_XMin + (m_RatioEdgeOverCorner-1)*(m_XMax-m_XMin)/m_RatioEdgeOverCorner, 
					m_YMin, m_ZMax);
	glEnd();

	//endCorner
	glLineWidth(m_CornerWidth);
	m_CornerColor.apply();
	glBegin(GL_LINES);
		glVertex3d(m_XMin + (m_RatioEdgeOverCorner-1)*(m_XMax-m_XMin)/m_RatioEdgeOverCorner,
					m_YMin, m_ZMax);
		glVertex3d(m_XMax, m_YMin, m_ZMax);
	glEnd();

	//line2
	//startCorner
	glLineWidth(m_CornerWidth);
	m_CornerColor.apply();
	glBegin(GL_LINES);
		glVertex3d(m_XMax, m_YMin, m_ZMax);
		glVertex3d(m_XMax, m_YMin+(m_YMax-m_YMin)/m_RatioEdgeOverCorner, m_ZMax);
	glEnd();

	//middle
	glLineWidth(m_EdgeWidth);
	m_EdgeColor.apply();
	glBegin(GL_LINES);
		glVertex3d(	m_XMax,
					m_YMin+(m_YMax-m_YMin)/m_RatioEdgeOverCorner, 
					m_ZMax);
		glVertex3d(	m_XMax, 
					m_YMin+(m_RatioEdgeOverCorner-1)*(m_YMax-m_YMin)/m_RatioEdgeOverCorner, 
					m_ZMax);
	glEnd();

	//endCorner
	glLineWidth(m_CornerWidth);
	m_CornerColor.apply();
	glBegin(GL_LINES);
		glVertex3d(	m_XMax, 
					m_YMin+(m_RatioEdgeOverCorner-1)*(m_YMax-m_YMin)/m_RatioEdgeOverCorner, 
					m_ZMax);
		glVertex3d(m_XMax, m_YMax, m_ZMax);
	glEnd();

	//line3
	//startCorner
	glLineWidth(m_CornerWidth);
	m_CornerColor.apply();
	glBegin(GL_LINES);
		glVertex3d(	m_XMin, 
					m_YMax, 
					m_ZMax);
		glVertex3d(	m_XMin+(m_XMax-m_XMin)/m_RatioEdgeOverCorner, 
					m_YMax, 
					m_ZMax);
	glEnd();

	//middle
	glLineWidth(m_EdgeWidth);
	m_EdgeColor.apply();
	glBegin(GL_LINES);
		glVertex3d(	m_XMin+(m_XMax-m_XMin)/m_RatioEdgeOverCorner, 
					m_YMax, m_ZMax);
		glVertex3d(	m_XMin+(m_RatioEdgeOverCorner-1)*(m_XMax-m_XMin)/m_RatioEdgeOverCorner, 
					m_YMax, m_ZMax);
	glEnd();

	//endCorner
	glLineWidth(m_CornerWidth);
	m_CornerColor.apply();
	glBegin(GL_LINES);
		glVertex3d(	m_XMin+(m_RatioEdgeOverCorner-1)*(m_XMax-m_XMin)/m_RatioEdgeOverCorner, 
					m_YMax, m_ZMax);
		glVertex3d(	m_XMax, 
					m_YMax, m_ZMax);
	glEnd();

	//line4
	glLineWidth(m_CornerWidth);
	m_CornerColor.apply();
	glBegin(GL_LINES);
		glVertex3d(	m_XMin, 
					m_YMin,		
					m_ZMax);
		glVertex3d(	m_XMin, 
					m_YMin+(m_YMax-m_YMin)/m_RatioEdgeOverCorner,
					m_ZMax);
	glEnd();

	//middle
	glLineWidth(m_EdgeWidth);
	m_EdgeColor.apply();
	glBegin(GL_LINES);
		glVertex3d(	m_XMin, 
					m_YMin+(m_YMax-m_YMin)/m_RatioEdgeOverCorner,
					m_ZMax);
		glVertex3d(	m_XMin, 
					m_YMin+(m_RatioEdgeOverCorner-1)*(m_YMax-m_YMin)/m_RatioEdgeOverCorner, 
					m_ZMax);
	glEnd();

	//endCorner
	glLineWidth(m_CornerWidth);
	m_CornerColor.apply();
	glBegin(GL_LINES);
		glVertex3d(	m_XMin, 
					m_YMin+(m_RatioEdgeOverCorner-1)*(m_YMax-m_YMin)/m_RatioEdgeOverCorner, 
					m_ZMax);
		glVertex3d(	m_XMin, 
					m_YMax, 
					m_ZMax);
	glEnd();
	//EndLines:
	glLineWidth(1.0);
	glColor3f(0.0, 1.0, 0.0);
}
//-----------------------------------------------------------------------------
void ContourBox::drawFace2 ()
{
	glBegin(GL_LINE_LOOP);
	//face 2
		glVertex3d(m_XMax, m_YMin, m_ZMax);
		glVertex3d(m_XMax, m_YMin, m_ZMin);
		glVertex3d(m_XMax, m_YMax, m_ZMin);
		glVertex3d(m_XMax, m_YMax, m_ZMax);
	glEnd();
    
}
//-----------------------------------------------------------------------------
void ContourBox::drawFace3 ()
{
	glBegin(GL_LINE_LOOP);
	//face 3
		glVertex3d(m_XMax, m_YMin, m_ZMin);
		glVertex3d(m_XMin, m_YMin, m_ZMin);
		glVertex3d(m_XMin, m_YMax, m_ZMin);
		glVertex3d(m_XMax, m_YMax, m_ZMin);
	glEnd();
}
//-----------------------------------------------------------------------------
void ContourBox::drawFace4 ()
{
	glBegin(GL_LINE_LOOP);
	//face 4
		glVertex3d(m_XMin, m_YMin, m_ZMin);
		glVertex3d(m_XMin, m_YMin, m_ZMax);
		glVertex3d(m_XMin, m_YMax, m_ZMax);
		glVertex3d(m_XMin, m_YMax, m_ZMin);
	glEnd();
}
//-----------------------------------------------------------------------------
void ContourBox::drawFace5 ()
{
	glBegin(GL_LINE_LOOP);
	//face 5
		glVertex3d(m_XMin, m_YMax, m_ZMax);
		glVertex3d(m_XMax, m_YMax, m_ZMax);
		glVertex3d(m_XMax, m_YMax, m_ZMin);
		glVertex3d(m_XMin, m_YMax, m_ZMin);
	glEnd();
}
//-----------------------------------------------------------------------------
void ContourBox::drawFace6 ()
{
	glBegin(GL_LINE_LOOP);
	//face 6
		glVertex3d(m_XMin, m_YMin, m_ZMax);
		glVertex3d(m_XMin, m_YMin, m_ZMin);
		glVertex3d(m_XMax, m_YMin, m_ZMin);
		glVertex3d(m_XMax, m_YMin, m_ZMax);
	glEnd();
}
//-----------------------------------------------------------------------------
} // namespace objectlib
//-----------------------------------------------------------------------------




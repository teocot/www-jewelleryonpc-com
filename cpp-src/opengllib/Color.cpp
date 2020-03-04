//-----------------------------------------------------------------------------
//
// Source file: c:\dev\src\opengllib\Color.cpp
//
//-----------------------------------------------------------------------------
#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
#include "opengllib\Color.h"
namespace opengllib {
//-----------------------------------------------------------------------------
Color::Color() : 
	m_Red(0.00f),
	m_Green(0.00f),
	m_Blue(0.00f),
	m_Alpha(0.00f)
{
	m_array[0] = m_array[1] = m_array[2] = m_array[3] = 0.0f;
//	  RandomGenerator random;
//	  m_Red   = (float)(random.integer(0, 255)/(float)255);
//	  m_Green = (float)(random.integer(0, 255)/(float)255);
//	  m_Blue  = (float)(random.integer(0, 255)/(float)255);
}
//-----------------------------------------------------------------------------
Color::Color(const Color &right) : 
	m_Red(0.00),
	m_Green(0.00),
	m_Blue(0.00),
	m_Alpha(0.00)
{
	/**
	 * this should be done in the initialization list of
	 * the copy constructor.
	 * this copy constructor is better to be private.
	 * the side effects are that each time we pass Color
	 * as an argument by Array, a new obiect is created
	 * this is very expensive and might fail
	 */
	this->m_Red = right.m_Red;
	this->m_Green = right.m_Green;
	this->m_Blue = right.m_Blue;
	this->m_Alpha = right.m_Alpha;
}
//-----------------------------------------------------------------------------
Color::Color (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) : 
	m_Red(0.00),
	m_Green(0.00),
	m_Blue(0.00),
	m_Alpha(0.00)
{
	this->m_Red = red;
	this->m_Green = green;
	this->m_Blue = blue;
	this->m_Alpha = alpha;
}
//-----------------------------------------------------------------------------
Color::~Color()
{
}
Color & Color::operator=(const Color &right)
{
	this->m_Red = right.m_Red;
	this->m_Green = right.m_Green;
	this->m_Blue = right.m_Blue;
	this->m_Alpha = right.m_Alpha;

	return *this;
}
//-----------------------------------------------------------------------------
void Color::apply ()
{
	glColor3f(this->m_Red, this->m_Green, this->m_Blue);
}
//-----------------------------------------------------------------------------
void Color::set (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
	this->m_Red=(red);
	this->m_Green=(green);
	this->m_Blue=(blue);
	this->m_Alpha=(alpha);
}
//-----------------------------------------------------------------------------
void Color::build4tuple (float v[])
{
	// load 4-tuple with this color: v[3] = 1 for homogeneous
	v[0] = m_Red; 
	v[1] = m_Green;
	v[2] = m_Blue;
	v[3] = m_Alpha;
}
//-----------------------------------------------------------------------------
bool Color::saveToFile (wfstream& out, int noTabs)
{
	tstring tabs = TEXT("");
	if(0 != noTabs)
	for(int i=0; i<noTabs; i++)
		tabs.append(TEXT("  "));
	out << tabs << TEXT("Color ") << m_Red << TEXT(" ") << m_Green << TEXT(" ")
		<< m_Blue << TEXT(" ") << m_Alpha << endl;
	return true;
}
//-----------------------------------------------------------------------------
bool Color::loadFromFile (wfstream& in)
{
	tstring temp; // 
	in >> temp ; //"Color "
	in >> m_Red ;
	in >> m_Green ;
	in >> m_Blue ;
	in >> m_Alpha;

	return true;
}
//-----------------------------------------------------------------------------
bool Color::loadFromSString(istringstream& iss)
{
	iss >> m_Red ;
	iss >> m_Green ;
	iss >> m_Blue ;
	iss >> m_Alpha;

	return true;
}
//-----------------------------------------------------------------------------
} // namespace opengllib
//-----------------------------------------------------------------------------

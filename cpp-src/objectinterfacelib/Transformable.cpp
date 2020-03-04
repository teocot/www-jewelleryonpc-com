//-----------------------------------------------------------------------------
// File Transformable.cpp
//-----------------------------------------------------------------------------
#include "stdafx.h"
#include "Transformable.h"
//-----------------------------------------------------------------------------
namespace objectinterfacelib {
//-----------------------------------------------------------------------------
Transformable::Transformable() : 
	m_Transform()
{
}
//-----------------------------------------------------------------------------
Transformable::Transformable(const Transformable &right)
{
	cout << "inside copy constructor" << endl;    
 }
//-----------------------------------------------------------------------------
Transformable::~Transformable()
{
}
//-----------------------------------------------------------------------------
Transformable & Transformable::operator=(const Transformable &right)
{
	return *this;
}
//-----------------------------------------------------------------------------
int Transformable::operator==(const Transformable &right) const
{
	return 0;
}
//-----------------------------------------------------------------------------
int Transformable::operator!=(const Transformable &right) const
{
	  return 0;    
}
//-----------------------------------------------------------------------------
Transform Transformable::getTransform ()
{
	return m_Transform;    
}
//-----------------------------------------------------------------------------
string Transformable::toString ()
{
	return (string)("Transformable Object");
}
//-----------------------------------------------------------------------------
} // namespace objectinterfacelib
//-----------------------------------------------------------------------------




//-----------------------------------------------------------------------------
//
// Source file: c:\dev\src\opengllib\Light.cpp
//
//-----------------------------------------------------------------------------
#include "stdafx.h"
#include "opengllib\Light.h"
//-----------------------------------------------------------------------------
namespace opengllib {
//-----------------------------------------------------------------------------
Light::Light() : 
	m_Ambient(),
	m_Diffuse(),
	m_Specular(),
	m_Emissive(),
	m_AttenuationType(GL_AMBIENT),
	m_SpotCutoff(0.00),
	m_SpotExponent(1.00),
	m_On(true),
	m_Glname(GL_LIGHT0),
	m_ConstantAttenuation(1.00),
	m_LinearAttenuation(0.00),
	m_QuadraticAttenuation(0.00)
{
	m_SpotDirectionArray[0] = m_SpotDirectionArray[1] = m_SpotDirectionArray[2] = 7.0f;
	m_PositionArray[0] = m_PositionArray[1] = m_PositionArray[2] = 8.0f;
	m_WhiteLightArray[0] = m_WhiteLightArray[1] = m_WhiteLightArray[2] = 
		m_WhiteLightArray[3] = 1.0;
}
//-----------------------------------------------------------------------------
Light::Light(const Light &right) : 
	m_Ambient(),
	m_Diffuse(),
	m_Specular(),
	m_Emissive(),
	m_AttenuationType(GL_AMBIENT),
	m_SpotCutoff(0.00),
	m_SpotExponent(1.00),
	m_On(true),
	m_Glname(GL_LIGHT0),
	m_ConstantAttenuation(1.00),
	m_LinearAttenuation(0.00),
	m_QuadraticAttenuation(0.00)
{
	this->m_SpotDirectionArray[0] = right.m_SpotDirectionArray[0];
	this->m_SpotDirectionArray[1] = right.m_SpotDirectionArray[1];
	this->m_SpotDirectionArray[2] = right.m_SpotDirectionArray[2];
	this->m_SpotDirectionArray[3] = right.m_SpotDirectionArray[3];

	this->m_PositionArray[0] = right.m_PositionArray[0];
	this->m_PositionArray[1] = right.m_PositionArray[1];
	this->m_PositionArray[2] = right.m_PositionArray[2];
}
//-----------------------------------------------------------------------------
Light::~Light()
{
}
//-----------------------------------------------------------------------------
Light & Light::operator=(const Light &right)
{
	this->m_SpotDirectionArray[0] = right.m_SpotDirectionArray[0];
	this->m_SpotDirectionArray[1] = right.m_SpotDirectionArray[1];
	this->m_SpotDirectionArray[2] = right.m_SpotDirectionArray[2];
	this->m_SpotDirectionArray[3] = right.m_SpotDirectionArray[3];

	this->m_PositionArray[0] = right.m_PositionArray[0];
	this->m_PositionArray[1] = right.m_PositionArray[1];
	this->m_PositionArray[2] = right.m_PositionArray[2];

	return *this;
}
//-----------------------------------------------------------------------------
void Light::giveLight ()
{
	glLightfv(m_Glname, GL_AMBIENT, m_AmbientArray);
	glLightfv(m_Glname, GL_DIFFUSE, m_DiffuseArray);
	glLightfv(m_Glname, GL_SPECULAR, m_SpecularArray);
	glLightfv(m_Glname, GL_POSITION, m_PositionArray);


/*	glLightf(m_Glname, GL_SPOT_CUTOFF, m_SpotCutoff);
	glLightf(m_Glname, GL_SPOT_EXPONENT, m_SpotExponent);
	glLightfv(m_Glname, GL_SPOT_DIRECTION, m_SpotDirectionArray);


	glLightf(m_Glname, GL_CONSTANT_ATTENUATION, m_ConstantAttenuation);
	glLightf(m_Glname, GL_LINEAR_ATTENUATION, m_LinearAttenuation);
	glLightf(m_Glname, GL_QUADRATIC_ATTENUATION, m_QuadraticAttenuation);
*/

	//	glEnable(GL_LIGHT0);
	if(m_On)
		glEnable(m_Glname);
	else
		glDisable(m_Glname);
}
//-----------------------------------------------------------------------------
void Light::giveWhiteLight()
{
	glLightfv(m_Glname, GL_AMBIENT, m_WhiteLightArray);
	glLightfv(m_Glname, GL_DIFFUSE, m_WhiteLightArray);
	glLightfv(m_Glname, GL_SPECULAR, m_WhiteLightArray);

	glLightfv(m_Glname, GL_POSITION, m_PositionArray);
	glLightf(m_Glname, GL_SPOT_CUTOFF, m_SpotCutoff);
	glLightf(m_Glname, GL_SPOT_EXPONENT, m_SpotExponent);
	glLightfv(m_Glname, GL_SPOT_DIRECTION, m_SpotDirectionArray);


	glLightf(m_Glname, GL_CONSTANT_ATTENUATION, m_ConstantAttenuation);
	glLightf(m_Glname, GL_LINEAR_ATTENUATION, m_LinearAttenuation);
	glLightf(m_Glname, GL_QUADRATIC_ATTENUATION, m_QuadraticAttenuation);


	//	glEnable(GL_LIGHT0);
	if(m_On)
		glEnable(m_Glname);
	else
		glDisable(m_Glname);
}
//-----------------------------------------------------------------------------
  bool Light::saveToFile (wfstream& out, int noTabs)
  {
	tstring tabs = TEXT("");
	if(0 != noTabs)
	for(int i=0; i<noTabs; i++)
	{
		tabs.append(TEXT("  "));
	}
	out << tabs << TEXT("Light \n");
	out << tabs << TEXT("{\n");
	out << tabs << TEXT("  Ambient              ") ; 
	m_Ambient.saveToFile(out, 0);
	out << tabs << TEXT("  Diffuse              ") ; 
	m_Diffuse.saveToFile(out, 0) ;
	out << tabs << TEXT("  Specular             ") ; 
	m_Specular.saveToFile(out, 0) ;
	out << tabs << TEXT("  Emissive             ") ; 
	m_Emissive.saveToFile(out, 0);

	out << tabs << TEXT("  PositionArray        ") ;
	out <<	m_PositionArray[0] << TEXT(" ") ;
	out <<	m_PositionArray[1] << TEXT(" ") ;
	out <<	m_PositionArray[2] << TEXT(" ") ;
	out <<	m_PositionArray[3] << TEXT(" ") ;
	out << endl;

	out << tabs << TEXT("  SpotDirectionArray   ") ;
	out <<	m_SpotDirectionArray[0] << TEXT(" ") ;
	out <<	m_SpotDirectionArray[1] << TEXT(" ") ;
	out <<	m_SpotDirectionArray[2] << TEXT(" ") ;
	out << endl;

	out << tabs << TEXT("  SpotCutoff           ") << m_SpotCutoff				
		<< TEXT("\n");
	out << tabs << TEXT("  SpotExponent         ") << m_SpotExponent			
		<< TEXT("\n");
	out << tabs << TEXT("  On	                ") << m_On						
		<< TEXT("\n");
	out << tabs << TEXT("  Glname               ") << m_Glname					
		<< TEXT("\n");
	out << tabs << TEXT("  AttenuationType      ") << m_AttenuationType			
		<< TEXT("\n");
	out << tabs << TEXT("  ConstantAttenuation  ") << m_ConstantAttenuation		
		<< TEXT("\n");
	out << tabs << TEXT("  LinearAttenuation    ") << m_LinearAttenuation		
		<< TEXT("\n");
	out << tabs << TEXT("  QuadraticAttenuation ") << m_QuadraticAttenuation	
		<< TEXT("\n");
	out << tabs << TEXT("}//Light\n");
	return true;
  }
//-----------------------------------------------------------------------------
  bool Light::loadFromFile (wfstream& in)
  {
	tstring temp;
	in >> temp; //"Light : \n";
	in >> temp; //"{\n";
	in >> temp; //"  Ambient         : " ; 
	m_Ambient.loadFromFile(in);
	in >> temp; //"  Diffuse         : " ; 
	m_Diffuse.loadFromFile(in) ;
	in >> temp; //"  Specular        : " ; 
	m_Specular.loadFromFile(in) ;
	in >> temp; //"  Emissive        : " ; 
	m_Emissive.loadFromFile(in);
	in >> temp; //"  PositionArray   : " ;
	in >> m_PositionArray[0] >> m_PositionArray[1] >> m_PositionArray[2] >> m_PositionArray[3];
	in >> temp; //"  SpotDirectionArray  : " << ;
	in >> m_SpotDirectionArray[0] >> m_SpotDirectionArray[1] >> m_SpotDirectionArray[2];
	in >> temp; //"  SpotCutoff      : " << 
	in >> m_SpotCutoff ;
	in >> temp; //"  SpotExponent    : " << 
	in >> m_SpotExponent;
	in >> temp; //"  On	          : " << 
	in >> m_On;
	in >> temp; //"  Glname          : " << 
	in >> m_Glname;
	in >> temp; //"  AttenuationType : " << 
	in >> m_AttenuationType;
	in >> temp; //"  ConstantAttenuation  : " << 
	in >> m_ConstantAttenuation ; // << "\n";
	in >> temp; //"  LinearAttenuation    : " <<
	in >> m_LinearAttenuation ;
	in >> temp; //"  QuadraticAttenuation : " << 
	in >> m_QuadraticAttenuation ;
	in >> temp ; //"}\n";
	return true;
  }
//-----------------------------------------------------------------------------
} // namespace opengllib
//-----------------------------------------------------------------------------

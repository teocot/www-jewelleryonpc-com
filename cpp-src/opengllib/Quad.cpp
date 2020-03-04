//-----------------------------------------------------------------------------
//
// Source file: opengllib\Quad.cpp
//
//-----------------------------------------------------------------------------
#include "stdafx.h"
#include "opengllib\Quad.h"
//-----------------------------------------------------------------------------
namespace opengllib {
//-----------------------------------------------------------------------------
  Quad::Quad()
        : m_TextureId(0),
          m_HasTexture(false)
  {
  }
//-----------------------------------------------------------------------------
  Quad::Quad(const Quad &right)
        : m_TextureId(0),
          m_HasTexture(false)
  {
	  this->m_One = right.m_One;
	  this->m_Two = right.m_Two;
	  this->m_Three = right.m_Three;
	  this->m_Four = right.m_Four;
	  this->m_TextureId = right.m_TextureId;
  }
//-----------------------------------------------------------------------------
  Quad::~Quad()
  {
  }
//-----------------------------------------------------------------------------
  Quad & Quad::operator=(const Quad &right)
  {
	  this->m_One = right.m_One;
	  this->m_Two = right.m_Two;
	  this->m_Three = right.m_Three;
	  this->m_Four = right.m_Four;
	  this->m_TextureId = right.m_TextureId;
	  return *this;
  }
//-----------------------------------------------------------------------------
  void Quad::draw ()
  {
	  if(this->m_HasTexture)
	  {
		  glEnable(GL_TEXTURE_2D);
		  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	
		  glBindTexture(GL_TEXTURE_2D, this->m_TextureId);
	  }
	  else
		  glDisable(GL_TEXTURE_2D);
		
	  glBegin(GL_QUADS);
			this->m_One.draw();
			this->m_Two.draw();
			this->m_Three.draw();
			this->m_Four.draw();
	  glEnd();

	  glDisable(GL_TEXTURE_2D);

  }
//-----------------------------------------------------------------------------
  bool Quad::saveToFile (fstream& out, int noTabs)
  {
	string tabs = "";
	if(0 != noTabs)
	for(int i=0; i<noTabs; i++)
		tabs.append("  ");
	  out << tabs << "Quad save to file" << endl;
	  return true;
  }
//-----------------------------------------------------------------------------
  bool Quad::loadFromFile (fstream& in)
  {
	  return true;
  }
//-----------------------------------------------------------------------------
} // namespace opengllib
//-----------------------------------------------------------------------------

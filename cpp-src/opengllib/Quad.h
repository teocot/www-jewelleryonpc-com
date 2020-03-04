//-----------------------------------------------------------------------------
//
// Source file: opengllib\Quad.h
//
//-----------------------------------------------------------------------------
#ifndef _QUAD_H_
#define _QUAD_H_
//-----------------------------------------------------------------------------
#include <windows.h>
#include <gl/gl.h>
#include <iostream>
using namespace std;
#include "opengllib\Vertex3f.h"
//-----------------------------------------------------------------------------
namespace opengllib {
  //	This is a simple 4 vertices surface
  //	It provides 4 vertices + 4 tecture coordinates
  //	The main function is to draw after a texture is bind in
  //	the client.
  //	or we could set the texture for the surface, which then
  //	can take care of binding it.
  //	what about the later case?
//-----------------------------------------------------------------------------
class Quad 
{
public:
	Quad();
private:
	Quad(const Quad &right);
	Quad & operator=(const Quad &right);
public:
	virtual ~Quad();
	//	this one will simply do the staff for the texture
	//	vertices as well.
	//	If a texture is bound, then the texture will be there,
	//	if not, not.
	//	something like
	//	if(hasTexture)
	//	textures.getTexture(TextureId).bind();
	//	..do the drawing here
	virtual void draw ();
	bool saveToFile (fstream& out, int noTabs);
	bool loadFromFile (fstream& in);
	//	the texture for the surface.
	//	We should however have another flag to tell if we want
	//	to use a texture or not.
	//	If not, a quad will simply have a material or even less:
	//	a color in smooth or flat mode.
	GLuint m_TextureId;
	Vertex3f m_One;
	Vertex3f m_Two;
	Vertex3f m_Three;
	Vertex3f m_Four;
	bool m_HasTexture;
};
//-----------------------------------------------------------------------------
} // namespace opengllib
//-----------------------------------------------------------------------------
#endif

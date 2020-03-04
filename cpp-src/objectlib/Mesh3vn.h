//-----------------------------------------------------------------------------
// 
// Mesh3vn.h //simple mesh and the best, most probably
//	it can have multiple vertices faces.
//
//-----------------------------------------------------------------------------
#pragma once
//-----------------------------------------------------------------------------  
#include <gl/gl.h> 
#include <memorylib/RefCount.h>
using namespace memorylib;
#include "opengllib/material.h"
using namespace opengllib;
#include <geolib/Point3.h>
#include <geolib/Vector3.h>
using namespace geolib;
#include <objectinterfacelib/Transform.h>
using namespace objectinterfacelib;
//-----------------------------------------------------------------------------
namespace objectlib
{
//-----------------------------------------------------------------------------
//################## class VertexID ################
//used to define a Mesh
//-----------------------------------------------------------------------------
class VertexID{public: int vertIndex, normIndex, texIndex;};
//-----------------------------------------------------------------------------
//################# class FACE ##############
//used to define a Mesh
//-----------------------------------------------------------------------------
class Face{
public:
	int nVerts;
	VertexID * vert; // array of vertex and normal indices
	Face();
	~Face();
	bool hasVertex(int vertexIndex);
};
//-----------------------------------------------------------------------------
//################# class EDGE ##############
//used to define a Mesh
//-----------------------------------------------------------------------------
class Edge{
public:
	int vert1, vert2;
	Edge();
	~Edge();
};
//-----------------------------------------------------------------------------
//@$@$@$@$@$@$@$@$@$@ Mesh class @$@$@$@$@$@$@$@$@$
//-----------------------------------------------------------------------------
class Mesh3vn : public RefCount
{
public:
	GLuint m_listSolid;
	GLuint m_listSolidSmooth;
	GLuint m_listWire;
	GLuint m_listWireSmooth;
	GLboolean bNoLists;
	void createLists();
	void listDisplay(long mode, bool bSmooth = false);

	long m_drawState; //GL_LINE_LOOP |GL_POLYGON, whatelse, probably material
	Transform m_Transform;
	double m_x;
	double m_y;
	double m_z;
	double m_rx;
	double m_ry;
	double m_rz;
	int m_id;
	static int s_noMeshes;
	bool m_bIsSelected;
	void setMaterial(Material& material, gc_ptr<PixelMap> pTexture);
	void getMinMax (double* xMin, double* xMax, 
					double* yMin, double* yMax, 
					double* zMin, double* zMax);
	bool hasX(double x);
	bool hasY(double y);
	bool hasZ(double z);
	void move (double dx, double dy, double dz) ;
	void rotate (double rx, double ry, double rz);
	void rotate (Matrix4& matRotation);
	bool boundingSphereRadius(float& radius);
	void scale (double sx, double sy, double sz);
public:

	Material m_Material;
	gc_ptr<PixelMap> m_pTexture;

	int numVerts, numNorms, numFaces, numEdgesFgon;
	Point3 *pt; // array of points
	Vector3 *norm; // array of normals
	Vector3 *normVertex; // array of normals
	Face *face; // array of faces
	Edge *edge; //array of edges
	int lastVertUsed;
	int lastNormUsed;
	int lastFaceUsed;
	GLuint   numtexcoords;		
	GLfloat* texcoords;			
public:
	void calculateSmoothNormals();
	GLvoid calculateLinearTexture();
	GLvoid calculateSpheremapTexture();
	void setMaterial(Material& mt){m_Material.set(mt);}
	void tellMaterialsGL();
	void readMesh(tstring fname);
	void writeMesh(char* fname);
	void printMesh();
	void drawMesh(long mode, bool bSmooth = false);
	void drawWithColor(float red, float green, float blue);
	void drawEdges();
	void freeMesh();
	int isEmpty(); 	
	void makeEmpty(); 
	Mesh3vn();
	virtual ~Mesh3vn();
	virtual void drawOpenGL(long mode, bool bSmooth=false);	
	Mesh3vn(tstring fname);
	Vector3 newell4(int indx[]);
	tstring meshFileName; // holds file name for this Mesh

	//-------------------------------------------------------------------------
	// unitScale: "unitScale" a model by translating it to the origin and
	// scaling it to fit in a unit cube around the origin.  Returns the
	// scalefactor used.
	//-------------------------------------------------------------------------
	double teoUnitScale();
	double unitScale();
	double mx(double a, double b) ;
	double ab(double f);

}; // end of Mesh class
//-----------------------------------------------------------------------------
}//namespace objectlib
//-----------------------------------------------------------------------------

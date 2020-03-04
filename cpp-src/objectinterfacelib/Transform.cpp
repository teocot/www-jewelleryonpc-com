//-----------------------------------------------------------------------------
// File Transform.cpp
//-----------------------------------------------------------------------------
#include "stdafx.h"
#include <gl/gl.h> 
#include <math.h>
#include "Transform.h"
#include "../teologlib/Log.h"
#include "../teologlib/LogFactory.h"
using namespace teologlib;

namespace objectinterfacelib {
//-----------------------------------------------------------------------------
Transform::Transform() : 
	m_XRotation(0.00),
	m_YRotation(0.00),
	m_ZRotation(0.00),
	m_XMove(0.00),
	m_YMove(0.00),
	m_ZMove(0.00),
	m_XScale(6.00),
	m_YScale(6.00),
	m_ZScale(6.00)
{
//	D3DXMatrixIdentity(&m_matRotation);
//	D3DXMatrixIdentity(&m_mModelLastRot);        // Last arcball rotation matrix for model 
//	D3DXMatrixIdentity(&m_mModelRot);            // Rotation matrix of model
}
//-----------------------------------------------------------------------------
Transform::Transform(const Transform &right) : 
	m_XRotation(0.00),
	m_YRotation(0.00),
	m_ZRotation(0.00),
	m_XMove(0.00),
	m_YMove(0.00),
	m_ZMove(0.00),
	m_XScale(6.00),
	m_YScale(6.00),
	m_ZScale(6.00)
{
	m_XRotation = right.m_XRotation;
	m_YRotation = right.m_YRotation;
	m_ZRotation = right.m_ZRotation;
	m_XMove = right.m_XMove;
	m_YMove = right.m_YMove;
	m_ZMove = right.m_ZMove;
	m_XScale = right.m_XScale;
	m_YScale = right.m_YScale;
	m_ZScale = right.m_ZScale;
	m_matRotation = right.m_matRotation;
	m_mModelLastRot = right.m_mModelLastRot;
	m_mModelRot = right.m_mModelRot;
}
//-----------------------------------------------------------------------------
Transform::~Transform()
{
}
//-----------------------------------------------------------------------------
Transform & Transform::operator=(const Transform &right)
{
	m_XRotation = right.m_XRotation;
	m_YRotation = right.m_YRotation;
	m_ZRotation = right.m_ZRotation;
	m_XMove = right.m_XMove;
	m_YMove = right.m_YMove;
	m_ZMove = right.m_ZMove;
	m_XScale = right.m_XScale;
	m_YScale = right.m_YScale;
	m_ZScale = right.m_ZScale;
	m_matRotation = right.m_matRotation;
	m_mModelLastRot = right.m_mModelLastRot;
	m_mModelRot = right.m_mModelRot;
	return *this;
}
//-----------------------------------------------------------------------------
int Transform::operator==(const Transform &right) const
{
	if(	fabs(m_XRotation - right.m_XRotation) >= 0.01 )
		return 0;
	if(	fabs(m_YRotation - right.m_YRotation) >= 0.01)
		return 0;
	if(	fabs(m_ZRotation - right.m_ZRotation) >= 0.01 )
		return 0;
	if(	fabs(m_XMove - right.m_XMove) >= 0.01 )
		return 0;
	if(	fabs(m_YMove - right.m_YMove) >= 0.01 )
		return 0;
	if(	fabs(m_ZMove - right.m_ZMove) >= 0.01 )
		return 0;
	if(	fabs(m_XScale - right.m_XScale) >= 0.01 )
		return 0;
	if(	fabs(m_YScale - right.m_YScale) >= 0.01 )
		return 0;
	if(	fabs(m_ZScale - right.m_ZScale) >= 0.01 )
		return 0;

	return 1;
}
//-----------------------------------------------------------------------------
int Transform::operator!=(const Transform &right) const
{
	if(*this == right)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
//-----------------------------------------------------------------------------
void Transform::move (double dx, double dy, double dz)
{
	this->m_XMove += dx;
	this->m_YMove += dy;
	this->m_ZMove += dz;
}
//-----------------------------------------------------------------------------
void Transform::rotate (Matrix4& matRotation )
{
	m_matRotation = matRotation ;//* m_matRotation;
}
//-----------------------------------------------------------------------------
double xtemp;
double ytemp;
double ztemp;
void Transform::rotate (double xangle, double yangle, double zangle)
{
//	Log* pLog = LogFactory::getLog(TEXT("abagraph"));
	this->m_XRotation = m_XRotation + xangle;
//	pLog->debug(TEXT("m_XRotation = %.2f"), m_XRotation);
	this->m_YRotation = m_YRotation + yangle;
//	pLog->debug(TEXT("m_YRotation = %.2f"), m_YRotation);
	this->m_ZRotation = m_ZRotation + zangle;
//	pLog->debug(TEXT("m_ZRotation = %.2f"), m_ZRotation);
	return;

	xtemp = xangle;
	ytemp = yangle;
	ztemp = zangle;

	if((m_XRotation + xangle)>6.28 ||
		(m_XRotation + xangle)<-6.28)
	{
		this->m_XRotation = this->m_XRotation + xtemp;
	}
	if((m_YRotation + yangle)>6.28 ||
		(m_YRotation + yangle)<-6.28)
	{
		this->m_YRotation = this->m_YRotation + ytemp;
	}
	if((m_ZRotation + zangle)>6.28 ||
		(m_ZRotation + zangle)<-6.28)
	{
		this->m_ZRotation = this->m_ZRotation + ztemp;
	}
	return;

xloop:
//	pLog->debug(TEXT("m_XRotation = %.2f"), m_XRotation);
	if(m_XRotation > 6.28f)
	{
		m_XRotation = m_XRotation - 6.28f;
		goto xloop;
	}
	if(m_XRotation < -6.28f)
	{
		m_XRotation = m_XRotation + 6.28f;
		goto xloop;
	}

//	this->m_YRotation = m_YRotation + yangle;
yloop:
//	pLog->debug(TEXT("m_YRotation = %.2f"), m_YRotation);
	if(m_YRotation > 6.28f)
	{
		m_YRotation = m_YRotation - 6.28f;
		goto yloop;
	}
	if(m_YRotation < -6.28f)
	{
		m_YRotation = m_YRotation + 6.28f;
		goto yloop;
	}
//	this->m_ZRotation = m_ZRotation + zangle;
zloop:
//	pLog->debug(TEXT("m_ZRotation = %.2f"), m_ZRotation);
	if(m_ZRotation > 6.28f)
	{
		m_ZRotation = m_ZRotation - 6.28f;
		goto zloop;
	}
	if(m_ZRotation < -6.28f)
	{
		m_ZRotation = m_ZRotation + 6.28f;
		goto zloop;
	}
}
//-----------------------------------------------------------------------------
void Transform::scale (double xscale, double yscale, double zscale)
{
	this->m_XScale *= xscale;
	this->m_YScale = m_XScale;
	this->m_ZScale = m_XScale;

	return;

/*
	if(1 < xscale)
	{
		this->m_XScale += 0.1;
		this->m_YScale += 0.1;
		this->m_ZScale += 0.1;
	}
	else
	{
		this->m_XScale += -0.1;
		this->m_YScale += -0.1;
		this->m_ZScale += -0.1;
	}

	return;
*/
	//
	// here we try to limit the scale 
	if(	(this->m_XScale += xscale) < -1.00)
	{
		this->m_XScale = 0.00;
	}
	else
	{
		this->m_XScale += xscale;
	}
	if(	(this->m_YScale += yscale) < -1.00)
	{
		this->m_YScale = 0.00;
	}
	else
	{
		this->m_YScale += yscale;
	}
	if(	(this->m_ZScale += zscale) < -1.00)
	{
		this->m_ZScale = 0.00;
	}
	else
	{
		this->m_ZScale += zscale;
	}
}
//-----------------------------------------------------------------------------
bool Transform::saveToFile (tfstream& out, int noTabs)
{
	tstring tabs = TEXT("");
	if(0 != noTabs)
	for(int i=0; i<noTabs; i++)
		tabs.append(TEXT("  "));

	__try
	{
		out << tabs << TEXT("Transform") << endl;
		out << tabs << TEXT("{\n");

		out << tabs << TEXT("  ") << TEXT("Move     ") << m_XMove << TEXT(" ") << m_YMove << TEXT(" ") 
					<< m_ZMove << TEXT(" ") << endl;
		out << tabs << TEXT("  ") << TEXT("Rotation ") << m_XRotation << TEXT(" ") << m_YRotation 
					<< TEXT(" ") << m_ZRotation << TEXT(" ") << endl;
		out << tabs << TEXT("  ") << TEXT("Scale    ") << m_XScale << TEXT(" ") << m_YScale 
					<< TEXT(" ") << m_ZScale << TEXT(" ") << endl;

		out << tabs << TEXT("}//Transform\n");
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		Util::casualException(GetExceptionCode(), TEXT(__FILE__), __LINE__);
		return false;
	}
	
	return true;
}
//-----------------------------------------------------------------------------
bool Transform::loadFromFile (tfstream& in)
{
	tstring temp;
	__try
	{
		in >> temp; //"Transform";
		in >> temp; //"{\n";
		in >> temp; //"Move: " << 
		in >> m_XMove >> m_YMove >> m_ZMove ;
		in >> temp; //"Rotation: "  
		in >> m_XRotation >> m_YRotation >> m_ZRotation ;
		in >> temp;//"Scale: "  
		in >> m_XScale >> m_YScale >> m_ZScale;
		m_XScale = m_XScale;
		m_YScale = m_YScale;
		m_ZScale = m_ZScale;
		in >> temp; //"}\n";
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		Util::casualException(GetExceptionCode(), TEXT(__FILE__), __LINE__);
		return false;
	}
	
	return true;

}
//-----------------------------------------------------------------------------
void Transform::normalRotation(Matrix4* pMatWorld )
{
//	D3DXMatrixIdentity (pMatWorld); 

    Matrix4 MatRot;   
    Matrix4 MatScale;  
  //  D3DXMatrixIdentity(&MatRot);
 
	applyMove(pMatWorld);

	applyRotation(&MatRot);
    //D3DXMatrixMultiply(pMatWorld, &MatRot, pMatWorld);

	applyScale(&MatScale);
//    D3DXMatrixMultiply(pMatWorld, &MatScale, pMatWorld);
}
//-----------------------------------------------------------------------------
void Transform::arcballRotation(Matrix4* pMatWorld )
{
//	D3DXMatrixIdentity (pMatWorld); 

    Matrix4 MatScale;   // Final scale matrix, applied to 
  //  D3DXMatrixTranslation(pMatWorld, (float)m_XMove, (float)m_YMove, (float)m_ZMove);

//	*pMatWorld = m_matRotation * (*pMatWorld);

	applyScale(&MatScale);
//	gltbMatrix(); //scene rotation
    //D3DXMatrixMultiply(pMatWorld, &MatScale, pMatWorld);
}
//-----------------------------------------------------------------------------
void Transform::apply (Matrix4* pMatWorld )
{
	//this should be here, refer to DrawModel
//  glTranslatef(0.0, 0.0, -3.0);
//	glTranslatef(pan_x, pan_y, 0.0);
	glScalef(4.0, 4.0, 4.0);
	//gltbMatrix(); //scene rotation

	//this is oldish now from D3D
	return normalRotation(pMatWorld);
//	return arcballRotation(pMatWorld);
}
//-----------------------------------------------------------------------------
void Transform::applyMove(Matrix4* matrixMove )
{
//	D3DXMatrixTranslation(matrixMove, (float)m_XMove, (float)m_YMove, (float)m_ZMove);
}
//-----------------------------------------------------------------------------
void Transform::applyRotation (Matrix4* matrixRotation )
{
	//we should use D3DXMatrixTransformation here, probably,
	//but YawPitchRoll looks fine till now.
//	D3DXMatrixRotationYawPitchRoll(	matrixRotation,
//									(float)((m_YRotation)/360*2*D3DX_PI),
//									(float)((m_XRotation)/360*2*D3DX_PI),
//									(float)((m_ZRotation)/360*2*D3DX_PI));
}
//-----------------------------------------------------------------------------
void Transform::applyScale (Matrix4* matrixScaling )
{
//	D3DXMatrixScaling(matrixScaling, (float)m_XScale, (float)m_YScale, (float)m_ZScale);
}
//-----------------------------------------------------------------------------
void Transform::rotatePoint (Vector3& input, 
							double dx, 
							double dy, 
							double dz, 
							Vector3* output, 
							double centerX, 
							double centerY, 
							double centerZ)
{
}
//-----------------------------------------------------------------------------
void Transform::scalePoint (Vector3& input, 
							double dx, 
							double dy, 
							double dz, 
							Vector3* output, 
							double centerX, 
							double centerY, 
							double centerZ)
{
	// ------------------------------------------------------------
	// in the case when the center is at the origin 
	// this is just a normal transform
	//
	// x = xcenter + (xpoint-xcenter)*scaleFactor
	//
	// ------------------------------------------------------------
	float x = 0.00; 
	float y = 0.00;
	float z = 0.00;
	x = input.m_X - (float)centerX;
	y = input.m_Y - (float)centerY;
	z = input.m_Z - (float)centerZ;
	output->m_X = x*(float)(dx) + (float)centerX;
	output->m_Y = y*(float)(dy) + (float)centerY;
	output->m_Z = z*(float)(dz) + (float)centerZ;
}
//-----------------------------------------------------------------------------
void Transform::getPointRelativeCoordinates (
							Vector3 input, 
							Vector3* output, 
							double centerX, 
							double centerY, 
							double centerZ)
{
	Vector3 point3;
	double x = 0.00;
	double y = 0.00;
	double z = 0.00;
	x = input.m_X;
	y = input.m_Y;
	z = input.m_Z;
	//now apply the transforms to the point
	this->rotatePoint(	input, 
						this->m_XRotation,
						this->m_YRotation,
						this->m_ZRotation,
						output);
}
//-----------------------------------------------------------------------------
} // namespace objectinterfacelib
//-----------------------------------------------------------------------------




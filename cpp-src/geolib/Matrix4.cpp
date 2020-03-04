//-----------------------------------------------------------------------------
//
// Source file: geolib\Matrix4.cpp
//
//-----------------------------------------------------------------------------
#include "stdafx.h"
#include <math.h>
#include "geolib\Matrix4.h"
#define SMALL_NUMBER 1.e-8
//-----------------------------------------------------------------------------
namespace geolib {
//-----------------------------------------------------------------------------
Matrix4::Matrix4()
{
	try
	{
		for(int i=0; i<4; i++)
		  for(int j=0; j<4; j++)
			  m_Element[i][j] = 0.00;
	}
	catch(exception e)
	{
		//Log->error("exception in Matrix::Matrix, message = %s", e.what());
		throw e;
	}
}
//-----------------------------------------------------------------------------
Matrix4::Matrix4(const Matrix4 &right)
{
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
		{
			m_Element[i][j] = right.m_Element[i][j];
		}
	}
}
//-----------------------------------------------------------------------------
Matrix4::~Matrix4()
{
}
//-----------------------------------------------------------------------------
Matrix4 & Matrix4::operator=(const Matrix4 &right)
{
	return *this;
}
//-----------------------------------------------------------------------------
void Matrix4::inverse (Matrix4* in, Matrix4* out)
{
	int i, j;
	double det;// det4x4();

	/* calculate the adjoint matrix */
	try
	{
		adjoint( in, out );
	}
	catch(exception e)
	{
		throw e;
	}
	/*  calculate the 4x4 determinant
	 *  if the determinant is zero, 
	 *  then the inverse matrix is not unique.
	 */

	det = det4x4( in );

	if ( fabs( det ) < SMALL_NUMBER) 
	{
		throw exception("Non-singular matrix, no inverse!");
	}

	/* scale the adjoint matrix to get the inverse */
	try
	{
		for (i=0; i<4; i++)
			for(j=0; j<4; j++)
				out->m_Element[i][j] = out->m_Element[i][j] / det;
	}
	catch(exception e)
	{
		throw e;
	}
}
//-----------------------------------------------------------------------------
  double Matrix4::det4x4 (Matrix4* in)
  {
    double ans;
    double a1, a2, a3, a4, b1, b2, b3, b4, c1, c2, c3, c4, d1, d2, d3, d4;

	try
	{
		a1 = in->m_Element[0][0]; b1 = in->m_Element[0][1]; 
		c1 = in->m_Element[0][2]; d1 = in->m_Element[0][3];

		a2 = in->m_Element[1][0]; b2 = in->m_Element[1][1]; 
		c2 = in->m_Element[1][2]; d2 = in->m_Element[1][3];

		a3 = in->m_Element[2][0]; b3 = in->m_Element[2][1]; 
		c3 = in->m_Element[2][2]; d3 = in->m_Element[2][3];

		a4 = in->m_Element[3][0]; b4 = in->m_Element[3][1]; 
		c4 = in->m_Element[3][2]; d4 = in->m_Element[3][3];

		ans = a1 * det3x3( b2, b3, b4, c2, c3, c4, d2, d3, d4)
			- b1 * det3x3( a2, a3, a4, c2, c3, c4, d2, d3, d4)
			+ c1 * det3x3( a2, a3, a4, b2, b3, b4, d2, d3, d4)
			- d1 * det3x3( a2, a3, a4, b2, b3, b4, c2, c3, c4);
	}
	catch(exception e)
	{
		//Log->error("exception in Matrix::det4x4, message = %s", e.what());
		throw e;
	}

	return ans;
  }
//-----------------------------------------------------------------------------
double Matrix4::det3x3 (double a1, double a2, double a3, 
						double b1, double b2, double b3, 
						double c1, double c2, double c3)
{
	double ans;

	try
	{
		ans = a1 * det2x2( b2, b3, c2, c3 )
			- b1 * det2x2( a2, a3, c2, c3 )
			+ c1 * det2x2( a2, a3, b2, b3 );
	}
	catch(exception e)
	{
		//Log->error("exception in Matrix::det3x3, message = %s", e.what());
		throw e;
	}

	return ans;
}
//-----------------------------------------------------------------------------
double Matrix4::det2x2 (double a, double b, double c, double d)
{
	double ans;
	ans = a * d - b * c;

	return ans;
}
//-----------------------------------------------------------------------------
void Matrix4::adjoint (Matrix4* in, Matrix4* out)
{
	double a1, a2, a3, a4, b1, b2, b3, b4;
	double c1, c2, c3, c4, d1, d2, d3, d4;

	try
	{
		a1 = in->m_Element[0][0]; b1 = in->m_Element[0][1]; 
		c1 = in->m_Element[0][2]; d1 = in->m_Element[0][3];

		a2 = in->m_Element[1][0]; b2 = in->m_Element[1][1]; 
		c2 = in->m_Element[1][2]; d2 = in->m_Element[1][3];

		a3 = in->m_Element[2][0]; b3 = in->m_Element[2][1];
		c3 = in->m_Element[2][2]; d3 = in->m_Element[2][3];

		a4 = in->m_Element[3][0]; b4 = in->m_Element[3][1]; 
		c4 = in->m_Element[3][2]; d4 = in->m_Element[3][3];


		/* row column labeling reversed since we transpose rows & columns */

		out->m_Element[0][0]  =   det3x3( b2, b3, b4, c2, c3, c4, d2, d3, d4);
		out->m_Element[1][0]  = - det3x3( a2, a3, a4, c2, c3, c4, d2, d3, d4);
		out->m_Element[2][0]  =   det3x3( a2, a3, a4, b2, b3, b4, d2, d3, d4);
		out->m_Element[3][0]  = - det3x3( a2, a3, a4, b2, b3, b4, c2, c3, c4);
	    
		out->m_Element[0][1]  = - det3x3( b1, b3, b4, c1, c3, c4, d1, d3, d4);
		out->m_Element[1][1]  =   det3x3( a1, a3, a4, c1, c3, c4, d1, d3, d4);
		out->m_Element[2][1]  = - det3x3( a1, a3, a4, b1, b3, b4, d1, d3, d4);
		out->m_Element[3][1]  =   det3x3( a1, a3, a4, b1, b3, b4, c1, c3, c4);
	    
		out->m_Element[0][2]  =   det3x3( b1, b2, b4, c1, c2, c4, d1, d2, d4);
		out->m_Element[1][2]  = - det3x3( a1, a2, a4, c1, c2, c4, d1, d2, d4);
		out->m_Element[2][2]  =   det3x3( a1, a2, a4, b1, b2, b4, d1, d2, d4);
		out->m_Element[3][2]  = - det3x3( a1, a2, a4, b1, b2, b4, c1, c2, c4);
	    
		out->m_Element[0][3]  = - det3x3( b1, b2, b3, c1, c2, c3, d1, d2, d3);
		out->m_Element[1][3]  =   det3x3( a1, a2, a3, c1, c2, c3, d1, d2, d3);
		out->m_Element[2][3]  = - det3x3( a1, a2, a3, b1, b2, b3, d1, d2, d3);
		out->m_Element[3][3]  =   det3x3( a1, a2, a3, b1, b2, b3, c1, c2, c3);
	}
	catch(exception e)
	{
		//Log->error("Matrix::inverse(): exception3");
		throw e;
	}
}
//-----------------------------------------------------------------------------
void Matrix4::setElement (int i, int j, double value)
{
	//------------------------------------------------------------
	//here we should assert that i and j are between 0 and 3
	//------------------------------------------------------------
	if(!(i>=0 && j>=0 && i<=3 && j<=3))
		throw exception("index out of range");

	m_Element[i][j] = value;
}
//-----------------------------------------------------------------------------
void Matrix4::set (double n16value[16])
{
	//--------------------------------------------------------
	//set the one dimension in 2 dimensions, columns, rows
	//--------------------------------------------------------
	try
	{
		int k=0;
		for (int i =0; i<4; i++)
			for(int j=0; j<4; j++)
			{
				m_Element[i][j] = n16value[k];
				k++;
			}
	}
	catch(exception e)
	{
		throw e;
	}
}
//-----------------------------------------------------------------------------
bool Matrix4::saveToFile (fstream& out, int noTabs)
{
	int k=0;
	try
	{
		out << "Matrix4: \n" ;
		for (int i =0; i<4; i++)
		{
			for(int j=0; j<4; j++)
			{
				out << m_Element[i][j] << " ";
			}
			out << endl;
		}
	}
	catch(exception e)
	{
		throw e;
	}

	return true;
}
//-----------------------------------------------------------------------------
bool Matrix4::loadFromFile (fstream& in)
{
	string temp;
	try
	{
		in >> temp; // "Matrix4: "
		for (int i =0; i<4; i++)
		{
			for(int j=0; j<4; j++)
			{
				in >> m_Element[i][j];
			}
		}
	}
	catch(exception e)
	{
		throw e; 
	}

	return true;
}
//-----------------------------------------------------------------------------
} // namespace geolib
//-----------------------------------------------------------------------------

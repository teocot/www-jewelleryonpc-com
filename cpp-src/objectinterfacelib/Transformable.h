//-----------------------------------------------------------------------------
// File Transformable.h
//-----------------------------------------------------------------------------
#pragma once
#pragma warning(disable : 4530)
#include "../memorylib\RefCount.h"
#include "../memorylib\gc_ptr.h"
using namespace memorylib;
#include "Transform.h"
//-----------------------------------------------------------------------------

namespace objectinterfacelib 
{
//-----------------------------------------------------------------------------

	class Transformable : public RefCount
    {

	public:
        Transform m_Transform;
        Transformable();
        Transformable(const Transformable &right);
        virtual ~Transformable();      
        Transformable & operator=(const Transformable &right);
      
        int operator==(const Transformable &right) const;
        int operator!=(const Transformable &right) const;
        
        virtual void	move (double dx, double dy, double dz) = 0;
        virtual void	rotate (double rx, double ry, double rz) = 0;
		virtual void	rotate (Matrix4& m_matRotation) {};
		virtual	bool	boundingSphereRadius(float& radius)=0;
        virtual void	scale (double sx, double sy, double sz) = 0;
        virtual Transform getTransform ();
		virtual bool	isSelected ()=0;
		virtual void	select (bool value = true)=0;
        virtual int		getToken () = 0;
        virtual long	getId () = 0;
        virtual int		getPartIndex () = 0;
        virtual Vector3 getCenter () = 0;
        virtual string	toString ();
        
  };
//-----------------------------------------------------------------------------

} // namespace objectinterfacelib
//-----------------------------------------------------------------------------


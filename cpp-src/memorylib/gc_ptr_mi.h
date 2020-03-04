
//
// we can't use the standard RefCount for 
// classes that uses multiple inheritance from 
// a base RefCount or derived
//
// the easiest way is to implement another 
// RefCount named RefCountMi just for these
//
//

#include "../memorylib/RefCountMi.h"
#pragma once


namespace memorylib 
{
template <class T> class gc_ptr_mi 
{
private:
    RefCountMi* m_RefCountMi;
//---------------------------------------------------------------
    void set(RefCountMi* refCountMi)
    {
        if(refCountMi != NULL) 
		{
			refCountMi->addReference();
		}
        RefCountMi* oldref = m_RefCountMi;
        m_RefCountMi = refCountMi;
        if(oldref != NULL)
		{
			oldref->removeReference();
		}
    }
public:
//---------------------------------------------------------------
    gc_ptr_mi()
    {
        m_RefCountMi = NULL;
    }
//---------------------------------------------------------------
    gc_ptr_mi(T * ptr)
    {
        m_RefCountMi = 0;//NULL;
        set((RefCountMi*)ptr);
    }
//---------------------------------------------------------------
    gc_ptr_mi(const gc_ptr_mi &gc)
    {
        m_RefCountMi = NULL;
        set(gc.m_RefCountMi);
    }
//---------------------------------------------------------------
    virtual ~gc_ptr_mi()
    {
        set((RefCountMi*)NULL);
    }

//---------------------------------------------------------------
    T *getObject() const
    {
        if(m_RefCountMi==NULL) return NULL;
        return static_cast<T*> (m_RefCountMi->getObject());
    }
//---------------------------------------------------------------
    gc_ptr_mi & operator = (const gc_ptr_mi &gc) 
	{
		set(gc.m_RefCountMi); 
		return *this;
	}
//---------------------------------------------------------------
    gc_ptr_mi & operator = (T * ptr) 
	{
		set((RefCountMi*)ptr); 
		return *this;
	}
//---------------------------------------------------------------
    T * operator ->()
    {
#ifdef _ASSERT
        _ASSERT(getObject()!=NULL);
#endif
        return static_cast<T*> (getObject());
    }
//---------------------------------------------------------------
    // conversion to T* (for function calls)
    operator T* () const
    {
        return getObject();
    }
//---------------------------------------------------------------
    bool operator !()
    {
        return getObject()==NULL;
    }
//---------------------------------------------------------------
    bool operator ==(const gc_ptr_mi &gc)
    {
        return getObject()==gc.getObject();
    }
//---------------------------------------------------------------
    bool operator !=(const gc_ptr_mi &gc)
    {
        return getObject()!=gc.getObject();
    }
};
}


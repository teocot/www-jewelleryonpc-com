
#pragma once

#include "RefCount.h"

//---------------------------------------------------------------
// gc_ptr
// Usage:
// ----------------------
// 1. In a program block
// ----------------------
// gc_ptr<CMyObject> ptr1(new CMyObject); // creates object 1
// gc_ptr<CMyObject> ptr2(new CMyObject); // creates object 2
// ptr1 = ptr2;             // destroys object 1
// ptr2 = NULL;
// ptr1 = new CMyObject;    // creates object 3, destroys object 2
// never use it unless you check for null:
// if(NULL != ptr1.getObject()) then do anything else
// ptr1->methodcall(...);
// CMyObject o1;
// // ptr1 = &o1;  // DON'T ! only memory allocated by new operator should be used
// CMyObject *o2 = new CMyObject;
// ptr1 = o2;
// //ptr2 = o2;  // DON'T ! unless CMyObject implements ref_count
//               // try to use ptr1 = ptr2 instead, it's always safe;
// ----------------------
// 2. in a function call
// ----------------------
// void f(CMyObject *o) {...} or
// VERY IMPORTAT
// void f(gc_ptr<CMyObject> *o) {...}
// ...
// gc_ptr<CMyObject> ptr(new CMyObject)
// f(ptr);
// or
// ----------------------
// 3. As a return value
// ----------------------
// gc_ptr<CMyObject> f()
// {
//      gc_ptr<CMyObject> ptr(new CMyObject);
//      return ptr;
// }
//---------------------------------------------------------------
namespace memorylib 
{
//---------------------------------------------------------------
template <class T> class gc_ptr 
{
private:
    RefCount* m_refcount;
//---------------------------------------------------------------
    void set(RefCount* refcount)
    {
        if(refcount != NULL)
		{
			refcount->addReference();
		}
        RefCount* oldref = m_refcount;
        m_refcount = refcount;
        if(oldref != NULL)
		{
			oldref->removeReference();
		}
    }
public:
//---------------------------------------------------------------
    gc_ptr()
    {
        m_refcount = NULL;
    }
//---------------------------------------------------------------
    gc_ptr(T * ptr)
    {
        m_refcount = NULL;
        set((RefCount*)ptr);
    }
//---------------------------------------------------------------
    gc_ptr(const gc_ptr &gc)
    {
        m_refcount = NULL;
        set(gc.m_refcount);
    }
//---------------------------------------------------------------
    virtual ~gc_ptr()
    {
        set((RefCount*)NULL);
    }

//---------------------------------------------------------------
    T *getObject() const
    {
        if(m_refcount==NULL) return NULL;
        return static_cast<T*> (m_refcount->getObject());
    }
//---------------------------------------------------------------
    gc_ptr & operator = (const gc_ptr &gc) 
	{
		set(gc.m_refcount); 
		return *this;
	}
//---------------------------------------------------------------
    gc_ptr & operator = (T * ptr) 
	{
		set((RefCount*)ptr); 
		return *this;
	}
//---------------------------------------------------------------
// never use it unless you check for null:
// if(NULL != ptr1.getObject()) then do anything else
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
    bool operator ==(const gc_ptr &gc)
    {
        return getObject() == gc.getObject();
    }
//---------------------------------------------------------------
    bool operator !=(const gc_ptr &gc)
    {
        return getObject()!=gc.getObject();
    }
//---------------------------------------------------------------
	//this is usefull if we use sets of the pointer
    bool operator <(const gc_ptr &gc) const
    {
        return getObject() < gc.getObject();
    }
};
}


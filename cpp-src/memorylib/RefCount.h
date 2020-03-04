#ifndef _REF_COUNT_H_
#define _REF_COUNT_H_

#pragma once
namespace memorylib
{

class RefCount 
{
    int m_NoReferences;
public:
//---------------------------------------------------------------
    virtual void addReference() 
    {
        m_NoReferences++; 
    }
//---------------------------------------------------------------
    virtual void removeReference()
    {
        m_NoReferences--;
        if(m_NoReferences<=0)
        {
            deleteReference();
        }
    }
//---------------------------------------------------------------
    virtual RefCount* getObject() const
    {
        return (RefCount*)this;
    }
//---------------------------------------------------------------
    virtual void deleteReference() 
    {
		delete getObject();
    }
public:
//---------------------------------------------------------------
	virtual int getNoReferences()
	{
		return m_NoReferences;
	}

protected:
//---------------------------------------------------------------
    RefCount()
    {
        m_NoReferences = 0;
    }
//---------------------------------------------------------------
    virtual ~RefCount()
	{
        m_NoReferences = 0;
	}
};
}//memorylib namespace
//---------------------------------------------------------------
#endif

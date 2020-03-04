#pragma once

//---------------------------------------------------------------
namespace memorylib
{

class RefCountMi
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
    virtual RefCountMi* getObject() const
    {
        return (RefCountMi*)this;
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
    RefCountMi()
    {
        m_NoReferences = 0;
    }
    virtual ~RefCountMi()
	{
        m_NoReferences = 0;
	};
//---------------------------------------------------------------
};
}//namespace memorylib
//---------------------------------------------------------------

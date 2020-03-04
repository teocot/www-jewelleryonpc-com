#pragma once

#include "../memorylib/RefCount.h"
#include <string>
using namespace std;

#pragma once

namespace memorylib
{

class CSmartChar : public memorylib::RefCount
{
public:
	static string pn() { return ("ringonpcbirthstone");}
	static string pv() { return ("1.0");}

private:
	char* m_buffer;

public:
	CSmartChar(void);
	char* getChar() const;
	void setChar(const char* valueBuffer);

public:
	virtual ~CSmartChar(void);
};

}//namespace memorylib


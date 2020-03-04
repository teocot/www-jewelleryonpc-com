//-----------------------------------------------------------------------------
//
// Source file: c:\dev\src\opengllib\Ortho3D.h
//
//-----------------------------------------------------------------------------
#ifndef _ORTHO3D_H_
#define _ORTHO3D_H_ 
//-----------------------------------------------------------------------------
namespace opengllib {
//-----------------------------------------------------------------------------
class Ortho3D 
{
public:
    Ortho3D();
    virtual ~Ortho3D();
private:
    Ortho3D(const Ortho3D &right);
    Ortho3D & operator=(const Ortho3D &right);
public:
	void apply ();
    void reshape (int w, int h);
    bool saveToFile (fstream& out, int noTabs);
    bool loadFromFile (fstream& in);

	//attributes are used directly for performance
	double m_Left;
    double m_Right;
    double m_Bottom;
    double m_Top;
    double m_Near;
    double m_Far;
};
//-----------------------------------------------------------------------------
} // namespace opengllib
//-----------------------------------------------------------------------------
#endif//_ORTHO3D_H_

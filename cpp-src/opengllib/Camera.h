//-----------------------------------------------------------------------------
//
// Source file: c:\dev\src\opengllib\Camera.h
//
//-----------------------------------------------------------------------------
#ifndef _CAMERA_H_
#define _CAMERA_H_
//-----------------------------------------------------------------------------
#include <windows.h>
#include <gl/gl.h>
#include <geolib/Point3.h>
#include <geolib/Vector3.h>
using namespace geolib;
//-----------------------------------------------------------------------------
namespace opengllib {
//-----------------------------------------------------------------------------
class Camera 
{
//-----------------------------------------------------------------------------
public:
    Camera();
    virtual ~Camera();
private:
    Camera(const Camera &right);
    Camera & operator=(const Camera &right);
public:
    void shot ();
    void set (Point3& eye, Point3& center, Vector3& up);
    void set (double eyex, double eyey, double eyez, double centerx, double centery, double centerz, double upx, double upy, double upz);
    void getEyePoint (Point3& eyePoint);

    //	this one turns the camera with angle to the Left
    //
    //	The center changes. with an arc of angle, at the
    //	distance d=(eye-center).
    //
    //	the formula might be complicated. The up coordinate
    //	remains unchanged, the other coordinates change.
    //
    //	Maybe we can use some openGL calls in all this using the
    //	reverse of the MODELVIEW matrix.
    void turnLeft (double angle);

    //	just move parallel to the left, doesn't turn the eye,
    //	just the body moves to the left
    void slideLeft (double distance);

    //	just move parallel to the right, doesn't turn the eye,
    //	just the body moves to the right
    void slideRight (double distance);

    //	bow the camera, change in view angle.
    //	the vertical changes here.
    void turnUp (double angle);

    //	same with turn up, but angle is oposite
    void turnDown (double angle);
    void turnRight (double angle);

    //	This one does change the eye and the center position,
    //	such that the view axis is parallel to what we had
    //	before.
    //
    //	The camera doesn't change the view angle here.
    //
    //	but then we need to decide if we want to keep the center
    //	fix or not.
    //
    //	the eye and the center plus "distance" parallel to the
    //	Up vector.
    //
    //	If the up vector has 0.0, 1.0, 0.0 ( the default), then
    //	eyeY = eyeY+distance and centerY = centerY + distance.
    void slideUp (double distance);

    //	same with up, but minus distance
    void slideDown (double distance);
    void slideForward (double distance);
    void slideBack (double distance);
    void slideForwardFixTarget (double distance);
    void slideBackFixTarget (double distance);
    void slideUpFixTarget (double distance);
    void slideDownFixTarget (double distance);
    void slideLeftFixTarget (double distance);
    void slideRightFixTarget (double distance);
    void turnOpen (double angle);
    void turnClose (double angle);
    //	this will draw the viewing volume, and a sphere at the
    //	origin, or the 3 vectors, so we can see the as of view
    void draw ();
  // Data Members for Class Attributes
    double m_Eyex;
    double m_Eyey;
    double m_Eyez;
    double m_Centerx;
    double m_Centery;
    double m_Centerz;
    double m_Upx;
    double m_Upy;
    double m_Upz;
    tstring m_Name;
    bool m_Active;
    bool m_HasFixTarget;
};
//-----------------------------------------------------------------------------
} // namespace opengllib
//-----------------------------------------------------------------------------
#endif //_CAMERA_H_


// Source file: c:\dev\src\opengllib\Cameras.h

#ifndef Cameras_h
#define Cameras_h 1

#include <iostream>
#include <string>
#include <list>
#include "opengllib\Camera.h"

namespace opengllib {
  class Cameras 
  {
	static Cameras* m_Cameras;
    private:
        Cameras();
  private:
        Cameras(const Cameras &right);
        Cameras & operator=(const Cameras &right);
  public:
		static Cameras* getStaticInstance();
        virtual ~Cameras();
		bool saveToFile (wfstream& out, int noTabs);
	    bool loadFromFile (wfstream& out);
        Camera* getCamera (tstring cameraName);
        void addCamera (Camera* camera);
        void draw ();
        void buildDefaultCameras ();
        list<Camera*> m_CameraList;
        list<Camera*>::iterator m_CameraListIterator;
        bool m_DefaultCamerasBuilt;
    private:
        void buildLeftCamera ();
        void buildRightCamera ();
        void buildTopCamera ();
        void buildBottomCamera ();
        void buildFrontCamera ();
        void buildBackCamera ();
        void buildPerspectiveCamera ();
        bool getDefaultCamerasBuilt ();
        void setDefaultCamerasBuilt (bool value);
  };

} // namespace opengllib
#endif

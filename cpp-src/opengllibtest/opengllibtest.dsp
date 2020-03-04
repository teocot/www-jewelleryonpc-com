# Microsoft Developer Studio Project File - Name="opengllibtest" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=opengllibtest - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "opengllibtest.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "opengllibtest.mak" CFG="opengllibtest - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "opengllibtest - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "opengllibtest - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "opengllibtest - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
F90=df.exe
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x1409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x1409 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 cppunit.lib testrunner.lib glu32.lib opengl32.lib /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "opengllibtest - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
F90=df.exe
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x1409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x1409 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 cppunitd.lib testrunnerd.lib glu32.lib opengl32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "opengllibtest - Win32 Release"
# Name "opengllibtest - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\ChildView.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\opengllibtest.cpp
# End Source File
# Begin Source File

SOURCE=.\opengllibtest.rc
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\TestAntialias.cpp
# End Source File
# Begin Source File

SOURCE=.\TestBlending.cpp
# End Source File
# Begin Source File

SOURCE=.\TestCamera.cpp
# End Source File
# Begin Source File

SOURCE=.\TestCameras.cpp
# End Source File
# Begin Source File

SOURCE=.\TestColor.cpp
# End Source File
# Begin Source File

SOURCE=.\TestLight.cpp
# End Source File
# Begin Source File

SOURCE=.\TestLightModel.cpp
# End Source File
# Begin Source File

SOURCE=.\TestLights.cpp
# End Source File
# Begin Source File

SOURCE=.\TestMaterial.cpp
# End Source File
# Begin Source File

SOURCE=.\TestMaterialList.cpp
# End Source File
# Begin Source File

SOURCE=.\TestNormal3f.cpp
# End Source File
# Begin Source File

SOURCE=.\TestOrtho2D.cpp
# End Source File
# Begin Source File

SOURCE=.\TestOrtho3D.cpp
# End Source File
# Begin Source File

SOURCE=.\TestPerspective.cpp
# End Source File
# Begin Source File

SOURCE=.\TestPerspective1Point.cpp
# End Source File
# Begin Source File

SOURCE=.\TestPixel.cpp
# End Source File
# Begin Source File

SOURCE=.\TestPixelMap.cpp
# End Source File
# Begin Source File

SOURCE=.\TestQuad.cpp
# End Source File
# Begin Source File

SOURCE=.\TestShadeModel.cpp
# End Source File
# Begin Source File

SOURCE=.\TestTexture.cpp
# End Source File
# Begin Source File

SOURCE=.\TestTextureImage.cpp
# End Source File
# Begin Source File

SOURCE=.\TestTextures.cpp
# End Source File
# Begin Source File

SOURCE=.\TestTransform.cpp
# End Source File
# Begin Source File

SOURCE=.\TestUnproject.cpp
# End Source File
# Begin Source File

SOURCE=.\TestVertex3f.cpp
# End Source File
# Begin Source File

SOURCE=.\TestViewport.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\ChildView.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\opengllibtest.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\TestAntialias.h
# End Source File
# Begin Source File

SOURCE=.\TestBlending.h
# End Source File
# Begin Source File

SOURCE=.\TestCamera.h
# End Source File
# Begin Source File

SOURCE=.\TestCameras.h
# End Source File
# Begin Source File

SOURCE=.\TestColor.h
# End Source File
# Begin Source File

SOURCE=.\TestLight.h
# End Source File
# Begin Source File

SOURCE=.\TestLightModel.h
# End Source File
# Begin Source File

SOURCE=.\TestLights.h
# End Source File
# Begin Source File

SOURCE=.\TestMaterial.h
# End Source File
# Begin Source File

SOURCE=.\TestMaterialList.h
# End Source File
# Begin Source File

SOURCE=.\TestNormal3f.h
# End Source File
# Begin Source File

SOURCE=.\TestOrtho2D.h
# End Source File
# Begin Source File

SOURCE=.\TestOrtho3D.h
# End Source File
# Begin Source File

SOURCE=.\TestPerspective.h
# End Source File
# Begin Source File

SOURCE=.\TestPerspective1Point.h
# End Source File
# Begin Source File

SOURCE=.\TestPixel.h
# End Source File
# Begin Source File

SOURCE=.\TestPixelMap.h
# End Source File
# Begin Source File

SOURCE=.\TestQuad.h
# End Source File
# Begin Source File

SOURCE=.\TestShadeModel.h
# End Source File
# Begin Source File

SOURCE=.\TestTexture.h
# End Source File
# Begin Source File

SOURCE=.\TestTextureImage.h
# End Source File
# Begin Source File

SOURCE=.\TestTextures.h
# End Source File
# Begin Source File

SOURCE=.\TestTransform.h
# End Source File
# Begin Source File

SOURCE=.\TestUnproject.h
# End Source File
# Begin Source File

SOURCE=.\TestVertex3f.h
# End Source File
# Begin Source File

SOURCE=.\TestViewport.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\opengllibtest.ico
# End Source File
# Begin Source File

SOURCE=.\res\opengllibtest.rc2
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project

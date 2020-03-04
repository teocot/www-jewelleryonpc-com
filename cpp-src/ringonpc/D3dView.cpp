//-----------------------------------------------------------------------------
//
// FILE: CD3dView.cpp, CD3dView class implementation
// Copyright (C) 2007 Abacasoft limited
//
//-----------------------------------------------------------------------------
//
// TODO: reset the model to reinitialize the model when we 
// loose teh device. NOt to load the files again, but to recreate teh full
// image including the textures
//
//-----------------------------------------------------------------------------
#pragma warning(disable: 4995)
#pragma warning(disable: 4996)
#include "stdafx.h"
#include "D3dView.h"
#include "mainFrm.h"
#include <objectinterfacelib/Transformable.h>
using namespace objectinterfacelib;
#include <ringmodellib/Model.h>
#include <ringmodellib/StateManager.h>
using namespace ringmodellib;
#include <objectlib/Definitions.h>
using namespace objectlib;
#include <utillib/Util.h>
using namespace utillib;
#include "pipelinelib/gltb.h"
#pragma warning(default: 4995)
#pragma warning(default: 4996)
//-----------------------------------------------------------------------------
extern CMainFrame				mainFrame;
bool							bReset				= true;
//-----------------------------------------------------------------------------
//HRESULT initTextures();
HRESULT SetupSphereEnvMapTexGen();
// No textures mapping mode
HRESULT DisableTexGen();
HRESULT SetupTexGen(int m_iTexGen);
// Setup texture scale matrix to map from -1.0..1.0 to 0.0..1.0
VOID SetTextureScaleMatrix(Matrix4 &mat);
gc_ptr<PixelMap> g_pTexture;
Matrix4 m_matTexScale;
bool bTextureLoaded = false;
#define MAX_INTERSECTIONS 16
#define CAMERA_DISTANCE 20.5f
//-----------------------------------------------------------------------------
int CD3dView::xMotion = 0;
int CD3dView::yMotion = 0;
bool CD3dView::animate = false;
int CD3dView::lastx = 0;
int CD3dView::lasty = 0;
int CD3dView::deltax = 0;
int CD3dView::deltay = 0;
extern GLfloat  gltb_angle;
extern GLint    gltb_button;
extern GLuint   gltb_lasttime;
//-----------------------------------------------------------------------------
void SaveBitmapToFile( BYTE* pBitmapBits, LONG lWidth, LONG lHeight,
					  WORD wBitsPerPixel, LPCTSTR lpszFileName );
//-----------------------------------------------------------------------------
CD3dView::CD3dView() 
{
	m_bRightButtonDown = false;
	m_isPerspective = true;
}
//-----------------------------------------------------------------------------
CD3dView::~CD3dView()
{
	__try
	{
		if(NULL != m_hglRC)
		{
			wglDeleteContext(m_hglRC);
		}
		m_hglRC = NULL;
		if(::IsWindow(m_hWnd))
		{
			ReleaseDC(m_hDC);
		}
		wglMakeCurrent(NULL,NULL);
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
	}
}
//-----------------------------------------------------------------------------
BOOL CD3dView::OnIdle()
{
	Invalidate();
	return FALSE;
}
//-----------------------------------------------------------------------------
BOOL CD3dView::PreTranslateMessage(MSG* pMsg)
{
	pMsg;

	return FALSE;
}
//-----------------------------------------------------------------------------
CD3dView* pView = NULL;
void __cdecl animateThread(void* pModel);
HANDLE hThread;	
//-----------------------------------------------------------------------------
void CD3dView::animateWork()
{
	__try
	{
		if(animate)
		{
			pView = this;
			hThread = (HANDLE)_beginthread(animateThread, 0,  NULL);
			SetThreadPriority(hThread, THREAD_PRIORITY_LOWEST);
		}
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		_endthread();
		;//Util::casualException(GetExceptionCode(), TEXT(__FILE__), __LINE__);
	}
}
//-----------------------------------------------------------------------------
void __cdecl animateThread(void* pModel )
{
	__try
	{
		while(CD3dView::animate)
		{
			((Model*)pModel)->motion(CD3dView::xMotion, CD3dView::yMotion);
			if(::IsWindow(pView->m_hWnd))
			{
				pView->Invalidate();
			}
			//moved it in the model to aply to every refresh
			//even when moving, scaling rotating with the mouse
			::Sleep(40);
		}
		//this looks important, but it is not really.
		pView = NULL;

		_endthread();
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		;//Util::casualException(GetExceptionCode(), TEXT(__FILE__), __LINE__);
	}
}
//-----------------------------------------------------------------------------
LRESULT CD3dView::OnPaint(UINT /*uMsg*/, WPARAM /*wParam*/, 
						  LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	CPaintDC dc(m_hWnd);

	__try
	{
		//got slow down after 10,000 drawings
	//	wglMakeCurrent(::GetDC(m_hWnd)/*m_hDC*/,m_hglRC);
		//this one is fast and stady
		wglMakeCurrent(m_hDC,m_hglRC);
		//createWGLFont(m_hDC);

		draw(GL_RENDER);
		mainFrame.updateFpsPane();

		SwapBuffers(m_hDC);

	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		Util::criticalException(GetExceptionCode(), TEXT(__FILE__), __LINE__);
	}

	return 0;
}
//-----------------------------------------------------------------------------
bool CD3dView::saveScreenGrabAsTga(const char* filename) 
{
	GLint viewport[4];					
	glGetIntegerv(GL_VIEWPORT, viewport);	
	GLuint sw = viewport[2];
	GLuint sh = viewport[3];
	unsigned bpp = 4;
	GLenum   format  =  GL_RGBA;//(bpp==4) ? GL_RGBA : GL_RGB;

	// allocate memory to store image data
	unsigned char* pdata = new unsigned char[sw*sh*bpp];

	// read from front buffer
	glReadBuffer(GL_FRONT);
	glReadPixels(0,0,sw,sh,format,GL_UNSIGNED_BYTE,pdata);

	// write data as a tga file
	//not implemented now
//	bool ret = saveToTga("temp.tga",sw,sh,bpp,pdata);
	goto cleanup;

cleanup:
	delete [] pdata;
	return true;
}
//-----------------------------------------------------------------------------
void SaveBitmapToFile( BYTE* pBitmapBits, LONG lWidth, LONG lHeight,
					  WORD wBitsPerPixel, LPCTSTR lpszFileName )
{
    BITMAPINFOHEADER header = {0};
    header.biSize = sizeof(BITMAPINFOHEADER);
    header.biBitCount = wBitsPerPixel;
    header.biClrImportant = 0;
    header.biClrUsed = 0;
    header.biCompression = BI_RGB;
    header.biHeight = lHeight;
    header.biWidth = lWidth;
    header.biPlanes = 1;
    header.biSizeImage = lWidth* lHeight * (wBitsPerPixel/8);
    BITMAPFILEHEADER bfh = {0};
    bfh.bfType=0x4D42;
    bfh.bfOffBits = sizeof(BITMAPINFOHEADER) + sizeof(BITMAPFILEHEADER);
    bfh.bfSize = bfh.bfOffBits + header.biSizeImage;
    HANDLE hFile = CreateFile( lpszFileName,GENERIC_WRITE, 0,NULL,
                               CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL,NULL);

    if( !hFile ) 
    {
        return;
    }

    DWORD dwWritten = 0;
    WriteFile( hFile, &bfh, sizeof(bfh), &dwWritten , NULL );
    WriteFile( hFile, &header, sizeof(header), &dwWritten, NULL );
    WriteFile( hFile, pBitmapBits, header.biSizeImage, &dwWritten, NULL );
    CloseHandle( hFile );
}
//-----------------------------------------------------------------------------
//there are 2 ways to do it
// 1. with a temp file or iwht a bitmap in memory
// 2. then set the View member bitmap
// In this second case the image is upside down, so we reverse it
//
// In both cases the colors are reversed:
// anyway, in the bitmap the colors are reversed.
// instead of rgba we have bgr.
//-----------------------------------------------------------------------------
bool CD3dView::saveScreenGrabAsBmp(const char* filename) 
{
//	tstring strFileName = TEXT("temp.bmp");

	GLint viewport[4];					// Where The Viewport Values Will Be Stored

	//we have to make sure we print the main window not the little preview one from 
	//the tabs. HOw? we should paint once.
//	Invalidate();
	BOOL bHandled = FALSE;
	OnPaint(WM_PAINT, 0 , 0 , bHandled);

	glGetIntegerv(GL_VIEWPORT, viewport);	
	GLuint width = viewport[2];
	GLuint height = viewport[3];
	m_size.cx = width;
	m_size.cy = height;
	unsigned bpp = 4;
	GLenum   format  =  GL_RGBA;//(bpp==4) ? GL_RGBA : GL_RGB;

	// allocate memory to store image data
	BYTE* pdata = new BYTE[width*height*bpp];

//	this->draw();
	// read from front buffer
	glReadBuffer(GL_BACK);
	// read pixel data
	glReadPixels(0,0,width,height,format,GL_UNSIGNED_BYTE,pdata);
//	glReadPixels(0,height,width,height,format,GL_BYTE,pdata);

	BYTE* pdataRGB = new BYTE[width*height*4];
	int indexdata = 0;
	int indexdataRGB = 0;
	int indexdataReversed = 0;
	for(int y = 0; y < height; y++) //image is reversed
//	for(int y = height - 1 ; y >= 0; y--)
	{
		for (int x = 0; x < width; x++)
		{
			//for(int k = 0; k < 4; k++)
			{
				indexdata = 4*x + y*width*4;
				indexdataRGB = 3*x + y*width*3;
				indexdataReversed = 4*x + (height-y-1)*width*4;

				//this is one way upside down
//				pdataRGB[indexdata+2] = pdata[indexdata+0];
//				pdataRGB[indexdata+1] = pdata[indexdata+1];
//				pdataRGB[indexdata+0] = pdata[indexdata+2];
//				pdataRGB[indexdata+3] = pdata[indexdata+3];

				//this is the other way upside down
				//for some reason the bitmap is reversed on y
				pdataRGB[indexdataReversed+2] = pdata[indexdata+0];
				pdataRGB[indexdataReversed+1] = pdata[indexdata+1];
				pdataRGB[indexdataReversed+0] = pdata[indexdata+2];
				pdataRGB[indexdataReversed+3] = pdata[indexdata+3];

				//doesn't work with 3 colors only
//				pdataRGB[indexdataRGB+2] = pdata[indexdata+0];
//				pdataRGB[indexdataRGB+1] = pdata[indexdata+1];
//				pdataRGB[indexdataRGB+0] = pdata[indexdata+2];
			}
		}
	}


/*
	//--------------------------------------------------------------------
	// for testing we save to various files, but not necessary
	//---------------------------------------------------------------------
	//saves to file
	string stringFileName =  Util::tostring(strFileName.c_str(), 
											strFileName.length());
	this->saveScreenGrabAsTga(stringFileName.c_str());

	SaveBitmapToFile( pdataRGB,//BYTE* pBitmapBits, 
					  width, //LONG lWidth, 
					  height, //LONG lHeight,
					  32, //WORD wBitsPerPixel, 
					  strFileName.c_str());//LPCTSTR lpszFileName )

	HBITMAP hBmp = (HBITMAP)::LoadImage(NULL, strFileName.c_str(),
					IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	if(hBmp != NULL)
	{
		SetBitmap(hBmp);	
		return true;
	}

	goto cleanup;

	//this will create the bitmap
	LPBITMAPINFO lpbi = new BITMAPINFO;
    lpbi->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    lpbi->bmiHeader.biWidth = width;
    lpbi->bmiHeader.biHeight = height;
    lpbi->bmiHeader.biPlanes = 1;
    lpbi->bmiHeader.biBitCount = 32;
    lpbi->bmiHeader.biCompression = BI_RGB;
    lpbi->bmiHeader.biSizeImage = width * height * 4;
    lpbi->bmiHeader.biClrUsed = 0;
    lpbi->bmiHeader.biClrImportant = 0;
*/
	HBITMAP hBitmap = ::CreateBitmap(width, height, 1, 32, pdataRGB);
//    SetBitmapBits(hBitmap, width * height * 4, pdataRGB);
	this->SetBitmap(hBitmap);

	goto cleanup;

cleanup:
	// clean up
	delete [] pdata;
	delete [] pdataRGB;

	// done
	return true;
}
//-----------------------------------------------------------------------------
LRESULT CD3dView::OnCreate(UINT /*uMsg*/, WPARAM /*wParam*/, 
						   LPARAM /*lParam*/, BOOL& /*bHandled*/)
{

    m_hDC = ::GetDC(this->m_hWnd);

    if(!SetPixelformat(m_hDC))
    {
		::MessageBox(m_hWnd,TEXT("SetPixelformat Failed!"),
									TEXT("Error"),MB_OK);
		return -1;
    }

    m_hglRC = wglCreateContext(m_hDC);
    int i= wglMakeCurrent(m_hDC,m_hglRC);

	createWGLFont(m_hDC);

	InitGL();	

	pView = this;
	int return_value = 0;
	__try
	{
/*		HWND hWndCmdBar = m_CmdBar.Create(	m_hWnd, 
											rcDefault, 
											NULL, 
											ATL_SIMPLE_CMDBAR_PANE_STYLE);
		// attach menu, if we want a menu, look int main frame 
		// how this is done
	//	m_CmdBar.AttachMenu(GetMenu());
		// load command bar images, all we need for context menu
		m_CmdBar.LoadImages(IDR_MAINFRAME);
*/
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		Util::casualException(GetExceptionCode(), TEXT(__FILE__), __LINE__);
		return_value = -1;
		goto cleanup;
	}
cleanup:
	Model::m_View = this;
	return return_value;
}
//-----------------------------------------------------------------------------
LRESULT CD3dView::OnEraseBackground(UINT /*uMsg*/, WPARAM /*wParam*/, 
									LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
    return 0;	
}
//-----------------------------------------------------------------------------
LRESULT CD3dView::OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, 
							LPARAM /*lParam*/, BOOL& bHandled)
{
	wglDeleteContext(m_hglRC);
	m_hglRC = NULL;
	if(::IsWindow(m_hWnd))
	{
		ReleaseDC(m_hDC);
	}
	wglMakeCurrent(NULL,NULL);

	Model::m_View = NULL;

	return 0;
}
//-----------------------------------------------------------------------------
BOOL CD3dView::SetPixelformat(HDC hdc)
{

    PIXELFORMATDESCRIPTOR *ppfd; 
    int pixelformat; 
 
    PIXELFORMATDESCRIPTOR pfd = { 
    sizeof(PIXELFORMATDESCRIPTOR),  //  size of this pfd 
    1,                     // version number 
    PFD_DRAW_TO_WINDOW |   // support window 
    PFD_SUPPORT_OPENGL |   // support OpenGL 
    PFD_GENERIC_FORMAT |
    PFD_DOUBLEBUFFER   ,   // double buffered 
    PFD_TYPE_RGBA,         // RGBA type 
    32,                    // 24-bit color depth 
    0, 0, 0, 0, 0, 0,      // color bits ignored 
    8,                     // no alpha buffer 
    0,                     // shift bit ignored 
    8,                     // no accumulation buffer 
    0, 0, 0, 0,            // accum bits ignored 
    64,                    // 32-bit z-buffer	 
    8,                     // no stencil buffer 
    8,                     // no auxiliary buffer 
    PFD_MAIN_PLANE,        // main layer 
    0,                     // reserved 
    0, 0, 0                // layer masks ignored 
    }; 

	ppfd = &pfd;

	if ( (pixelformat = ChoosePixelFormat(hdc, ppfd)) == 0 ) 
    { 
		::MessageBox(m_hWnd, TEXT("ChoosePixelFormat failed"), 
							TEXT("Error"), MB_OK); 
        return FALSE; 
    } 
 
    if (SetPixelFormat(hdc, pixelformat, ppfd) == FALSE) 
    { 
        ::MessageBox(m_hWnd, TEXT("SetPixelFormat failed"), 
							TEXT("Error"), MB_OK); 
        return FALSE; 
    } 
 
    return TRUE; 

}
//-----------------------------------------------------------------------------
GLvoid CD3dView::ReSizeGLScene(GLsizei width, GLsizei height)	
{
	if (height == 0)										
	{
		height = 1;										
	}

	__try
	{
		Model::getStaticInstance()->resize(width, height);

		gltbReshape(width, height);
		glViewport(0, 0, width, height);
		this->m_Viewport.reshape(width, height);
	
		m_dAspect = (width == 0) ? (double)width : (double)width/(double)height;
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		Util::casualException(GetExceptionCode(), TEXT(__FILE__), __LINE__);
	}
}
//-----------------------------------------------------------------------------
int CD3dView::InitGL()							
{
    gltbInit(MOUSE_LEFT_BUTTON);
//	glEnable(GL_AUTO_NORMAL);
//	glEnable(GL_NORMALIZE);
	glEnable(GL_DEPTH_TEST); 
//	ToolRotateScene* aTool = ToolsFactory::getInstance()->getpToolRotateScene();
//	aTool->initArcball();

//	m_DrawModel.initGL();
	return TRUE;										
}
//-----------------------------------------------------------------------------
LRESULT CD3dView::OnSize(UINT uMsg, WPARAM wParam, 
						 LPARAM lParam, BOOL& bHandled)
{
	__try
	{
		ReSizeGLScene(LOWORD(lParam), HIWORD(lParam));
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		Util::casualException(GetExceptionCode(), TEXT(__FILE__), __LINE__);
	}

	__try
	{
		Model::getStaticInstance()->updateAllViews();
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		Util::casualException(GetExceptionCode(), TEXT(__FILE__), __LINE__);
	}
//	Invalidate();
	//this will just flicker
//    SwapBuffers(m_hDC);
	return 0;
}
//-----------------------------------------------------------------------------
void CD3dView::updateAllViews()
{
	//any updates appart this winodw update, will screw up the transforms
	//mostly the viewport.
	__try
	{
		draw();
		Invalidate();//this is okl
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		Util::casualException(GetExceptionCode(), TEXT(__FILE__), __LINE__);
	}

//	if(::IsWindow(mainFrame.m_view.m_hWnd))
//	{
//		mainFrame.m_view.Invalidate();
//	}
}
//-----------------------------------------------------------------------------
LRESULT CD3dView::OnCommandViewVolume(WORD /*wNotifyCode*/, WORD /*wID*/, 
									  HWND /*hWndCtl*/, BOOL& /*bHandled*/) 
{
	OpenglView::setState(GL_POLYGON);
	Invalidate();
	return 0;
}
//-----------------------------------------------------------------------------
LRESULT CD3dView::OnCommandViewEdge(WORD /*wNotifyCode*/, WORD /*wID*/, 
									HWND /*hWndCtl*/, BOOL& /*bHandled*/) 
{
	OpenglView::setState(DRAW_WIRE);
	Invalidate();
	return 0;
}
//-----------------------------------------------------------------------------
LRESULT CD3dView::OnCommandViewTexture(WORD /*wNotifyCode*/, WORD /*wID*/, 
									   HWND /*hWndCtl*/, BOOL& /*bHandled*/) 
{
	OpenglView::setState(DRAW_TEXTURE);
	Invalidate();
	return 0;
}
//-----------------------------------------------------------------------------
LRESULT CD3dView::OnCommandPropertiesGridOn(WORD /*wNotifyCode*/, WORD /*wID*/, 
											HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	((OpenglView*)this)->m_DrawGrid = !((OpenglView*)this)->m_DrawGrid ;
	return 0;
}
//-----------------------------------------------------------------------------
LRESULT CD3dView::OnCommandViewBackColor(WORD /*wNotifyCode*/, WORD /*wID*/, 
										 HWND /*hWndCtl*/, BOOL& /*bHandled*/) 
{
	bool isAnimated = animate;
	CD3dView::animate = false;

	int return_value = 0;
	CColorDialog dlgColorChoice;
	BYTE red,green, blue;

	red   = 255 * (int) Model::s_BackColor.m_Red;
	green = 255 * (int) Model::s_BackColor.m_Green;
	blue  = 255 * (int) Model::s_BackColor.m_Blue;

	COLORREF theColor = RGB(red, green, blue);
	dlgColorChoice.m_cc.rgbResult = theColor; 
//	dlgColorChoice.SetCurrentColor(theColor);
	
	__try
	{
		if( IDOK == dlgColorChoice.DoModal())
		{
			theColor = dlgColorChoice.GetColor();

			red   = GetRValue(theColor);
			green = GetGValue(theColor);
			blue  = GetBValue(theColor);

			Model::s_BackColor.m_Red = (GLdouble)red/255.0;
			Model::s_BackColor.m_Green = (GLdouble)green/255.0;
			Model::s_BackColor.m_Blue = (GLdouble)blue/255.0;
			Invalidate();

		}

		if(isAnimated)
		{
			CD3dView::animate = true;
			animateWork();
		}
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		Util::casualException(GetExceptionCode(), TEXT(__FILE__), __LINE__);
		return_value = -1;
		goto cleanup;
	}

cleanup:
	return return_value;
}
//-----------------------------------------------------------------------------
int button = -1;
int state = -1;
//-----------------------------------------------------------------------------
LRESULT CD3dView::OnLButtonDown(UINT uMsg, WPARAM wParam, 
								LPARAM lParam, BOOL& bHandled)
{
	int return_value = 0;
	__try
	{
//		Tool* aTool = ToolsFactory::getInstance()->getTool(STATE_SCENE_ROTATE);
//		aTool->OnLButtonDown(this, 0,GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));

		button = MOUSE_LEFT_BUTTON;
		state = MOUSE_DOWN;
		xMotion = GET_X_LPARAM(lParam);
		yMotion = GET_Y_LPARAM(lParam);

		gltbMouse(button, state, xMotion, yMotion);

		lastx = xMotion;
		lasty = yMotion;
		deltax = 0;
		deltay = 0;

//		mouse_state = state;
//		mouse_button = button;
		animate= false;
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		Util::casualException(GetExceptionCode(), TEXT(__FILE__), __LINE__);
		return_value = -1;
		goto cleanup;
	}

cleanup:
	Invalidate();
	bHandled = TRUE;
	return return_value;
}
//-----------------------------------------------------------------------------
bool bRotate = false;
//-----------------------------------------------------------------------------
//if we include the ".h" we won't get the right values defined in the cpp file.
#include "../pipelinelib/gltb.cpp"
extern GLboolean gltbXRotation;
extern GLboolean gltbYRotation;
extern GLboolean gltbZRotation;
//-----------------------------------------------------------------------------
LRESULT CD3dView::OnRotateTop()
{
	int return_value = 0;
	__try
	{
		gltbXRotation = !gltbXRotation;
		gltbYRotation = !gltbYRotation;
		gltbZRotation = !gltbZRotation;
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		Util::casualException(GetExceptionCode(), TEXT(__FILE__), __LINE__);
		return_value = -1;
		goto cleanup;
	}

cleanup:
	Invalidate();
	return return_value;
}
//-----------------------------------------------------------------------------
LRESULT CD3dView::OnRotateFront()
{
	int return_value = 0;
	__try
	{
		gltbXRotation = !gltbXRotation;
		gltbYRotation = !gltbYRotation;
		gltbZRotation = !gltbZRotation;
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		Util::casualException(GetExceptionCode(), TEXT(__FILE__), __LINE__);
		return_value = -1;
		goto cleanup;
	}

cleanup:
	Invalidate();
	return return_value;
}
//-----------------------------------------------------------------------------
LRESULT CD3dView::OnRotateSide()
{
	int return_value = 0;
	__try
	{
		gltbXRotation = !gltbXRotation;
		gltbYRotation = !gltbYRotation;
		gltbZRotation = !gltbZRotation;
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		Util::casualException(GetExceptionCode(), TEXT(__FILE__), __LINE__);
		return_value = -1;
		goto cleanup;
	}

cleanup:
	Invalidate();
	return return_value;
}
//-----------------------------------------------------------------------------
LRESULT CD3dView::OnLButtonUp( UINT uMsg, WPARAM wParam, 
							  LPARAM lParam, BOOL& bHandled)
{
	int return_value = 0;
	__try
	{
//		Tool* aTool = ToolsFactory::getInstance()->getTool(STATE_SCENE_ROTATE);
//		aTool->OnLButtonUp(this, 0,  GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));

		button = MOUSE_LEFT_BUTTON;
		state = MOUSE_UP;
		xMotion = GET_X_LPARAM(lParam);
		yMotion = GET_Y_LPARAM(lParam);
//		m_DrawModel.mouse(button, state, xMotion, yMotion);
		gltbMouse(button, state, xMotion, yMotion);

		deltax = abs(lastx - xMotion);
		deltay = abs(lasty - yMotion);

//		mouse_state = state;
//		mouse_button = button;
//		if(bRotate && (xMotion>40 || yMotion>40))
		if(deltax > 40 || deltay > 40)
		{
			if(gltb_angle < 10)
			{
				animate = true;
				animateWork();
			}
		}
		bRotate = false;
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		Util::casualException(GetExceptionCode(), TEXT(__FILE__), __LINE__);
		return_value = -1;
		goto cleanup;
	}

cleanup:
	Invalidate();
	bHandled = TRUE;
	return return_value;
}
//-----------------------------------------------------------------------------
LRESULT CD3dView::OnRButtonDown( UINT uMsg, WPARAM wParam, 
								LPARAM lParam, BOOL& bHandled)
{
	int return_value = 0;

	__try
	{
		m_bRightButtonDown = true;
		lastx = xMotion = GET_X_LPARAM(lParam);
		lasty = yMotion = GET_Y_LPARAM(lParam);
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		Util::casualException(GetExceptionCode(), TEXT(__FILE__), __LINE__);
		return_value = -1;
		goto cleanup;
	}

cleanup:
	bHandled = TRUE;
	return return_value;
}
//-----------------------------------------------------------------------------
LRESULT CD3dView::OnRButtonUp( UINT uMsg, WPARAM wParam, 
								LPARAM lParam, BOOL& bHandled)
{
	int return_value = 0;

	__try
	{
		m_bRightButtonDown = false;
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		Util::casualException(GetExceptionCode(), TEXT(__FILE__), __LINE__);
		return_value = -1;
		goto cleanup;
	}

cleanup:
	bHandled = TRUE;
	return return_value;
}
//-----------------------------------------------------------------------------
LRESULT CD3dView::OnMouseMove( UINT uMsg, WPARAM wParam, 
							  LPARAM lParam, BOOL& bHandled)
{
	::SetFocus(m_hWnd);
	int return_value = 0;
	__try
	{
		xMotion = GET_X_LPARAM(lParam);
		yMotion = GET_Y_LPARAM(lParam);
		if(m_bRightButtonDown)
		{
			return_value = doScaleWithRightMouseButton();
			goto cleanup;
		}

//		if(animate)
//		{
//			return 0;
//		}
		if(MOUSE_DOWN == state)
		{
			//m_DrawModel.motion(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));

			gltbMotion(xMotion, yMotion);
//			lastx = xMotion;
//			lasty = yMotion;

//			bRotate = true;
			Invalidate();
		}
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		Util::casualException(GetExceptionCode(), TEXT(__FILE__), __LINE__);
		return_value = -1;
		goto cleanup;
	}

cleanup:
	bHandled = TRUE;
	return return_value;
}
//-----------------------------------------------------------------------------
LRESULT CD3dView::doScaleWithRightMouseButton()
{
//	gc_ptr<Model> pModel = Model::getStaticInstance();

	deltax = lastx - xMotion;
	deltay = lasty - yMotion;
	lastx = xMotion;
	lasty = yMotion;

	if(deltay < 0 )
	{
		if(Model::s_Transform.m_XScale < 1)
		{
			return 0;
		}
		Model::s_Transform.m_XScale *= DELTA_OUT_ZOOM;
		Model::s_Transform.m_YScale *= DELTA_OUT_ZOOM;
		Model::s_Transform.m_ZScale *= DELTA_OUT_ZOOM;
	}
	else if(deltay > 0)
	{
		if(	StateManager::stateZoom == STATE_ZOOM_RING) 
		{
			if(Model::s_Transform.m_XScale >= MAX_ZOOM_RING)
			{
				return 0;
			}
		}
		else
		{
			if(Model::s_Transform.m_XScale >= MAX_ZOOM_ELEMENT)
			{
				return 0;
			}
		}

		Model::s_Transform.m_XScale *= DELTA_IN_ZOOM;
		Model::s_Transform.m_YScale *= DELTA_IN_ZOOM;
		Model::s_Transform.m_ZScale *= DELTA_IN_ZOOM;
	}
	else
	{
		;
	}
	
	Invalidate();
	return 0;
}
//-----------------------------------------------------------------------------
void CD3dView::setMouseCursors()
{

	gc_ptr<Model> pModel = Model::getStaticInstance();
	long state = pModel->getState();
	//
	//CURSORS are working if you ever require them
	//
	if(	state == STATE_OBJECT_MOVE_X ||
		state == STATE_OBJECT_MOVE_Y ||
		state == STATE_OBJECT_MOVE_Z ||
		state == STATE_OBJECT_MOVE
		)
	{
		::SetCursor(::LoadCursor(_Module.m_hInst, 
								MAKEINTRESOURCE(IDC_CURSOR_MOVE)));
	}
	else 
	if(	state == STATE_OBJECT_ROTATE_X ||
		state == STATE_OBJECT_ROTATE_Y ||
		state == STATE_OBJECT_ROTATE_Z ||
		state == STATE_OBJECT_ROTATE
		)
	{
		::SetCursor(::LoadCursor(_Module.m_hInst, 
								MAKEINTRESOURCE(IDC_CURSOR_ROTATE)));
	}
	else 
	if(	state == STATE_OBJECT_SCALE_X ||
		state == STATE_OBJECT_SCALE_Y ||
		state == STATE_OBJECT_SCALE_Z ||
		state == STATE_OBJECT_SCALE
		)
	{
		::SetCursor(::LoadCursor(_Module.m_hInst, 
								MAKEINTRESOURCE(IDC_CURSOR_SCALE)));
	}
	else
	{
		::SetCursor(::LoadCursor(_Module.m_hInst, 
								MAKEINTRESOURCE(IDC_ARROW)));
	}

}
//-----------------------------------------------------------------------------
LRESULT CD3dView::OnMouseWheel(UINT /*uMsg*/, WPARAM wParam, 
							   LPARAM lParam, BOOL& bHandled)
{
	gc_ptr<Model> pModel = Model::getStaticInstance();

	if(GET_WHEEL_DELTA_WPARAM(wParam)<0)
	{
		if(pModel->s_Transform.m_XScale < 1)
		{
			return 0;
		}
		pModel->s_Transform.m_XScale *= DELTA_OUT_ZOOM;
		pModel->s_Transform.m_YScale *= DELTA_OUT_ZOOM;
		pModel->s_Transform.m_ZScale *= DELTA_OUT_ZOOM;
	}
	else
	{
		if(	StateManager::stateZoom == STATE_ZOOM_RING) 
		{
			if(pModel->s_Transform.m_XScale >= MAX_ZOOM_RING)
			{
				return 0;
			}
		}
		else
		{
			if(pModel->s_Transform.m_XScale >= MAX_ZOOM_ELEMENT)
			{
				return 0;
			}
		}

		pModel->s_Transform.m_XScale *= DELTA_IN_ZOOM;
		pModel->s_Transform.m_YScale *= DELTA_IN_ZOOM;
		pModel->s_Transform.m_ZScale *= DELTA_IN_ZOOM;
	}
	Invalidate();

	return 0;
}
//-----------------------------------------------------------------------------
LRESULT CD3dView::OnChar(UINT /*uMsg*/, WPARAM wParam, 
						 LPARAM lParam, BOOL& bHandled)
{
	return 0;
}
//-----------------------------------------------------------------------------
LRESULT CD3dView::OnKeyDown(UINT /*uMsg*/, WPARAM wParam, 
							LPARAM lParam, BOOL& bHandled)
{
	switch (wParam) 
    { 
        case VK_LEFT: 
//			m_DrawModel.m_pMeshSelected->m_ry -= 3.0;             
            break; 
        case VK_RIGHT: 
//			m_DrawModel.m_pMeshSelected->m_ry += 3.0;             
            break; 
        case VK_UP: 
//			m_DrawModel.m_pMeshSelected->m_rx += 3.0;             
            break; 
        case VK_DOWN: 
//			m_DrawModel.m_pMeshSelected->m_rx -= 3.0;             
            break; 
        case VK_HOME: 
            break; 
        case VK_END: 
            break; 
        case VK_INSERT: 
            break; 
        case VK_DELETE: 
            break; 
        case VK_F2: 
            break; 
        // Process other non-character keystrokes. 
        default: 
            break; 
	} 
	Invalidate();
	return 0;
}
//-----------------------------------------------------------------------------
LRESULT CD3dView::OnContextMenu(HWND hWnd, WTL::CPoint point)
{
/*	bool isAnimated = animate;
	animate = false;

	int return_value = 0;
	CMenu menu;
	CMenuHandle menuPopup;
	UINT uCmdID = -1;
	WORD wNotifyCode = (WORD)0;
	WORD wID = (WORD)0;
	BOOL bHandled = FALSE;

	__try
	{
		if (FALSE == menu.LoadMenu(MAKEINTRESOURCE(IDR_POPUP_BACK_SCENE))) 
		{
			return 1;
		}
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		Util::casualException(GetExceptionCode(), TEXT(__FILE__), __LINE__);
		return_value = -1;
		goto cleanup;
	}

	//we get to the first item in the menu, which is the menu to display
	__try
	{
		menuPopup = menu.GetSubMenu(0); 
		uCmdID = m_CmdBar.TrackPopupMenu(
					menuPopup,
					TPM_RIGHTBUTTON | //TPM_VERPOSANIMATION | 
					TPM_VERTICAL |
					TPM_LEFTALIGN | 
					TPM_TOPALIGN |
					TPM_RETURNCMD ,
		//				TPM_NONOTIFY , //using this one, will not show the icons
		// 				GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
					point.x, 
					point.y);//, 0, m_hWnd, NULL);
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		Util::casualException(GetExceptionCode(), TEXT(__FILE__), __LINE__);
		return_value = -1;
		goto cleanup;
	}

	// -----------------------------------------------------
	// we do the commands in here, we don't know how to 
	// send to the parent
	// -----------------------------------------------------
	__try
	{
		Model* pModel = Model::getStaticInstance();
		switch(uCmdID)
		{
			case ID_DRAW_SOLID:
				pModel->m_DrawSolid = true;
				pModel->updateAllViews();
			break;
			case ID_DRAW_WIRE:
				pModel->m_DrawSolid = false;
				pModel->updateAllViews();
			break;
			case ID_COMMAND_SELECT:
				OnCommandSelectDefault(wNotifyCode, wID , hWnd, bHandled) ;
			break;
			case ID_COMMAND_SELECT_MOVE:
				OnCommandSelectMove(wNotifyCode, wID , hWnd, bHandled) ;
			break;
			case ID_COMMAND_SELECT_ROTATE:
				OnCommandSelectRotate(wNotifyCode, wID, hWnd, bHandled) ;
			break;
			case ID_COMMAND_SELECT_SCALE:
				OnCommandSelectScale(wNotifyCode, wID, hWnd, bHandled) ;
			break;
			case ID_COMMAND_ROTATE_SCENE:
				pModel->setState(STATE_SCENE_ROTATE);
			break;
			case ID_COMMAND_SCALE_SCENE:
				pModel->setState(STATE_SCENE_SCALE);
			break;
			case ID_COMMAND_VIEW_VOLUME:
				OnCommandViewVolume(wNotifyCode, wID, hWnd, bHandled) ;
			break;
			case ID_COMMAND_VIEW_EDGE:
				OnCommandViewEdge(wNotifyCode, wID, hWnd, bHandled) ;
			break;
			case ID_COMMAND_VIEW_TEXTURE:
				OnCommandViewTexture(wNotifyCode, wID, hWnd, bHandled) ;
			break;
			case ID_PROPERTIES_GRIDON:
				OnCommandViewBackColor(wNotifyCode, wID, hWnd, bHandled) ;
			break;
			case ID_COMMAND_VIEW_BACK_COLOR:
				OnCommandViewBackColor(wNotifyCode, wID, hWnd, bHandled) ;
			break;
			default:
				;//Model::getStaticInstance()->setState(STATE_ROTATE_SCENE);
			break;
		}
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		Util::casualException(GetExceptionCode(), TEXT(__FILE__), __LINE__);
		return_value = -1;
		goto cleanup;
	}

cleanup:	 
	if(isAnimated)
	{
		animate = true;
		animateWork();
	}

	return return_value;
*/
	return 0;
}
//-----------------------------------------------------------------------------
LRESULT CD3dView::OnCommandSelectDefault(WORD /*wNotifyCode*/, WORD /*wID*/, 
										 HWND /*hWndCtl*/, BOOL& /*bHandled*/) 
{
	Model::getStaticInstance()->setState(STATE_OBJECT_SELECT);
	return 0;
}
//-----------------------------------------------------------------------------
LRESULT CD3dView::OnRotateScene(WORD /*wNotifyCode*/, WORD /*wID*/, 
								HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	Model::getStaticInstance()->setState(STATE_SCENE_ROTATE);
	return 0;
}
//-----------------------------------------------------------------------------
LRESULT CD3dView::OnScaleScene(WORD /*wNotifyCode*/, WORD /*wID*/, 
							   HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	Model::getStaticInstance()->setState(STATE_SCENE_SCALE);
	return 0;
}
//-----------------------------------------------------------------------------
LRESULT CD3dView::OnCommandSelectMove(WORD /*wNotifyCode*/, WORD /*wID*/, 
									  HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	return 0;
	int return_value = 0;

	__try
	{
		Model::getStaticInstance()->setState(STATE_OBJECT_MOVE);	
		Model::updateAllViews();
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		Util::casualException(GetExceptionCode(), TEXT(__FILE__), __LINE__);
		return_value = -1;
		goto cleanup;
	}

cleanup:	 
	return return_value;
}
//-----------------------------------------------------------------------------
LRESULT CD3dView::OnCommandSelectRotate(WORD /*wNotifyCode*/, WORD /*wID*/, 
										HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	return 0;

	int return_value = 0;

	__try
	{
		Model::getStaticInstance()->setState(STATE_OBJECT_ROTATE);
		Model::updateAllViews();
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		Util::casualException(GetExceptionCode(), TEXT(__FILE__), __LINE__);
		return_value = -1;
		goto cleanup;
	}

cleanup:	 
	return return_value;
}
//-----------------------------------------------------------------------------
LRESULT CD3dView::OnCommandSelectScale(WORD /*wNotifyCode*/, WORD /*wID*/, 
									   HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	return 0;
	int return_value = 0;

	__try
	{
		gc_ptr<Model> pModel = Model::getStaticInstance();
		pModel->setState(STATE_OBJECT_SCALE);
		Model::updateAllViews();
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		Util::casualException(GetExceptionCode(), TEXT(__FILE__), __LINE__);
		return_value = -1;
		goto cleanup;
	}

cleanup:	 
	return return_value;
}
//-----------------------------------------------------------------------------
int CD3dView::updateParentTitle()
{
	int return_value = 0;

	__try
	{
		tstring	strCameraName = m_Camera.m_Name;
		if(NULL != this->pParentPaneContainer)
		{
			this->pParentPaneContainer->SetTitle(strCameraName.c_str());
		}
		Invalidate();
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		Util::casualException(GetExceptionCode(), TEXT(__FILE__), __LINE__);
		return_value = -1;
		goto cleanup;
	}

cleanup:	 
	return return_value;
}
//-----------------------------------------------------------------------------
int CD3dView::setParent(CPaneContainer* parent)
{
	int return_value = 0;

	__try
	{
		this->pParentPaneContainer = parent;
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		Util::casualException(GetExceptionCode(), TEXT(__FILE__), __LINE__);
		return_value = -1;
		goto cleanup;
	}

cleanup:	 
	return return_value;
}
//-----------------------------------------------------------------------------
// Setup texgen for sphere environment mapping
HRESULT SetupSphereEnvMapTexGen()
{
	Matrix4 mat;

	return S_OK;
}
//-----------------------------------------------------------------------------
// No textures mapping mode
HRESULT DisableTexGen()
{
	return S_OK;
}
HRESULT SetupTexGen(int m_iTexGen)
{
	SetupSphereEnvMapTexGen();
	return S_OK;
}
// ----------------------------------------------------------------------------
// Setup texture scale matrix to map from -1.0..1.0 to 0.0..1.0
VOID SetTextureScaleMatrix(Matrix4 &mat)
{
	ZeroMemory(&mat, sizeof(Matrix4));
}
//-----------------------------------------------------------------------------
// Name: RenderText()
// Desc: Renders stats and help text to the scene.
//-----------------------------------------------------------------------------
HRESULT CD3dView::RenderText()
{
    return S_OK;
}
//-----------------------------------------------------------------------------
//  void CD3dView::updateAllViews ()
  //{
	//  Invalidate();
//  }
//-----------------------------------------------------------------------------
void CD3dView::invalidateLists()
{
}
//-----------------------------------------------------------------------------
void CD3dView::updateCreation ()
{
}
//-----------------------------------------------------------------------------
void CD3dView::updateRemoval ()
{
}
//-----------------------------------------------------------------------------
void CD3dView::createWGLFont(HDC hDC)
{
	HFONT hFont;

	//-------------------------------------
	//customised logfont structure
	//-------------------------------------
	LOGFONT font;
	font.lfCharSet = ANSI_CHARSET;
	font.lfClipPrecision = CLIP_DEFAULT_PRECIS;
	font.lfEscapement = 0;
	font.lfHeight = 5;
	font.lfItalic = FALSE;
	font.lfOrientation = 0;
	font.lfOutPrecision = OUT_DEFAULT_PRECIS;
	font.lfPitchAndFamily = DEFAULT_PITCH;
	font.lfQuality = DEFAULT_QUALITY;
	font.lfStrikeOut = FALSE;
	font.lfUnderline = FALSE;
	font.lfWeight = FW_THIN;//FW_BOLD;
	font.lfWidth = 0;
	_tcscpy_s(font.lfFaceName, 9, TEXT("Verdana"));

	//put the font in the dc
	hFont = CreateFontIndirect(&font);
	SelectObject (hDC, hFont); 
	
	//create the lists for the glyphs
	Model::s_nFontList =  glGenLists(128);

	GLYPHMETRICSFLOAT gmf[128]; 
	//use the dc to create the gl font
	wglUseFontOutlines(hDC, 0, 128, Model::s_nFontList, 0.0f, 0.5f, 
						WGL_FONT_POLYGONS, gmf); 

	DeleteObject(hFont);
}



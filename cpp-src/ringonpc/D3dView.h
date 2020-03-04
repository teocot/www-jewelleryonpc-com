//-----------------------------------------------------------------------------
//
// D3dView.h : interface of the CD3dView class
//
//-----------------------------------------------------------------------------
#pragma once
//-----------------------------------------------------------------------------
#pragma warning( disable : 4996 ) 
#pragma warning( disable : 4995 ) 
//-----------------------------------------------------------------------------
#include <Windows.h>
#include <mmsystem.h>
#include "atlcrack.h"
#include <atlmisc.h>
#include <atldlgs.h>
#include <strsafe.h>
#include "UpdateInterface.h"
#include <pipelinelib/OpenglView.h>
#include <ringmodellib/ModelObserver.h>
using namespace pipelinelib;
#include "ringmodellib/Model.h"
#include "resource.h"
#include <opengllib/RGBpixmap.h>
using namespace opengllib;
//-----------------------------------------------------------------------------
#include <gl/gl.h> 
//-----------------------------------------------------------------------------
#pragma warning( default : 4995 ) 
#pragma warning( default : 4996 ) 
//-----------------------------------------------------------------------------
#ifndef SAFE_RELEASE
#define SAFE_RELEASE(p)      { if(p) { (p)->Release(); (p)=NULL; } }
#endif
#ifndef V_RETURN
#define V_RETURN(x)    { HRESULT hr = x; if( FAILED(hr) ) { return hr; } }
#endif
#ifndef WM_MOUSEWHEEL
#define WM_MOUSEWHEEL                   0x020A
#endif
//-----------------------------------------------------------------------------
class CD3dView :	public CWindowImpl<CD3dView>,
					public OpenglView,
					public ModelObserver,
					public Observer
{
	Matrix4	m_matView;				
	Matrix4	m_matProj;
	bool	m_isPerspective;
//-----------------------------------------------------------------------------
// Global variables
//-----------------------------------------------------------------------------
	CPaneContainer* pParentPaneContainer;
public:

	CBitmap m_bmp;
	SIZE m_size;
	bool saveScreenGrabAsTga(const char* filename);
	bool saveScreenGrabAsBmp(const char* filename);

	// Size
	double		m_dAspectPrint; 
	double		m_dNearPlane; 
	double		m_dFarPlane; 
	double		m_dMaxObjSize; 
	double		m_dAspect;
private:
	bool m_bRightButtonDown;
	static int lastx ;
	static int lasty ;
	static int deltax;
	static int deltay;

public:

	static int xMotion ;
	static int yMotion ;
	static bool animate ;
	LRESULT OnRotateTop(  );
	LRESULT OnRotateFront( );
	LRESULT OnRotateSide( );
	LRESULT doScaleWithRightMouseButton();
	CD3dView();
	virtual ~CD3dView();

	//used for context menus
	//when used it gives assertion errors in debug
//	CCommandBarCtrl m_CmdBar;
	
	DECLARE_WND_CLASS(NULL)

	BEGIN_MSG_MAP(CD3dView)
		MESSAGE_HANDLER(WM_PAINT, OnPaint)
		MESSAGE_HANDLER(WM_CREATE, OnCreate)
		//MSG_WM_CONTEXTMENU(OnContextMenu)

		// ---------- top object commands -------------
		COMMAND_ID_HANDLER(ID_COMMAND_SELECT, OnCommandSelectDefault)

		COMMAND_ID_HANDLER(ID_COMMAND_SELECT_MOVE, OnCommandSelectMove)
		COMMAND_ID_HANDLER(ID_COMMAND_SELECT_ROTATE, OnCommandSelectRotate)
		COMMAND_ID_HANDLER(ID_COMMAND_SELECT_SCALE, OnCommandSelectScale)
		// ------ Draw menu ------------
		COMMAND_ID_HANDLER(ID_COMMAND_VIEW_VOLUME, OnCommandViewVolume)
		COMMAND_ID_HANDLER(ID_COMMAND_VIEW_EDGE, OnCommandViewEdge)
		COMMAND_ID_HANDLER(ID_COMMAND_VIEW_TEXTURE, OnCommandViewTexture)
		COMMAND_ID_HANDLER(ID_PROPERTIES_GRIDON, OnCommandPropertiesGridOn)
		// --- Camera menu ------------------
		COMMAND_ID_HANDLER(ID_COMMAND_ROTATE_SCENE, OnRotateScene)
		COMMAND_ID_HANDLER(ID_COMMAND_SCALE_SCENE, OnScaleScene)

		// -------- miscelaneous --------------
		COMMAND_ID_HANDLER(ID_COMMAND_VIEW_BACK_COLOR, OnCommandViewBackColor)

		REFLECT_NOTIFICATIONS()
		MESSAGE_HANDLER(WM_LBUTTONDOWN, OnLButtonDown)
		MESSAGE_HANDLER(WM_LBUTTONUP, OnLButtonUp)
		MESSAGE_HANDLER(WM_RBUTTONDOWN, OnRButtonDown)
		MESSAGE_HANDLER(WM_RBUTTONUP, OnRButtonUp)
		MESSAGE_HANDLER(WM_MOUSEMOVE, OnMouseMove)
		MESSAGE_HANDLER(WM_ERASEBKGND, OnEraseBackground)
		MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
		MESSAGE_HANDLER(WM_SIZE, OnSize)
		MESSAGE_HANDLER(WM_CHAR, OnChar)
		MESSAGE_HANDLER(WM_KEYDOWN, OnKeyDown)
		MESSAGE_HANDLER(WM_MOUSEWHEEL, OnMouseWheel)
	END_MSG_MAP()

	LRESULT OnMouseWheel(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnChar(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnKeyDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnContextMenu(HWND hWnd, CPoint point);

	LRESULT OnCommandSelectDefault(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
	LRESULT OnCommandSelectMove(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
	LRESULT OnCommandSelectScale(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
	LRESULT OnCommandSelectRotate(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);

	// ------------------ commands from menus -------------------------------------
	LRESULT OnCommandViewVolume(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled) ;
	LRESULT OnCommandViewEdge(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled) ;
	LRESULT OnCommandViewTexture(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled) ;
	LRESULT OnCommandPropertiesGridOn(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled); 

	LRESULT OnRotateScene(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
	LRESULT OnScaleScene(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);

	LRESULT OnCommandViewBackColor(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled) ;

	LRESULT OnLButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnLButtonUp( UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnRButtonDown( UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnRButtonUp( UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnMouseMove( UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnEraseBackground(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//	LRESULT OnMouseWheel(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	//LRESULT OnMouseWheel(UINT nFlags, CPoint point) ;

	virtual BOOL OnIdle();
	BOOL PreTranslateMessage(MSG* pMsg);

	enum draw_style{SOLID, WIRE, VERTEX};

	int setParent(CPaneContainer* parent);
	int updateParentTitle();
	void setMouseCursors();

	HRESULT RenderText();
    void invalidateLists ();
    void updateAllViews ();
    void updateCreation ();
    void updateRemoval ();

	void update()
	{
		draw();
		Invalidate();//this is okl
	}
	void SetBitmap(HBITMAP hBitmap)
	{
		if(!m_bmp.IsNull())
			m_bmp.DeleteObject();

		m_bmp = hBitmap;

		if(!m_bmp.IsNull())
			m_bmp.GetSize(m_size);
		else
			m_size.cx = m_size.cy = 1;

//		SetScrollOffset(0, 0, FALSE);
//		SetScrollSize(m_size);
	}
//-----------------------------------------------------------------------------
// opengl
//-----------------------------------------------------------------------------
	HDC		m_hDC;			// GDI Device Context 
    HGLRC	m_hglRC;		// Rendering Context
	BOOL	SetPixelformat(HDC hdc);
	GLvoid	ReSizeGLScene(GLsizei width, GLsizei height);
	int		InitGL();	
	void	animateWork();
	inline void SetContext() 
	{ wglMakeCurrent( ::GetDC(m_hWnd), m_hglRC ); }
	inline void SwapGLBuffers() { ::SwapBuffers( ::GetDC(m_hWnd) ); }
	GLint m_nFontList ;
	void createWGLFont(HDC hDC);


//-----------------------------------------------------------------------------
};
//-----------------------------------------------------------------------------

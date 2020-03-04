//-----------------------------------------------------------------------------
// CustomColorDialog.h
//
// the ids for the edit boxes have been hacked from teh messages
// presented with the sdk spy
// at the end better to do a new custom one, instead of using the base class
// the customer on will have the rogvaiv on one coordinate,
// then for each color the intensity, which will give lighter efects
//-----------------------------------------------------------------------------
#include "UpdateInterface.h"
#pragma once
//-----------------------------------------------------------------------------
class CCustomColorDialog : public CColorDialogImpl<CCustomColorDialog>,
							public UpdateInterface
{
public:
	COLORREF m_Color;
	CCustomColorDialog(COLORREF clrInit = 0, DWORD dwFlags = 0, HWND hWndParent = NULL);

	BEGIN_MSG_MAP(CCustomColorDialog)
//		MESSAGE_HANDLER(WM_PAINT,OnPaint)
		MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
		MESSAGE_HANDLER(WM_MOUSEMOVE,OnMouseMove)
		MESSAGE_HANDLER(WM_LBUTTONDOWN,OnLButtonDown)
		MESSAGE_HANDLER(WM_SETTEXT,OnSetText)

		NOTIFY_HANDLER_EX(706, EN_UPDATE, OnRedChanged)
	END_MSG_MAP()

//	LRESULT OnCloseCmd(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
//	{
//		return FALSE;
//	}

	LRESULT OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnRedChanged(LPNMHDR lParam);
	LRESULT OnSetText(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnMouseMove(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) ;
	LRESULT OnLButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) ;
	void changeColor();

	virtual ~CCustomColorDialog(void);
};
//-----------------------------------------------------------------------------

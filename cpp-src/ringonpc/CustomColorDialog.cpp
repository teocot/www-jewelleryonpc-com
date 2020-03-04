//-----------------------------------------------------------------------------
// CustomColorDialog.cpp
//-----------------------------------------------------------------------------
#include "StdAfx.h"
#include "CustomColorDialog.h"
//-----------------------------------------------------------------------------
CCustomColorDialog::CCustomColorDialog(COLORREF clrInit , DWORD dwFlags ,
									   HWND hWndParent ) : 
	CColorDialogImpl<CCustomColorDialog>(clrInit, dwFlags, hWndParent)
{
}
//-----------------------------------------------------------------------------
CCustomColorDialog::~CCustomColorDialog(void)
{
}
//-----------------------------------------------------------------------------
LRESULT CCustomColorDialog::OnRedChanged(LPNMHDR lParam)
{
	TCHAR buffer[20] = {(TCHAR)NULL};
	CEdit mEdit ;
	int return_value = 0;

	__try
	{
		mEdit = ::GetDlgItem(m_hWnd, 706);
		mEdit.GetWindowText(buffer, 20);
		::MessageBox(m_hWnd, buffer, TEXT("message"), MB_OK);
		::MessageBox(m_hWnd, TEXT("Changed red"), TEXT("message"), MB_OK);
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		::MessageBox(m_hWnd,
					TEXT("Exception in CustomColorDialog::OnRedChanged"), 
					TEXT("Exception in CustomColorDialog::OnRedChanged"), 
					MB_OK);
		//non critical
		return_value = -1;
		goto cleanup;
	}

cleanup:
	return 0;
}
//-----------------------------------------------------------------------------
LRESULT CCustomColorDialog::OnSetText(UINT uMsg, WPARAM wParam, 
									  LPARAM lParam, BOOL& bHandled) 
{
	int return_value = 0;
	TCHAR buffer[20] = {(TCHAR)NULL};
	CEdit mEdit ;
	
	__try
	{
		mEdit = ::GetDlgItem(m_hWnd, 706);
		mEdit.GetWindowText(buffer, 20);
		::MessageBox(m_hWnd, buffer, TEXT("message"), MB_OK);
		bHandled = FALSE;
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		::MessageBox(m_hWnd,
					TEXT("Exception in CustomColorDialog::OnSetText"), 
					TEXT("Exception in CustomColorDialog::OnSetText"), 
					MB_OK);
		//non critical
		return_value = -1;
		goto cleanup;
	}

cleanup:
	return return_value;
}
//-----------------------------------------------------------------------------
LRESULT CCustomColorDialog::OnMouseMove(UINT uMsg, WPARAM wParam, 
										LPARAM lParam, BOOL& bHandled) 
{
	__try
	{
		changeColor();
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		::MessageBox(m_hWnd,
					TEXT("Exception in CustomColorDialog::OnMouseMove"), 
					TEXT("Exception in CustomColorDialog::OnMouseMove"), 
					MB_OK);
		//non critical
	}
	
	bHandled = FALSE;
	return 0;
}
//-----------------------------------------------------------------------------
void CCustomColorDialog::changeColor()
{
	CEdit mEdit ;
	TCHAR bufferRed[20] = {(TCHAR)NULL};
	TCHAR bufferGreen[20] = {(TCHAR)NULL};
	TCHAR bufferBlue[20] = {(TCHAR)NULL};
	BYTE byRed	;
	BYTE byGreen;
	BYTE byBlue	;

	__try
	{
		mEdit = ::GetDlgItem(m_hWnd, 706);
		mEdit.GetWindowText(bufferRed, 20);

		mEdit = ::GetDlgItem(m_hWnd, 707);
		mEdit.GetWindowText(bufferGreen, 20);

		mEdit = ::GetDlgItem(m_hWnd, 708);
		mEdit.GetWindowText(bufferBlue, 20);

		byRed		= _wtoi(bufferRed);
		byGreen		= _wtoi(bufferGreen);
		byBlue		= _wtoi(bufferBlue);

		m_cc.rgbResult = RGB(byRed, byGreen, byBlue);

		updateAll();
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		::MessageBox(m_hWnd,
					TEXT("Exception in CustomColorDialog::changeColor"), 
					TEXT("Exception in CustomColorDialog::changeColor"), 
					MB_OK);
		//non critical
	}

}
//-----------------------------------------------------------------------------
LRESULT CCustomColorDialog::OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, 
										 LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	__try
	{
		CenterWindow(GetParent());
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		::MessageBox(m_hWnd,
					TEXT("Exception in CustomColorDialog::OnInitDialog"), 
					TEXT("Exception in CustomColorDialog::OnInitDialog"), 
					MB_OK);
		return FALSE;
	}
	return TRUE;
}
//-----------------------------------------------------------------------------
LRESULT CCustomColorDialog::OnLButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) 
{
	__try
	{
		changeColor();
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		::MessageBox(m_hWnd,
					TEXT("Exception in CustomColorDialog::OnLButtonDown"), 
					TEXT("Exception in CustomColorDialog::OnLButtonDown"), 
					MB_OK);
		return -1;
	}
	
	bHandled  = FALSE;
	return 0;
}
//-----------------------------------------------------------------------------

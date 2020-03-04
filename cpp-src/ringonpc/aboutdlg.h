// ----------------------------------------------------------------------------
//
// Copyright © 2006 ABACASOFT LIMITED
//
// aboutdlg.h : interface of the CAboutDlg class
//
// ----------------------------------------------------------------------------
#if !defined(_ABOUTDLG_H_)
#define _ABOUTDLG_H_
#include <string>
#include <atlctrlx.h>
#include <atlddx.h>
using namespace std;
// ----------------------------------------------------------------------------
class CAboutDlg : public CDialogImpl<CAboutDlg>,
					public CWinDataExchange<CAboutDlg>
{
	CHyperLink m_linkToBuy;
	CHyperLink m_linkToSupport;

	CStatic m_staticWarning;
	tstring	m_strStaticWarning;
	CEdit	m_editUserName;
	tstring	m_strUserName;
	CEdit	m_editProductId;
	tstring  m_strProductId;
	CStatic m_staticVersion ;
	tstring	m_strVersion ;

public:
	enum { IDD = IDD_ABOUTBOX };
// ----------------------------------------------------------------------------
	BEGIN_MSG_MAP(CAboutDlg)
		MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
		COMMAND_ID_HANDLER(IDOK, OnCloseCmd)
		COMMAND_ID_HANDLER(IDCANCEL, OnCloseCmd)
	END_MSG_MAP()
// ----------------------------------------------------------------------------
	BEGIN_DDX_MAP(CAboutDialog)
        DDX_CONTROL(IDC_HYPERLINK_BUY,		m_linkToBuy)
        DDX_CONTROL(IDC_HYPERLINK_SUPPORT,	m_linkToSupport)
    END_DDX_MAP()
// ----------------------------------------------------------------------------
	LRESULT OnInitDialog(	UINT uMsg, WPARAM wParam, 
							LPARAM lParam, BOOL& bHandled);
	LRESULT OnCloseCmd(		WORD wNotifyCode, WORD wID, 
							HWND hWndCtl, BOOL& bHandled);
};
// ----------------------------------------------------------------------------
#endif // !defined(_ABOUTDLG_H_)

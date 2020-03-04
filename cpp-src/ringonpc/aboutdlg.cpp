//#############################################################################
//
// Copyright © 2006-2009 ABACASOFT LIMITED
//
// aboutdlg.cpp : implementation of the CAboutDlg class
//
//#############################################################################
#include "stdafx.h"
#include "resource.h"
#include "aboutdlg.h"
#include "../utillib/UtilLicence.h"
using namespace utillib;
//#############################################################################
LRESULT CAboutDlg::OnInitDialog(UINT uMsg, WPARAM wParam, 
								LPARAM lParam, BOOL& bHandled)
{
	CenterWindow(GetParent());

    // set icons
    HICON hIcon = (HICON)::LoadImage(_Module.GetResourceInstance(), MAKEINTRESOURCE(IDR_MAINFRAME), 
        IMAGE_ICON, ::GetSystemMetrics(SM_CXICON), ::GetSystemMetrics(SM_CYICON), LR_DEFAULTCOLOR);
    SetIcon(hIcon, TRUE);
    HICON hIconSmall = (HICON)::LoadImage(_Module.GetResourceInstance(), MAKEINTRESOURCE(IDR_MAINFRAME), 
        IMAGE_ICON, ::GetSystemMetrics(SM_CXSMICON), ::GetSystemMetrics(SM_CYSMICON), LR_DEFAULTCOLOR);
    SetIcon(hIconSmall, FALSE);

    // Hook up controls & variables
    DoDataExchange(false);

	m_staticWarning = GetDlgItem(IDC_STATIC_WARNING);
	m_strStaticWarning = TEXT("Warning: This computer program is protected \
by copyright law and international treaties. Unauthorizsed reproduction \
or distribution of this program, or any portion of it, may result in severe \
civil and criminal penalties and it will be prosecuted to the maximum extent \
possible under the law.");
	m_staticWarning.SetWindowText(m_strStaticWarning.c_str());

	m_editUserName = GetDlgItem(IDC_EDIT_LICENCED_TO);
	m_strUserName = UtilLicence::s_strUserName;
	m_editUserName.SetWindowText(m_strUserName.c_str());
	m_editProductId = GetDlgItem(IDC_EDIT_PRODUCT_ID);
	m_strProductId = UtilLicence::s_strProductID;
	m_editProductId.SetWindowText(m_strProductId.c_str());
	m_staticVersion = GetDlgItem(IDC_STATIC_VERSION);

#ifdef DEMO
	m_strVersion = TEXT("Ringonpc Birthstone Demo 1.0");
#else
	m_strVersion = TEXT("Ringonpc Birthstone 1.0");
#endif

	m_staticVersion.SetWindowText(m_strVersion.c_str());

	m_linkToBuy.SetHyperLink ( TEXT("http://www.jewelleryonpc.com/Buy/Default.aspx") );
	m_linkToSupport.SetHyperLink ( TEXT("mailto:contact@jewelleryonpc.com") );

	return TRUE;
}
//#############################################################################
LRESULT CAboutDlg::OnCloseCmd(WORD wNotifyCode, WORD wID, 
							  HWND hWndCtl, BOOL& bHandled)
{
	EndDialog(wID);
	return 0;
}
//#############################################################################

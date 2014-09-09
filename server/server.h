// server.h : main header file for the SERVER application
//

#if !defined(AFX_SERVER_H__7F3B8635_5A10_4A9E_B559_7CA8141BF68B__INCLUDED_)
#define AFX_SERVER_H__7F3B8635_5A10_4A9E_B559_7CA8141BF68B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CServerApp:
// See server.cpp for the implementation of this class
//

class CServerApp : public CWinApp
{
public:
	sockaddr_in serv;
	CServerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CServerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CServerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERVER_H__7F3B8635_5A10_4A9E_B559_7CA8141BF68B__INCLUDED_)

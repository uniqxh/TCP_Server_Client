#if !defined(AFX_SET_H__BBADEA07_3621_4752_97EF_305302595FDA__INCLUDED_)
#define AFX_SET_H__BBADEA07_3621_4752_97EF_305302595FDA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// set.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// set dialog

class set : public CDialog
{
// Construction
public:
	CString str;
	set(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(set)
	enum { IDD = IDD_DIALOG1 };
	CIPAddressCtrl	m_ip;
	int		m_port;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(set)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(set)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SET_H__BBADEA07_3621_4752_97EF_305302595FDA__INCLUDED_)

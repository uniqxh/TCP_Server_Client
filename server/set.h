#if !defined(AFX_SET_H__6B1F2FE5_D4B7_4799_8C60_FEF7F94A6576__INCLUDED_)
#define AFX_SET_H__6B1F2FE5_D4B7_4799_8C60_FEF7F94A6576__INCLUDED_

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
	set(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(set)
	enum { IDD = IDD_set };
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
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SET_H__6B1F2FE5_D4B7_4799_8C60_FEF7F94A6576__INCLUDED_)

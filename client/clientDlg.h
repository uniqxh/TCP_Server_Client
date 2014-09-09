// clientDlg.h : header file
//

#if !defined(AFX_CLIENTDLG_H__B6A25F07_3A17_4BD5_AC0F_A5A409776579__INCLUDED_)
#define AFX_CLIENTDLG_H__B6A25F07_3A17_4BD5_AC0F_A5A409776579__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CClientDlg dialog

class CClientDlg : public CDialog
{
// Construction
public:
	bool iscon;
	int cnt;
	SOCKET sock;
	sockaddr_in cli;
	void Play(CString str);
	CString ip;
	int port;
	CClientDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CClientDlg)
	enum { IDD = IDD_CLIENT_DIALOG };
	CButton	m_set;
	CButton	m_connect;
	CButton	m_disconnect;
	CEdit	m_info;
	CEdit	m_send;
	CButton	m_button;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClientDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CClientDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void Onset();
	afx_msg void Onbuttonsend();
	afx_msg void Oncon();
	afx_msg void Onclose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIENTDLG_H__B6A25F07_3A17_4BD5_AC0F_A5A409776579__INCLUDED_)

// serverDlg.h : header file
//

#if !defined(AFX_SERVERDLG_H__26145141_1435_4AEC_9828_661AB353264B__INCLUDED_)
#define AFX_SERVERDLG_H__26145141_1435_4AEC_9828_661AB353264B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CServerDlg dialog

class CServerDlg : public CDialog
{
// Construction
public:
	bool isopen;
	int msgcount;
	int addlen;
	sockaddr_in serv;
	SOCKET sock;
	SOCKET msgsock[50];
	int getcount();
	void Play(CString str);
	CString ip;
	int port;
	CServerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CServerDlg)
	enum { IDD = IDD_SERVER_DIALOG };
	CButton	m_open;
	CButton	m_close;
	CButton	m_set;
	CEdit	m_send;
	CButton	m_button;
	CEdit	m_info;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CServerDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CServerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void Onset();
	afx_msg void Onsend();
	afx_msg void Onstartserver();
	afx_msg void Oncloseserver();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERVERDLG_H__26145141_1435_4AEC_9828_661AB353264B__INCLUDED_)

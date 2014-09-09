// set.cpp : implementation file
//

#include "stdafx.h"
#include "client.h"
#include "set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// set dialog


set::set(CWnd* pParent /*=NULL*/)
	: CDialog(set::IDD, pParent)
{
	//{{AFX_DATA_INIT(set)
	m_port = 0;
	//}}AFX_DATA_INIT
}


void set::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(set)
	DDX_Control(pDX, IDC_IPADDRESS1, m_ip);
	DDX_Text(pDX, IDC_port, m_port);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(set, CDialog)
	//{{AFX_MSG_MAP(set)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// set message handlers

void set::OnOK() 
{
	// TODO: Add extra validation here
	m_ip.GetWindowText(str);
	CDialog::OnOK();
}

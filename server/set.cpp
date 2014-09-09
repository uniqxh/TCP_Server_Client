// set.cpp : implementation file
//

#include "stdafx.h"
#include "server.h"
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
	m_port=8888;
	//}}AFX_DATA_INIT
}


void set::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(set)
	DDX_Control(pDX, IDC_IP, m_ip);
	DDX_Text(pDX, IDC_port, m_port);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(set, CDialog)
	//{{AFX_MSG_MAP(set)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// set message handlers


BOOL set::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	char   name[128];  
	hostent*   pHost;
	gethostname(name,128);//获得主机名
	pHost=gethostbyname(name);//获得主机结构
	m_port=8888;
	m_ip.SetWindowText(inet_ntoa(*((in_addr*)pHost->h_addr)));
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

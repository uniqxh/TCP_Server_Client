// serverDlg.cpp : implementation file
//

#include "stdafx.h"
#include "server.h"
#include "serverDlg.h"
#include "set.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

UINT thread(LPVOID p)
{
	char buff[100];//定义缓冲区
	int s=1,msgcount,loop=1,flag=0;
	CServerDlg *dlg=(CServerDlg*)AfxGetApp()->GetMainWnd();//获得当前运行对话框句柄
	msgcount=dlg->getcount();//获取还没有被占用的数组序号
	if (msgcount==-1)//如果不等于-1，则表示，还有空缺SOCKET
		loop=0;
	msgcount=1;
	if(loop)
	{
		s=1;
		//AfxMessageBox("AA");
		dlg->msgsock[msgcount]=accept(dlg->sock,(sockaddr*)&(dlg->serv),&(dlg->addlen));//用空缺的SOCKET等待客户连接
		if (dlg->msgsock[msgcount]==INVALID_SOCKET)
		{
			dlg->Play("Error accept");
		}
		else
		{
			AfxBeginThread(thread,0);//如果和客户端连接成功，则再次启动一个线程
			dlg->SetForegroundWindow();//显示连机成功信息
			CString str,ss;
			CTime tm;
			str.Format("与 %s 连接成功\n",inet_ntoa(dlg->serv.sin_addr));
			ss.Format(" %s ",inet_ntoa(dlg->serv.sin_addr));
			dlg->Play(str);
			dlg->m_button.EnableWindow(TRUE);
			//send(dlg->msgsock[msgcount],"nihao",100,0);
			while(s!=SOCKET_ERROR)//如果没有发生错误，则一直循环等待数据的到来
			{
				s=recv(dlg->msgsock[msgcount],buff,100,0); //循环接收数据
				tm=CTime::GetCurrentTime();
				str=ss;
				str+=tm.Format(" %X");
				str+="\n";
				dlg->Play(str);
				dlg->SetForegroundWindow();
				if (s!=SOCKET_ERROR)//如果接收成功，则显示接收到的数据
				{
					str=buff;
					str+="\n";
					dlg->Play(str);
					//dlg->sendtoall(dlg->msgsock[msgcount],buff);//发送信息到所有的客户端
				}
			}
			send(dlg->msgsock[msgcount],"Disconnected",100,0);//如果发生错误，发送连接中断消息到客户端
			dlg->msgsock[msgcount]=NULL;//将该SOCKET设定为空
			for(int i=0;i<50;i++)//判断是否还有其他客户在保持连接
			if (dlg->msgsock[i]!=NULL)
			{
				flag=1;
				break;
			}
			if (flag!=1)//如果没有客户连接了，则将发送按钮设置为不可用
				dlg->m_button.EnableWindow(FALSE);
			closesocket(dlg->msgsock[msgcount]);//关闭连接
		}
	}
	AfxEndThread(0); //终止线程
	return 0;
}

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CServerDlg dialog

CServerDlg::CServerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CServerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CServerDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CServerDlg)
	DDX_Control(pDX, IDC_startserver, m_open);
	DDX_Control(pDX, IDC_closeserver, m_close);
	DDX_Control(pDX, IDC_set, m_set);
	DDX_Control(pDX, IDC_sendinfo, m_send);
	DDX_Control(pDX, IDC_send, m_button);
	DDX_Control(pDX, IDC_info, m_info);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CServerDlg, CDialog)
	//{{AFX_MSG_MAP(CServerDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_set, Onset)
	ON_BN_CLICKED(IDC_send, Onsend)
	ON_BN_CLICKED(IDC_startserver, Onstartserver)
	ON_BN_CLICKED(IDC_closeserver, Oncloseserver)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CServerDlg message handlers

BOOL CServerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

/*
	CFont *m_Font;
    m_Font = new CFont; 
    m_Font->CreateFont(25,10,0,0,50,
    FALSE,FALSE,0,ANSI_CHARSET,OUT_DEFAULT_PRECIS,
    CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,FF_SWISS,"Arial");
    CEdit *m_Edit=(CEdit *)GetDlgItem(IDC_IP1);
    m_Edit->SetFont(m_Font,FALSE);
    GetDlgItem(IDC_IP1)->SetFont(m_Font);

	m_Edit=(CEdit *)GetDlgItem(IDC_IP2);
    m_Edit->SetFont(m_Font,FALSE);
    GetDlgItem(IDC_IP2)->SetFont(m_Font);

	m_Edit=(CEdit *)GetDlgItem(IDC_retport);
    m_Edit->SetFont(m_Font,FALSE);
    GetDlgItem(IDC_retport)->SetFont(m_Font);

	m_list_ip.SetFont(m_Font);

	m_list_ip.InsertColumn(0,"IP");
	m_list_ip.SetColumnWidth(0,255);//*/
	isopen=0;
	WSADATA wsaData;	
	BOOL ret = WSAStartup(MAKEWORD(2,2), &wsaData);
	if(ret != 0)
	{
		MessageBox("初始化网络协议失败!");
		return -1;
	}
	UpdateData(false);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CServerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CServerDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CServerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CServerDlg::Onset() 
{
	// TODO: Add your control notification handler code here
	set dlg;
	if(dlg.DoModal()==IDOK)
	{
		port=dlg.m_port;
	}
	else
	{
		port=8888;
	}
}

BOOL CServerDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if (pMsg->message == WM_KEYDOWN && (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE))
	{
		Onsend();
		return 0;
	}
	return CDialog::PreTranslateMessage(pMsg);
}

void CServerDlg::Onsend()
{
	// TODO: Add your control notification handler code here
	if(!isopen)
	{
		AfxMessageBox("服务器没有启动!!!");
		return ;
	}
	int flag=0;
	int i;
	for(i=0;i<50;i++)//判断是否有客户连接
		if (msgsock[i]!=NULL)
		{
			flag=1;
			break;
		}
	if (flag!=1)
	{
		AfxMessageBox("没有客户连接!!!");
		return ;
	}

	if(m_send.GetWindowTextLength()==0)
	{
		AfxMessageBox("消息不能为空!!!");
		return ;
	}
	char buff[100];
	CString str;
	CTime tm;
	tm=CTime::GetCurrentTime();
	str=tm.Format(" %X");
	str+="\n";
	Play(str);

	m_send.GetWindowText(buff,99);//获得当前文本框中的信息
	m_send.SetWindowText("");//清空文本框的信息
	str=buff;
	str+="\n";
	Play(str);

	for (i=0;i<50;i++)//循环向所有客户发送信息
	{
		if (msgsock[i]!=NULL)
			send(msgsock[i],buff,100,0);
	}
}

void CServerDlg::Onstartserver() 
{
	// TODO: Add your control notification handler code here
	char   name[128];  
	hostent*   pHost;
	gethostname(name,128);//获得主机名
	pHost=gethostbyname(name);//获得主机结构
	ip=inet_ntoa(*((in_addr*)pHost->h_addr));

	for(int i=0;i<50;i++)
	{
		msgsock[i]=NULL;
	}

	serv.sin_addr=*((in_addr*)pHost->h_addr);
	serv.sin_family=AF_INET;
	serv.sin_port=port;
	addlen=sizeof(serv);
	sock=socket(AF_INET,SOCK_STREAM,0);
	if(bind(sock,(sockaddr*)&serv,addlen))
	{
		Play("绑定错误!!!\n");
	}
	else
	{
		Play("服务器启动成功!!!\n");
		isopen=1;
		m_set.EnableWindow(0);
		m_button.EnableWindow(0);
		m_open.EnableWindow(0);
		listen(sock,5);
		AfxBeginThread(&thread,0);
	}
}

void CServerDlg::Play(CString str)
{
	LPCTSTR pDisplay;
	pDisplay = _T(str);//转换成LPCTSTR数据类型
	int nlength = m_info.GetWindowTextLength();//获取编辑框的字符数
	m_info.SetSel(nlength, nlength);//定位光标
	m_info.ReplaceSel(pDisplay);//光标处显示
}

int CServerDlg::getcount()
{
	int i;
	for(i=0;i<50;i++)
		if(msgsock[i]==NULL) break;
	if(i==50) return -1;
	return i;
}

void CServerDlg::Oncloseserver() 
{
	// TODO: Add your control notification handler code here
	int i;
	closesocket(sock);
	for(i=0;i<50;i++) 
	{
		msgsock[i]=NULL;
		closesocket(msgsock[i]);
	}
	m_set.EnableWindow(1);
	m_open.EnableWindow(1);
	isopen=0;
	Play("服务器已关闭!!!\n");
}

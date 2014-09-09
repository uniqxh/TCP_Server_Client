; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CServerDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "server.h"

ClassCount=4
Class1=CServerApp
Class2=CServerDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_SERVER_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Class4=set
Resource4=IDD_set

[CLS:CServerApp]
Type=0
HeaderFile=server.h
ImplementationFile=server.cpp
Filter=N

[CLS:CServerDlg]
Type=0
HeaderFile=serverDlg.h
ImplementationFile=serverDlg.cpp
Filter=D
LastObject=CServerDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=serverDlg.h
ImplementationFile=serverDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SERVER_DIALOG]
Type=1
Class=CServerDlg
ControlCount=6
Control1=IDC_info,edit,1352728580
Control2=IDC_set,button,1342242816
Control3=IDC_startserver,button,1342242816
Control4=IDC_closeserver,button,1342242816
Control5=IDC_sendinfo,edit,1350631552
Control6=IDC_send,button,1342242816

[DLG:IDD_set]
Type=1
Class=set
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308866
Control4=IDC_IP,SysIPAddress32,1342242816
Control5=IDC_STATIC,static,1342308866
Control6=IDC_port,edit,1350631552

[CLS:set]
Type=0
HeaderFile=set.h
ImplementationFile=set.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=set


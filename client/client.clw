; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CClientDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "client.h"

ClassCount=4
Class1=CClientApp
Class2=CClientDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_CLIENT_DIALOG
Class4=set
Resource4=IDD_DIALOG1

[CLS:CClientApp]
Type=0
HeaderFile=client.h
ImplementationFile=client.cpp
Filter=N

[CLS:CClientDlg]
Type=0
HeaderFile=clientDlg.h
ImplementationFile=clientDlg.cpp
Filter=D
LastObject=CClientDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=clientDlg.h
ImplementationFile=clientDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_CLIENT_DIALOG]
Type=1
Class=CClientDlg
ControlCount=6
Control1=IDC_info,edit,1352728580
Control2=IDC_set,button,1342242816
Control3=IDC_con,button,1342242816
Control4=IDC_close,button,1342242816
Control5=IDC_send,edit,1350631552
Control6=IDC_button_send,button,1342242816

[DLG:IDD_DIALOG1]
Type=1
Class=set
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308866
Control4=IDC_IPADDRESS1,SysIPAddress32,1342242816
Control5=IDC_STATIC,static,1342308866
Control6=IDC_port,edit,1350631552

[CLS:set]
Type=0
HeaderFile=set.h
ImplementationFile=set.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_IPADDRESS1


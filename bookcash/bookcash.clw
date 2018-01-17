; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CBookcashDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "bookcash.h"

ClassCount=9
Class1=CBookcashApp
Class2=CBookcashDlg
Class3=CAboutDlg

ResourceCount=9
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_CASH_OLD_DIALOG
Class4=CNewOrderDialog
Resource4=IDD_BOOKCASH_DIALOG
Class5=CBillDialog
Resource5=IDD_CASH_RETURN_DIALOG
Class6=CCashRebateDlg
Resource6=IDD_NEW_ORDER
Class7=CCashReturnDlg
Resource7=IDD_BILLING_DIALOG
Class8=CCashOldDlg
Resource8=IDD_CASH_REBATE_DIALOG
Class9=CCashBuygetDlg
Resource9=IDD_CASH_BUYGET_DIALOG

[CLS:CBookcashApp]
Type=0
HeaderFile=bookcash.h
ImplementationFile=bookcash.cpp
Filter=N

[CLS:CBookcashDlg]
Type=0
HeaderFile=bookcashDlg.h
ImplementationFile=bookcashDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_ADD_ORDER

[CLS:CAboutDlg]
Type=0
HeaderFile=bookcashDlg.h
ImplementationFile=bookcashDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_BOOKCASH_DIALOG]
Type=1
Class=CBookcashDlg
ControlCount=11
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,button,1342177287
Control4=IDC_ORDER_LIST,SysListView32,1350631425
Control5=IDC_ADD_ORDER,button,1342242816
Control6=IDC_DEL_ORDER,button,1342242816
Control7=IDC_RESET_ORDER,button,1342242816
Control8=IDC_CASH_TYPE,combobox,1344339971
Control9=IDC_CASH_INFO,static,1342312448
Control10=IDC_STATIC,static,1342308352
Control11=IDC_BOOKMANAGE,button,1342242816

[DLG:IDD_NEW_ORDER]
Type=1
Class=CNewOrderDialog
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_BOOK_NAME,edit,1350631552
Control7=IDC_BOOK_PRICE,edit,1350631552
Control8=IDC_PURCHASE_NUM,edit,1350631552

[CLS:CNewOrderDialog]
Type=0
HeaderFile=NewOrderDialog.h
ImplementationFile=NewOrderDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=CNewOrderDialog
VirtualFilter=dWC

[DLG:IDD_BILLING_DIALOG]
Type=1
Class=CBillDialog
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_TOTAL_MONEY,edit,1350633600
Control7=IDC_PAY_MONEY,edit,1350631552
Control8=IDC_MAKE_CHANGE,edit,1350633600

[CLS:CBillDialog]
Type=0
HeaderFile=BillDialog.h
ImplementationFile=BillDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDOK

[DLG:IDD_CASH_REBATE_DIALOG]
Type=1
Class=CCashRebateDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_REBATE_RATE,edit,1350631552

[CLS:CCashRebateDlg]
Type=0
HeaderFile=CashRebateDlg.h
ImplementationFile=CashRebateDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CCashRebateDlg

[DLG:IDD_CASH_RETURN_DIALOG]
Type=1
Class=CCashReturnDlg
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_CASH_LIMIT,edit,1350631552
Control6=IDC_CASH_RETURN,edit,1350631552

[CLS:CCashReturnDlg]
Type=0
HeaderFile=CashReturnDlg.h
ImplementationFile=CashReturnDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDOK

[DLG:IDD_CASH_OLD_DIALOG]
Type=1
Class=CCashOldDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_OLD_PRICE,edit,1350631552

[CLS:CCashOldDlg]
Type=0
HeaderFile=CashOldDlg.h
ImplementationFile=CashOldDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDOK

[DLG:IDD_CASH_BUYGET_DIALOG]
Type=1
Class=CCashBuygetDlg
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_CASH_BUY,edit,1350631552
Control6=IDC_CASH_GET,edit,1350631552

[CLS:CCashBuygetDlg]
Type=0
HeaderFile=CashBuygetDlg.h
ImplementationFile=CashBuygetDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDOK


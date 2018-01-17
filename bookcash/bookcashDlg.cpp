// bookcashDlg.cpp : implementation file
//

#include "stdafx.h"
#include "bookcash.h"
#include "bookcashDlg.h"
#include "NewOrderDialog.h"
#include "BillDialog.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

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
// CBookcashDlg dialog
void CBookcashDlg::InitOrderList()
{
	m_OrderList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	LV_COLUMN lvColumn;
	lvColumn.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
	lvColumn.fmt = LVCFMT_CENTER;

	lvColumn.cx = 110;
	lvColumn.iSubItem = 0;
	lvColumn.pszText = "图书名称";
	m_OrderList.InsertColumn(0, &lvColumn);

	lvColumn.cx = 100;
	lvColumn.iSubItem = 1;
	lvColumn.pszText = "单价";
	m_OrderList.InsertColumn(1, &lvColumn);

	lvColumn.cx = 100;
	lvColumn.iSubItem = 2;
	lvColumn.pszText = "数量";
	m_OrderList.InsertColumn(2, &lvColumn);

	lvColumn.cx = 100;
	lvColumn.iSubItem = 3;
	lvColumn.pszText = "金额";
	m_OrderList.InsertColumn(3, &lvColumn);
}

CBookcashDlg::CBookcashDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBookcashDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBookcashDlg)
	m_nCashType = 0;
	m_sCashInfo = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_pBookCash = NULL;
}

CBookcashDlg::~CBookcashDlg()
{
	ReleaseCashActivity(&m_pBookCash);
}

void CBookcashDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBookcashDlg)
	DDX_Control(pDX, IDC_ORDER_LIST, m_OrderList);
	DDX_CBIndex(pDX, IDC_CASH_TYPE, m_nCashType);
	DDX_Text(pDX, IDC_CASH_INFO, m_sCashInfo);
	DDV_MaxChars(pDX, m_sCashInfo, 100);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CBookcashDlg, CDialog)
	//{{AFX_MSG_MAP(CBookcashDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD_ORDER, OnAddOrder)
	ON_BN_CLICKED(IDC_DEL_ORDER, OnDelOrder)
	ON_BN_CLICKED(IDC_RESET_ORDER, OnResetOrder)
	ON_CBN_SELCHANGE(IDC_CASH_TYPE, OnSelchangeCashType)
	ON_BN_CLICKED(IDC_BOOKMANAGE, OnBookmanage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBookcashDlg message handlers

BOOL CBookcashDlg::OnInitDialog()
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
	InitOrderList();
	m_pBookCash = CreateCashActivity(m_nCashType);       //多态调用
	m_sCashInfo = m_pBookCash->GetCashInfo();
	UpdateData(FALSE);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBookcashDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CBookcashDlg::OnPaint() 
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
HCURSOR CBookcashDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
void CBookcashDlg::AddOrderToList(const char* sBookName, double dBookPrice, int nPurchaseNum)
{
	LV_ITEM lvItem;
	lvItem.mask = LVIF_TEXT;

	int n = m_OrderList.GetItemCount();
	lvItem.iItem = n;
	lvItem.iSubItem = 0;
	lvItem.pszText = (char *)sBookName;
	m_OrderList.InsertItem(&lvItem);
	m_OrderList.SetItemData(n, n);
	
	char strText[32];
	sprintf(strText, "%.3lf", dBookPrice);
	m_OrderList.SetItemText(n, 1, strText);
	
	sprintf(strText, "%d", nPurchaseNum);
	m_OrderList.SetItemText(n, 2, strText);
	
	sprintf(strText, "%.3lf", dBookPrice*nPurchaseNum);
	m_OrderList.SetItemText(n, 3, strText);
}
void CBookcashDlg::OnAddOrder() 
{
	// TODO: Add your control notification handler code here
	CNewOrderDialog dialog;
	//dialog.DoModal();
	if (dialog.DoModal() == IDOK){
		CString sBookName = dialog.m_sBookName;
		double dBookPrice = dialog.m_dBookPrice;
		int nPurchaseNum  = dialog.m_nPurchaseNum;
		
		AddOrderToList(sBookName, dBookPrice, nPurchaseNum);
	}
}

void CBookcashDlg::OnDelOrder() 
{
	// TODO: Add your control notification handler code here
	int iItem = m_OrderList.GetNextItem(-1, LVNI_SELECTED);
	while (iItem != -1){
		m_OrderList.DeleteItem(iItem);
		iItem = m_OrderList.GetNextItem(iItem, LVNI_SELECTED);
	}
}

void CBookcashDlg::OnResetOrder() 
{
	// TODO: Add your control notification handler code here
	m_OrderList.DeleteAllItems();
}

void CBookcashDlg::OnOK() 
{
	// TODO: Add extra validation here
	int nItem = m_OrderList.GetItemCount();
	if (nItem < 1){
		AfxMessageBox("没有任何订单！");
		return;
	}

	BookOrder order;
	m_pBookCash->SetOrderNum(nItem);
	for (int i=0; i<nItem; i++){
		order.price = atof(m_OrderList.GetItemText(i, 1));
		order.sum   = atoi(m_OrderList.GetItemText(i, 2));
		m_pBookCash->SetOrder(i, order);
	}

	CBillDialog dialog;
	dialog.m_dTotalMoney = m_pBookCash->CalcCash();
	dialog.DoModal();
	
	CDialog::OnOK();
}

void CBookcashDlg::OnSelchangeCashType() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	CCashBase* pCash = CreateCashActivity(m_nCashType);
	if (pCash){
		ReleaseCashActivity(&m_pBookCash);
		m_pBookCash = pCash;
		m_sCashInfo = m_pBookCash->GetCashInfo();
	}
	m_nCashType = m_pBookCash->m_nType;
	UpdateData(FALSE);
}

void CBookcashDlg::OnBookmanage() 
{
	// TODO: Add your control notification handler code here
	ShellExecute(   m_hWnd, 
                    "open", 
                    "bookmanage.exe", 
                    NULL,
                    NULL,
                    SW_SHOWNORMAL);
}

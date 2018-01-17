// CashBuygetDlg.cpp : implementation file
//

#include "stdafx.h"
#include "bookcash.h"
#include "CashBuygetDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCashBuygetDlg dialog


CCashBuygetDlg::CCashBuygetDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCashBuygetDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCashBuygetDlg)
	m_iCashBuy = 2;
	m_iCashGet = 1;
	//}}AFX_DATA_INIT
}


void CCashBuygetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCashBuygetDlg)
	DDX_Text(pDX, IDC_CASH_BUY, m_iCashBuy);
	DDV_MinMaxInt(pDX, m_iCashBuy, 0, 100000);
	DDX_Text(pDX, IDC_CASH_GET, m_iCashGet);
	DDV_MinMaxInt(pDX, m_iCashGet, 0, 100000);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCashBuygetDlg, CDialog)
	//{{AFX_MSG_MAP(CCashBuygetDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCashBuygetDlg message handlers

void CCashBuygetDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	if (m_iCashGet >= m_iCashBuy){
		AfxMessageBox("赠送数量必须少于购买数量！");
		return;
	}
	CDialog::OnOK();
}

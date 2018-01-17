// CashReturnDlg.cpp : implementation file
//

#include "stdafx.h"
#include "bookcash.h"
#include "CashReturnDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCashReturnDlg dialog


CCashReturnDlg::CCashReturnDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCashReturnDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCashReturnDlg)
	m_dCashLimit = 500;
	m_dCashReturn = 100;
	//}}AFX_DATA_INIT
}


void CCashReturnDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCashReturnDlg)
	DDX_Text(pDX, IDC_CASH_LIMIT, m_dCashLimit);
	DDV_MinMaxDouble(pDX, m_dCashLimit, 1., 999999.);
	DDX_Text(pDX, IDC_CASH_RETURN, m_dCashReturn);
	DDV_MinMaxDouble(pDX, m_dCashReturn, 1., 999999.);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCashReturnDlg, CDialog)
	//{{AFX_MSG_MAP(CCashReturnDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCashReturnDlg message handlers

void CCashReturnDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	if (m_dCashReturn >= m_dCashLimit){
		AfxMessageBox("返利条件不能少于返利金额！");
		return;
	}
	CDialog::OnOK();
}

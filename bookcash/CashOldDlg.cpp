// CashOldDlg.cpp : implementation file
//

#include "stdafx.h"
#include "bookcash.h"
#include "CashOldDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCashOldDlg dialog


CCashOldDlg::CCashOldDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCashOldDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCashOldDlg)
	m_dOldPrice = 5.0;
	//}}AFX_DATA_INIT
}


void CCashOldDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCashOldDlg)
	DDX_Text(pDX, IDC_OLD_PRICE, m_dOldPrice);
	DDV_MinMaxDouble(pDX, m_dOldPrice, 0., 100000.);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCashOldDlg, CDialog)
	//{{AFX_MSG_MAP(CCashOldDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCashOldDlg message handlers

void CCashOldDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	CDialog::OnOK();
}

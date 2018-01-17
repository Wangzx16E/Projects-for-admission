// CashRebateDlg.cpp : implementation file
//

#include "stdafx.h"
#include "bookcash.h"
#include "CashRebateDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCashRebateDlg dialog


CCashRebateDlg::CCashRebateDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCashRebateDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCashRebateDlg)
	m_dRebateRate = 0.9;
	//}}AFX_DATA_INIT
}


void CCashRebateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCashRebateDlg)
	DDX_Text(pDX, IDC_REBATE_RATE, m_dRebateRate);
	DDV_MinMaxDouble(pDX, m_dRebateRate, 0., 1.);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCashRebateDlg, CDialog)
	//{{AFX_MSG_MAP(CCashRebateDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCashRebateDlg message handlers

void CCashRebateDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	CDialog::OnOK();
}

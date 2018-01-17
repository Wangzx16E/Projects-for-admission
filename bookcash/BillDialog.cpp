// BillDialog.cpp : implementation file
//

#include "stdafx.h"
#include "bookcash.h"
#include "BillDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBillDialog dialog


CBillDialog::CBillDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CBillDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBillDialog)
	m_dTotalMoney = 0.0;
	m_dPay = 0.0;
	m_dChange = 0.0;
	//}}AFX_DATA_INIT
}


void CBillDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBillDialog)
	DDX_Text(pDX, IDC_TOTAL_MONEY, m_dTotalMoney);
	DDX_Text(pDX, IDC_PAY_MONEY, m_dPay);
	DDX_Text(pDX, IDC_MAKE_CHANGE, m_dChange);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBillDialog, CDialog)
	//{{AFX_MSG_MAP(CBillDialog)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBillDialog message handlers

void CBillDialog::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);

	if (m_dPay < m_dTotalMoney){
		AfxMessageBox("交费不足！");
		return;
	}
	
	m_dChange = m_dPay - m_dTotalMoney; 
	m_dChange = ((int)(m_dChange*100.0 + 0.50))/100.0;           //保留到小数点后2位
	UpdateData(FALSE);
}

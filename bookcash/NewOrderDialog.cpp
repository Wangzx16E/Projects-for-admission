// NewOrderDialog.cpp : implementation file
//

#include "stdafx.h"
#include "bookcash.h"
#include "NewOrderDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNewOrderDialog dialog


CNewOrderDialog::CNewOrderDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CNewOrderDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNewOrderDialog)
	m_sBookName = _T("");
	m_dBookPrice = 0.0;
	m_nPurchaseNum = 1;
	//}}AFX_DATA_INIT
}


void CNewOrderDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNewOrderDialog)
	DDX_Text(pDX, IDC_BOOK_NAME, m_sBookName);
	DDV_MaxChars(pDX, m_sBookName, 32);
	DDX_Text(pDX, IDC_BOOK_PRICE, m_dBookPrice);
	DDV_MinMaxDouble(pDX, m_dBookPrice, 1.e-002, 10000.);
	DDX_Text(pDX, IDC_PURCHASE_NUM, m_nPurchaseNum);
	DDV_MinMaxInt(pDX, m_nPurchaseNum, 1, 10000);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNewOrderDialog, CDialog)
	//{{AFX_MSG_MAP(CNewOrderDialog)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNewOrderDialog message handlers

void CNewOrderDialog::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	if (m_sBookName.IsEmpty()){
		AfxMessageBox("«Î ‰»ÎÕº È√˚≥∆£°");
		return;
	}
	CDialog::OnOK();
}

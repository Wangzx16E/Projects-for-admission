// CashBuyget.cpp: implementation of the CCashBuyget class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "bookcash.h"
#include "CashBuyget.h"
#include "CashBuygetDlg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCashBuyget::CCashBuyget()
{
	m_iCashBuy  = 2;
	m_iCashGet = 1;
	sprintf(m_strInfo, "相同图书\n买%d送%d\n", m_iCashBuy, m_iCashGet);
	m_nType = 4;

}

CCashBuyget::~CCashBuyget()
{

}

bool CCashBuyget::Create(){
	CCashBuygetDlg dialog;
	if (dialog.DoModal() == IDOK){
		m_iCashBuy = dialog.m_iCashBuy;
		m_iCashGet = dialog.m_iCashGet;
		sprintf(m_strInfo, "相同图书\n买%d送%d\n", m_iCashBuy, m_iCashGet);
		return true;
	}
	return false;
}

double CCashBuyget::CalcCash(){
	double dTotalPrice = 0;
	for (int i=0; i<CCashBase::m_nOrder; i++){
		
			dTotalPrice += CCashBase::m_bOrder[i].price*(CCashBase::m_bOrder[i].sum-(CCashBase::m_bOrder[i].sum/m_iCashBuy)*m_iCashGet);
        
	}
	return dTotalPrice;
}
// CashReturn.cpp: implementation of the CCashReturn class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "bookcash.h"
#include "CashReturn.h"
#include "CashReturnDlg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CCashReturn::CCashReturn(){
	m_dCashLimit  = 500.0;
	m_dCashReturn = 100.0;
	sprintf(m_strInfo, "Âú %.2lf\n·µ %.2lf\n", m_dCashLimit, m_dCashReturn);
	m_nType = 2;
}

CCashReturn::~CCashReturn(){
}

bool CCashReturn::Create(){
	CCashReturnDlg dialog;
	if (dialog.DoModal() == IDOK){
		m_dCashLimit  = dialog.m_dCashLimit;
		m_dCashReturn = dialog.m_dCashReturn;
		sprintf(m_strInfo, "Âú %.2lf\n·µ %.2lf\n", m_dCashLimit, m_dCashReturn);
		return true;
	}
	return false;
}

double CCashReturn::CalcCash(){
	double dTotalPrice = CCashBase::CalcCash();
	dTotalPrice -= ((int)(dTotalPrice/m_dCashLimit))*m_dCashReturn;
	return dTotalPrice;
}



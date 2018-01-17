// CashRebate.cpp: implementation of the CCashRebate class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "bookcash.h"
#include "CashRebate.h"
#include "CashRebateDlg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CCashRebate::CCashRebate()
{
	m_dRebateRate = 1.0;
	sprintf(m_strInfo, "打折率：%.2lf\n", m_dRebateRate);
	m_nType = 1;
}

CCashRebate::~CCashRebate()
{
}

bool CCashRebate::Create()
{
	CCashRebateDlg dialog;
	if (dialog.DoModal() == IDOK){
		m_dRebateRate = dialog.m_dRebateRate;
		sprintf(m_strInfo, "打折率：%.2lf\n", m_dRebateRate);
		return true;
	}
	return false;
}

double CCashRebate::CalcCash(){
	double dTotalPrice = m_dRebateRate*CCashBase::CalcCash();
	return dTotalPrice;
}

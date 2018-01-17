// CashOld.cpp: implementation of the CCashOld class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "bookcash.h"
#include "CashOld.h"
#include "CashOldDlg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCashOld::CCashOld()
{
	m_dOldPrice=5;
	sprintf(m_strInfo, "旧书统一单价：每本%.2lf元\n", m_dOldPrice);
	m_nType = 3;
}

CCashOld::~CCashOld()
{

}

bool CCashOld::Create()
{
	CCashOldDlg dialog;
	if (dialog.DoModal() == IDOK){
		m_dOldPrice = dialog.m_dOldPrice;
		sprintf(m_strInfo, "旧书统一单价：每本%.2lf元\n", m_dOldPrice);
		return true;
	}
	return false;
}

double CCashOld::CalcCash()
{
	double dTotalPrice=0;
	for (int i=0; i<CCashBase::m_nOrder; i++){
		dTotalPrice += m_dOldPrice*CCashBase::m_bOrder[i].sum;
	}
	return dTotalPrice;
}
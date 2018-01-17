// CashBase.cpp: implementation of the CCashBase class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "bookcash.h"
#include "CashBase.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCashBase::CCashBase()
{
	strcpy(m_strInfo, "");
	m_bOrder = NULL;
	m_nOrder = 0;
	m_nType  = 0;
}

CCashBase::~CCashBase()
{
	Reset();
}

void CCashBase::Reset()
{
	if (m_bOrder){
		delete[] m_bOrder;
		m_bOrder = NULL;
		m_nOrder = 0;
	}
}

void CCashBase::SetOrderNum(int num)
{
	Reset();
	if (num < 1) return;
	m_bOrder = new BookOrder[num];
	memset(m_bOrder, 0, num*sizeof(BookOrder));
	m_nOrder = num;
}

void CCashBase::SetOrder(int index, BookOrder order)
{
	if (index >= 0 && index < m_nOrder){
		m_bOrder[index] = order;
	}
}

double CCashBase::CalcCash()
{
	double dTotalPrice = 0;
	for (int i=0; i<m_nOrder; i++){
		dTotalPrice += m_bOrder[i].price*m_bOrder[i].sum;
	}
	return dTotalPrice;
}
//////////////////È«¾Öº¯Êý///////////////////////////////////
#include "CashNone.h"
#include "CashRebate.h"
#include "CashReturn.h"
#include "CashOld.h"
#include "CashBuyget.h"

CCashBase* CreateCashActivity(int nType){
	CCashBase* bCash = NULL;
	switch (nType){
		case 0:  bCash = new CCashNone;   break;
		case 1:  bCash = new CCashRebate; break;
		case 2:  bCash = new CCashReturn; break;
		case 3:  bCash = new CCashOld;    break;
		case 4:  bCash = new CCashBuyget; break;
		default: bCash = new CCashNone;   break;
	}
	
	if (!bCash->Create()){
		delete bCash;
		bCash = NULL;
	}

	return bCash;
}

void ReleaseCashActivity(CCashBase** bCash){
	if ((*bCash)){
		delete (*bCash);
		(*bCash) = NULL;
	}
}

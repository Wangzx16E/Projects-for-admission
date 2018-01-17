// CashRebate.h: interface for the CCashRebate class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CASHREBATE_H__B789CD76_C50E_494A_A1EE_91F087CCB1B4__INCLUDED_)
#define AFX_CASHREBATE_H__B789CD76_C50E_494A_A1EE_91F087CCB1B4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CashBase.h"

class CCashRebate : public CCashBase  
{
public:
	CCashRebate();
	virtual ~CCashRebate();

	virtual bool Create();
	virtual double CalcCash();

protected:
	double m_dRebateRate;

};

#endif // !defined(AFX_CASHREBATE_H__B789CD76_C50E_494A_A1EE_91F087CCB1B4__INCLUDED_)

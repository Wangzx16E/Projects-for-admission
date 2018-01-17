// CashBuyget.h: interface for the CCashBuyget class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CASHBUYGET_H__8B2F6075_2742_41CF_BC7A_2DEA3F1842A9__INCLUDED_)
#define AFX_CASHBUYGET_H__8B2F6075_2742_41CF_BC7A_2DEA3F1842A9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CashBase.h"

class CCashBuyget : public CCashBase  
{
public:
	CCashBuyget();
	virtual ~CCashBuyget();

	virtual bool Create();
	virtual double CalcCash();
protected:
	int m_iCashBuy;
	int m_iCashGet;
};

#endif // !defined(AFX_CASHBUYGET_H__8B2F6075_2742_41CF_BC7A_2DEA3F1842A9__INCLUDED_)

// CashReturn.h: interface for the CCashReturn class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CASHRETURN_H__0A387FBD_84B5_4CB3_B230_9AA6BB743D7B__INCLUDED_)
#define AFX_CASHRETURN_H__0A387FBD_84B5_4CB3_B230_9AA6BB743D7B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CashBase.h"

class CCashReturn : public CCashBase  
{
public:
	CCashReturn();
	virtual ~CCashReturn();

	virtual bool Create();
	virtual double CalcCash();

protected:
	double m_dCashLimit;
	double m_dCashReturn;
};

#endif // !defined(AFX_CASHRETURN_H__0A387FBD_84B5_4CB3_B230_9AA6BB743D7B__INCLUDED_)

// CashOld.h: interface for the CCashOld class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CASHOLD_H__B4F3DE62_91E2_4DE1_8EC1_DE27DC200435__INCLUDED_)
#define AFX_CASHOLD_H__B4F3DE62_91E2_4DE1_8EC1_DE27DC200435__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CashBase.h"

class CCashOld : public CCashBase  
{
public:
	CCashOld();
	virtual ~CCashOld();

    virtual bool Create();
	virtual double CalcCash();
protected:
	double m_dOldPrice;
};

#endif // !defined(AFX_CASHOLD_H__B4F3DE62_91E2_4DE1_8EC1_DE27DC200435__INCLUDED_)

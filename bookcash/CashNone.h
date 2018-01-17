// CashNone.h: interface for the CCashNone class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CASHNONE_H__A75F1078_227D_4E89_975C_D9D686CE761D__INCLUDED_)
#define AFX_CASHNONE_H__A75F1078_227D_4E89_975C_D9D686CE761D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CashBase.h"

class CCashNone : public CCashBase  
{
public:
	CCashNone();
	virtual ~CCashNone();

	virtual double CalcCash(){
		return CCashBase::CalcCash();
	};
};


#endif // !defined(AFX_CASHNONE_H__A75F1078_227D_4E89_975C_D9D686CE761D__INCLUDED_)

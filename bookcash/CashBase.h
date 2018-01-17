// CashBase.h: interface for the CCashBase class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CASHBASE_H__4DCB7451_CFE6_4290_9316_3CDBCD03EA32__INCLUDED_)
#define AFX_CASHBASE_H__4DCB7451_CFE6_4290_9316_3CDBCD03EA32__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

typedef struct tagBookOrder{
	double price;
	int sum;
}BookOrder;

class CCashBase{
public:
	CCashBase();
	virtual ~CCashBase();

	virtual bool Create(){return true;};
	virtual double CalcCash();
	
	void SetOrderNum(int num);
	void SetOrder(int index, BookOrder order);
	void Reset();

	const char* GetCashInfo(){return m_strInfo;};

	int m_nType;

protected:
	char m_strInfo[256];
	BookOrder* m_bOrder;
	int m_nOrder;
};

CCashBase* CreateCashActivity(int nType);
void ReleaseCashActivity(CCashBase** bCash);


#endif // !defined(AFX_CASHBASE_H__4DCB7451_CFE6_4290_9316_3CDBCD03EA32__INCLUDED_)

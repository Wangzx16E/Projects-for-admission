// CashNone.cpp: implementation of the CCashNone class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "bookcash.h"
#include "CashNone.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCashNone::CCashNone()
{
	strcpy(m_strInfo, "无促销活动");
	m_nType = 0;
}

CCashNone::~CCashNone()
{

}

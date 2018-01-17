// bookcashDlg.h : header file
//

#if !defined(AFX_BOOKCASHDLG_H__E69D7041_D272_4918_B4FB_E27D3B22CB98__INCLUDED_)
#define AFX_BOOKCASHDLG_H__E69D7041_D272_4918_B4FB_E27D3B22CB98__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBookcashDlg dialog

#include "CashBase.h"

class CBookcashDlg : public CDialog
{
// Construction
public:
	CBookcashDlg(CWnd* pParent = NULL);	// standard constructor
	~CBookcashDlg();

// Dialog Data
	//{{AFX_DATA(CBookcashDlg)
	enum { IDD = IDD_BOOKCASH_DIALOG };
	CListCtrl	m_OrderList;
	int		m_nCashType;
	CString	m_sCashInfo;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBookcashDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CCashBase* m_pBookCash;           //∂‡Ã¨
    void InitOrderList();
	void AddOrderToList(const char* sBookName, double dBookPrice, int nPurchaseNum);
	// Generated message map functions
	//{{AFX_MSG(CBookcashDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAddOrder();
	afx_msg void OnDelOrder();
	afx_msg void OnResetOrder();
	virtual void OnOK();
	afx_msg void OnSelchangeCashType();
	afx_msg void OnBookmanage();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BOOKCASHDLG_H__E69D7041_D272_4918_B4FB_E27D3B22CB98__INCLUDED_)

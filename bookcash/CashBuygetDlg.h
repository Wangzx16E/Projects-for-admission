#if !defined(AFX_CASHBUYGETDLG_H__E275B615_D50C_49D6_8C4C_0DBB2C614401__INCLUDED_)
#define AFX_CASHBUYGETDLG_H__E275B615_D50C_49D6_8C4C_0DBB2C614401__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CashBuygetDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCashBuygetDlg dialog

class CCashBuygetDlg : public CDialog
{
// Construction
public:
	CCashBuygetDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCashBuygetDlg)
	enum { IDD = IDD_CASH_BUYGET_DIALOG };
	int		m_iCashBuy;
	int		m_iCashGet;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCashBuygetDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCashBuygetDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CASHBUYGETDLG_H__E275B615_D50C_49D6_8C4C_0DBB2C614401__INCLUDED_)

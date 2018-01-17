#if !defined(AFX_CASHRETURNDLG_H__635C8699_EDAF_4077_871D_3AD224361EDD__INCLUDED_)
#define AFX_CASHRETURNDLG_H__635C8699_EDAF_4077_871D_3AD224361EDD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CashReturnDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCashReturnDlg dialog

class CCashReturnDlg : public CDialog
{
// Construction
public:
	CCashReturnDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCashReturnDlg)
	enum { IDD = IDD_CASH_RETURN_DIALOG };
	double	m_dCashLimit;
	double	m_dCashReturn;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCashReturnDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCashReturnDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CASHRETURNDLG_H__635C8699_EDAF_4077_871D_3AD224361EDD__INCLUDED_)

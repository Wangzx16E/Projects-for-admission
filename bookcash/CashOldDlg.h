#if !defined(AFX_CASHOLDDLG_H__F84A5C90_515A_4C71_B6E9_86DA51E5D12F__INCLUDED_)
#define AFX_CASHOLDDLG_H__F84A5C90_515A_4C71_B6E9_86DA51E5D12F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CashOldDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCashOldDlg dialog

class CCashOldDlg : public CDialog
{
// Construction
public:
	CCashOldDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCashOldDlg)
	enum { IDD = IDD_CASH_OLD_DIALOG };
	double	m_dOldPrice;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCashOldDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCashOldDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CASHOLDDLG_H__F84A5C90_515A_4C71_B6E9_86DA51E5D12F__INCLUDED_)

#if !defined(AFX_BILLDIALOG_H__6F3ADB5E_2C7E_4F0E_ABB0_FB76EE1416C4__INCLUDED_)
#define AFX_BILLDIALOG_H__6F3ADB5E_2C7E_4F0E_ABB0_FB76EE1416C4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BillDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBillDialog dialog

class CBillDialog : public CDialog
{
// Construction
public:
	CBillDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CBillDialog)
	enum { IDD = IDD_BILLING_DIALOG };
	double	m_dTotalMoney;
	double	m_dPay;
	double	m_dChange;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBillDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBillDialog)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BILLDIALOG_H__6F3ADB5E_2C7E_4F0E_ABB0_FB76EE1416C4__INCLUDED_)

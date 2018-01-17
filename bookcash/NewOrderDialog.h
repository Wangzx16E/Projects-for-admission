#if !defined(AFX_NEWORDERDIALOG_H__2EFDAC34_135C_4EE4_8CE1_C893BAD5F6F9__INCLUDED_)
#define AFX_NEWORDERDIALOG_H__2EFDAC34_135C_4EE4_8CE1_C893BAD5F6F9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NewOrderDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNewOrderDialog dialog

class CNewOrderDialog : public CDialog
{
// Construction
public:
	CNewOrderDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CNewOrderDialog)
	enum { IDD = IDD_NEW_ORDER };
	CString	m_sBookName;
	double	m_dBookPrice;
	int		m_nPurchaseNum;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewOrderDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNewOrderDialog)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWORDERDIALOG_H__2EFDAC34_135C_4EE4_8CE1_C893BAD5F6F9__INCLUDED_)

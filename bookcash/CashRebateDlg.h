#if !defined(AFX_CASHREBATEDLG_H__4DA8A966_5C91_4088_8E19_FB1D5D9D0263__INCLUDED_)
#define AFX_CASHREBATEDLG_H__4DA8A966_5C91_4088_8E19_FB1D5D9D0263__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CashRebateDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCashRebateDlg dialog

class CCashRebateDlg : public CDialog
{
// Construction
public:
	CCashRebateDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCashRebateDlg)
	enum { IDD = IDD_CASH_REBATE_DIALOG };
	double	m_dRebateRate;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCashRebateDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCashRebateDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CASHREBATEDLG_H__4DA8A966_5C91_4088_8E19_FB1D5D9D0263__INCLUDED_)

// bookcash.h : main header file for the BOOKCASH application
//

#if !defined(AFX_BOOKCASH_H__1BE0EA9C_8F6B_4A01_B09D_664CC1FADFC0__INCLUDED_)
#define AFX_BOOKCASH_H__1BE0EA9C_8F6B_4A01_B09D_664CC1FADFC0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBookcashApp:
// See bookcash.cpp for the implementation of this class
//

class CBookcashApp : public CWinApp
{
public:
	CBookcashApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBookcashApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBookcashApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BOOKCASH_H__1BE0EA9C_8F6B_4A01_B09D_664CC1FADFC0__INCLUDED_)

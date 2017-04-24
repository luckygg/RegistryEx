
// FTech_RegistryExDlg.h : header file
//

#pragma once

#include "RegistryEx.h"

// CFTech_RegistryExDlg dialog
class CFTech_RegistryExDlg : public CDialogEx
{
// Construction
public:
	CFTech_RegistryExDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_FTECH_REGISTRYEX_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnAdd();
	afx_msg void OnBnClickedBtnDelete();
};

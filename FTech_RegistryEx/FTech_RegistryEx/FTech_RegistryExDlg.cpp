
// FTech_RegistryExDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FTech_RegistryEx.h"
#include "FTech_RegistryExDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFTech_RegistryExDlg dialog




CFTech_RegistryExDlg::CFTech_RegistryExDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFTech_RegistryExDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFTech_RegistryExDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFTech_RegistryExDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_ADD, &CFTech_RegistryExDlg::OnBnClickedBtnAdd)
	ON_BN_CLICKED(IDC_BTN_DELETE, &CFTech_RegistryExDlg::OnBnClickedBtnDelete)
END_MESSAGE_MAP()


// CFTech_RegistryExDlg message handlers

BOOL CFTech_RegistryExDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFTech_RegistryExDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFTech_RegistryExDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFTech_RegistryExDlg::OnBnClickedBtnAdd()
{
	bool ret=false;
	ret = CRegistryEx::OnAddKey(CURRENT_USER, _T("Software"), _T("TEST"));
	if (ret == true)
	{
		ret = CRegistryEx::SetValue(CURRENT_USER, _T("Software\\TEST"), _T("My Value"), _T("TEXT"));
		if (ret == false)
			AfxMessageBox(_T("실패."));
	}
	
}


void CFTech_RegistryExDlg::OnBnClickedBtnDelete()
{
	bool ret=false;
	ret = CRegistryEx::OnDeleteKey(CURRENT_USER, _T("Software"), _T("TEST"));
	if (ret == false)
		AfxMessageBox(_T("실패."));
}

#pragma once
#include "afxwin.h"

// TextInputDlg ��ȭ �����Դϴ�.

class CChildView;

class TextInputDlg : public CDialogEx
{
	DECLARE_DYNAMIC(TextInputDlg)

public:
	TextInputDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	TextInputDlg(CWnd* pParent = NULL, CChildView *childView);
	virtual ~TextInputDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CEdit etxtView;
	CButton radioButtons[3];
	afx_msg void OnBnClickedOk();
	int selectedColor;
	CChildView *childView;
};

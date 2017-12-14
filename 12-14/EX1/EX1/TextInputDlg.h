#pragma once
#include "afxwin.h"

// TextInputDlg 대화 상자입니다.

class CChildView;

class TextInputDlg : public CDialogEx
{
	DECLARE_DYNAMIC(TextInputDlg)

public:
	TextInputDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	TextInputDlg(CWnd* pParent = NULL, CChildView *childView);
	virtual ~TextInputDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CEdit etxtView;
	CButton radioButtons[3];
	afx_msg void OnBnClickedOk();
	int selectedColor;
	CChildView *childView;
};

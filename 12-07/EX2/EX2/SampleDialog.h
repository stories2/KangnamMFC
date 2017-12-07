#pragma once
#include "afxwin.h"


// SampleDialog 대화 상자입니다.

class SampleDialog : public CDialogEx
{
	DECLARE_DYNAMIC(SampleDialog)

public:
	SampleDialog(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~SampleDialog();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CEdit etxtView;
	CButton radioColor;
};

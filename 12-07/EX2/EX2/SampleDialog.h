#pragma once
#include "afxwin.h"


// SampleDialog ��ȭ �����Դϴ�.

class SampleDialog : public CDialogEx
{
	DECLARE_DYNAMIC(SampleDialog)

public:
	SampleDialog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~SampleDialog();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CEdit etxtView;
	CButton radioColor;
};

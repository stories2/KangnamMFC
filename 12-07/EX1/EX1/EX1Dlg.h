
// EX1Dlg.h : ��� ����
//

#pragma once
#include "afxwin.h"


// CEX1Dlg ��ȭ ����
class CEX1Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CEX1Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_EX1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CEdit etxtSample;
	CString etxtSampleText;
	afx_msg void OnBnClickedOk();
	CListBox listSample;
	CButton btnAdd;
	CButton btnRemove;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};


// ChildView.h : CChildView Ŭ������ �������̽�
//


#pragma once
#include "dialog.h"
#include "SampleDialog.h"

// CChildView â

class CChildView : public CWnd
{
// �����Դϴ�.
public:
	CChildView();

	dialog mDialog;
	SampleDialog sampleDialog;
// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:

// �������Դϴ�.
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// �����Դϴ�.
public:
	virtual ~CChildView();

	// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};


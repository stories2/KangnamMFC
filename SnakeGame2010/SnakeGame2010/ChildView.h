
// ChildView.h : CChildView Ŭ������ �������̽�
//


#pragma once

#ifdef _DEBUG

#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

#include "PlayerObject.h"
#include "LogManager.h"

#endif

#ifdef HEADER_TEST
#endif
// CChildView â

class CChildView : public CWnd
{
	bool resetFlag;
	CBitmap bitmapPlayer, bitmapItem;	
	CRect rect;
	CDC memDC;
	PlayerObject *rootPlayerObject;
	int timer, movingTimer;
// �����Դϴ�.
public:
	CChildView();
	void Init(CPaintDC &dc);
	void RecursiveDraw(CPaintDC &dc);
	void RecursiveMove();

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
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};


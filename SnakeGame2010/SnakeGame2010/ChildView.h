
// ChildView.h : CChildView 클래스의 인터페이스
//


#pragma once

#ifdef _DEBUG

#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

#include "PlayerObject.h"
#include "LogManager.h"
#include <random>

#endif

#ifdef HEADER_TEST
#endif
// CChildView 창

class CChildView : public CWnd
{
	bool resetFlag, isGameOver, hardResetFlag;
	CBitmap bitmapPlayer, bitmapItem;	
	CRect rect;
	CDC memDC;
	PlayerObject *rootPlayerObject;
	GameObject *itemObject;
	int timer, movingTimer;
	Position viewPosition;
// 생성입니다.
public:
	CChildView();
	void Init(CPaintDC &dc);
	void RecursiveDraw(CPaintDC &dc);
	void RecursiveMove();
	void ItemDraw(CPaintDC &dc);
	void BackgroundDraw(CPaintDC &dc);
	void GameRuleManager();
	int GetRandomInt(int nMin, int nMax);

// 특성입니다.
public:

// 작업입니다.
public:

// 재정의입니다.
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 구현입니다.
public:
	virtual ~CChildView();

	// 생성된 메시지 맵 함수
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};



// ChildView.h : CChildView 클래스의 인터페이스
//


#pragma once

#ifdef _DEBUG

#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

#include "PlayerObject.h"
#include "LogManager.h"

#endif

#ifdef HEADER_TEST
#endif
// CChildView 창

class CChildView : public CWnd
{
	bool resetFlag;
	CBitmap bitmapPlayer, bitmapItem;	
	CRect rect;
	CDC memDC;
	PlayerObject *rootPlayerObject;
// 생성입니다.
public:
	CChildView();
	void Init(CPaintDC &dc);
	void RecursiveDraw(CPaintDC &dc);

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
};


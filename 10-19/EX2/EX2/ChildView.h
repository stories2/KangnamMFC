
// ChildView.h: CChildView 클래스의 인터페이스
//


#pragma once
#include "Resource.h"
#include "Shape2D.h"
#include "Line2D.h"

#ifdef _DEBUG
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif
// CChildView 창

class CChildView : public CWnd
{
// 생성입니다.
	
public:
	CChildView();
	Shape2D *shapes[100];
	int shapesNum;
// 특성입니다.
public:
	void ExampleBitmap(CPaintDC &dc);
	void ExampleBitmapDirectly(CPaintDC &dc);
	void ExampleDoubleBuffering(CPaintDC &dc);
	void ExampleSingleBuffering(CPaintDC &dc);
	void ExampleDrawLine(CDC &dc, CPoint point);
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
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};


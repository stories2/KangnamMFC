
// ChildView.cpp: CChildView 클래스의 구현
//

#include "stdafx.h"
#include "EX2.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	//*shapes = new Shape2D[100];
	shapesNum = 0;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

CPoint lastMousePosition;

// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
	ExampleBitmap(dc);
	ExampleBitmapDirectly(dc);
	ExampleSingleBuffering(dc);
	ExampleDoubleBuffering(dc);
}

void CChildView::ExampleBitmap(CPaintDC &dc) {
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP1);
	CBrush brush(&bitmap);
	dc.SelectObject(brush);
	dc.Rectangle(100, 100, 600, 600);
}

void CChildView::ExampleBitmapDirectly(CPaintDC & dc)
{
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP1);
	BITMAP bmpInfo;
	bitmap.GetBitmap(&bmpInfo);

	CDC memDc;
	memDc.CreateCompatibleDC(&dc);
	memDc.SelectObject(&bitmap);

	dc.BitBlt(700, 100, bmpInfo.bmWidth, bmpInfo.bmHeight, &memDc, 0, 0, SRCCOPY);
}

void CChildView::ExampleDoubleBuffering(CPaintDC & dc)
{

}

void CChildView::ExampleSingleBuffering(CPaintDC & dc)
{
	CRect rect;
	
}

void CChildView::ExampleDrawLine(CDC & dc, CPoint point)
{
	Line2D *line = new Line2D;
	line->start = point;

	shapes[shapesNum] = line;
	shapesNum += 1;
}


BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	//return CWnd::OnEraseBkgnd(pDC);
	return true;
}


void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CWnd::OnLButtonDown(nFlags, point);
	lastMousePosition = point;
	CClientDC dc(this);

	ExampleDrawLine(dc, point);
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CWnd::OnLButtonUp(nFlags, point);

	CClientDC dc(this);
	dc.MoveTo(lastMousePosition.x, lastMousePosition.y);
	dc.LineTo(point.x, point.y);
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CWnd::OnMouseMove(nFlags, point);

	if (nFlags & MK_LBUTTON) {
		CClientDC dc(this);/*
		dc.MoveTo(lastMousePosition.x, lastMousePosition.y);
		dc.LineTo(point.x, point.y);

		lastMousePosition = point;*/
		printf("left mouse move\n");

		Line2D *line = (Line2D *)shapes[shapesNum - 1];
		line->end = point;

		line->Draw(dc);
	}
	else {

		printf("just mouse move\n");
	}
}

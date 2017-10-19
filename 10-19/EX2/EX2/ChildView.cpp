
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
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()



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


BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	//return CWnd::OnEraseBkgnd(pDC);
	return true;
}

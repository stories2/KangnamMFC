
// ChildView.cpp: CChildView 클래스의 구현
//

#include "stdafx.h"
#include "EX1.h"
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
	dc.SetTextColor(RGB(255, 0, 0));
	dc.SetBkColor(RGB(0, 255, 0));

	CRect rect;
	GetClientRect(rect);

	CString a("test"), b("welcome");

	dc.DrawText(L"test", &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	dc.SetTextAlign(TA_CENTER);
	dc.TextOut(rect.Width() / 2, rect.Height() / 4, b);

	DrawRectWithPen(dc);
	DrawPolygon(dc);
}

void CChildView::DrawPolygon(CPaintDC &dc) {
	CRgn rgn;
	CPoint ptVertex[5];
	//ALTERNATE : WINDING
}


void CChildView::DrawRectWithPen(CPaintDC &dc) {

	CPen pen(PS_SOLID, 1, RGB(0, 0, 255));
	dc.SelectObject(&pen);
	dc.Rectangle(100, 100, 200, 200);

	CPen *pOldPen = dc.SelectObject(&pen);
	dc.Rectangle(400, 100, 500, 200);
	dc.SelectObject(pOldPen);
}

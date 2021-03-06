
// ChildView.cpp : CChildView 클래스의 구현
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
	ON_WM_LBUTTONDOWN()
	ON_WM_SIZE()
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
	//this->SetWindowPos(NULL, 0, 0, 640, 640, SWP_NOMOVE | SWP_NOZORDER);
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.

	int r, g, b;

	//COLORREF color = dc.GetPixel(x, y);
	//dc.SetPixel(x, y, RGB(r, g, b));
	int i, t;
	for (i = 0; i < 255; i += 1) {
		for (t = 0; t < 255; t += 1) {
			dc.SetPixel(t, i, RGB(t, i, 255));
		}
	}

	CRect rect;
	GetClientRect(rect);

	int centerX = rect.right / 2,
		centerY = rect.bottom / 2;
	
	char buffer[100];//멀티바이트 문자 집합으로 바꾸기
	sprintf(buffer, "Left: %d", rect.left);


	dc.TextOut(centerX, centerY, buffer);

	sprintf(buffer, "Right: %d", rect.right);

	dc.TextOut(centerX, centerY + 20, buffer);


	//
	//dc.MoveTo(x1, y1);
	//dc.LineTo(x1, y1);
	t = 0;
	int gap = 20;
	for (i = 0; i < rect.bottom; i += gap) {
		t += gap;
		dc.MoveTo(t, 0);
		dc.LineTo(rect.right, i);

		dc.MoveTo(0, i);
		dc.LineTo(t, rect.bottom);
	}

	dc.SetTextColor(RGB(255, 0, 0));
	dc.SetBkColor(RGB(255, 255, 0));

	dc.DrawText("Draw Text Test", &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	dc.SetTextAlign(TA_CENTER);
	dc.TextOut(rect.Width() / 2, rect.Height() / 4, "Welcome");

}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CClientDC dc(this);

	int radius = 30;

	dc.Ellipse(point.x - radius, point.y - radius, point.x + radius, point.y + radius);

	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.

	CClientDC dc(this);

	CRect rect;
	GetClientRect(rect);

	dc.Ellipse(rect.left, rect.top, rect.right, rect.bottom);

	printf("on size event accepted\n");

	Invalidate();
}

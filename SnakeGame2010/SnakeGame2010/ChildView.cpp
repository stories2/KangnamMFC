
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "SnakeGame2010.h"
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
	delete rootPlayerObject;
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
	Init(dc);
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.

	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.	
	/*
	Position defaultPosition;
	defaultPosition.SetPosition(10, 10);
	CString filePath("res/player.png");
	PlayerObject playerObject(defaultPosition, filePath, DIRECTION_UP);*/

	//memDC.SelectObject(&bitmapPlayer);
	//image.Draw(dc.GetSafeHdc(), 0, 0, 32, 32, 0, 0, 32, 32);
	//dc.BitBlt(0, 0, 32, 32, &memDC, 0, 0, SRCCOPY);

	memDC.SelectObject(&bitmapItem);

	dc.BitBlt(32, 32, 32, 32, &memDC, 0, 0, SRCCOPY);

	RecursiveDraw(dc);
}

void CChildView::RecursiveDraw(CPaintDC &dc) {
	memDC.SelectObject(&bitmapPlayer);
	GameObject *indexOfGameObject = rootPlayerObject;
	while(indexOfGameObject != NULL) {
		int x = indexOfGameObject->GetX(), y = indexOfGameObject->GetY();
		dc.BitBlt(x * 32, y * 32, 32, 32, &memDC, 0, 0, SRCCOPY);
		indexOfGameObject = indexOfGameObject->GetNextGameObject();
	}
}

void CChildView::Init(CPaintDC &dc) {
	if(resetFlag) {
		resetFlag = !resetFlag;

		CImage imagePlayer, imageItem;
		imagePlayer.Load(CString("res/player.png"));
		imageItem.Load(CString("res/item.png"));

		bitmapPlayer.Attach(imagePlayer.Detach());
		bitmapItem.Attach(imageItem.Detach());

		memDC.CreateCompatibleDC(&dc); 
		GetClientRect(&rect);

		Position defaultPosition;
		defaultPosition.SetPosition(0, 0);
		CString filePath("res/player.png");
		rootPlayerObject = new PlayerObject(defaultPosition, filePath, DIRECTION_UP);
	}
}
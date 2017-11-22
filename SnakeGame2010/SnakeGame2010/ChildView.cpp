
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
	ON_WM_TIMER()
	ON_WM_KEYDOWN()
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

	if(movingTimer % PLAYER_MOVE_TIME == 0) {
		RecursiveMove();
	}

	movingTimer += 1;
	timer += 1;
}

void CChildView::RecursiveDraw(CPaintDC &dc) {
	memDC.SelectObject(&bitmapPlayer);
	GameObject *indexOfGameObject = rootPlayerObject;
	GameObject *previousGameObject = NULL;
	Position *backupPosition = NULL;
	int cnt = 0;
	while(indexOfGameObject != NULL) {
		int x = indexOfGameObject->GetX(), y = indexOfGameObject->GetY(), 
			direction = indexOfGameObject->GetDirection(), animeFrame = indexOfGameObject->GetAnimeFrame();
		//printf("#%d x: %d y: %d dir: %d\n", cnt, x, y, direction);
		cnt += 1;
		if(timer % IMAGE_UPDATE_TIME == 0) {
			indexOfGameObject->SetAnimeFrame((animeFrame + 1) % 4);
		}
		if(previousGameObject != NULL && movingTimer % PLAYER_MOVE_TIME == 0) {
			if(backupPosition != NULL) {
				indexOfGameObject->SetPosition(*backupPosition);
				delete backupPosition;
				backupPosition = NULL;
			}
			else {
				backupPosition = new Position();
				backupPosition->SetPosition(indexOfGameObject->GetPosition());
				indexOfGameObject->SetPosition(previousGameObject->GetPosition());
			}
			indexOfGameObject->SetDirection(previousGameObject->GetDirection());
		}
		previousGameObject = indexOfGameObject;
		indexOfGameObject = indexOfGameObject->GetNextGameObject();
		dc.BitBlt(x * 32, y * 32, 32, 32, &memDC, animeFrame * 32, direction * 32, SRCCOPY);
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
		defaultPosition.SetPosition(5, 5);
		CString filePath("res/player.png");
		rootPlayerObject = new PlayerObject(defaultPosition, filePath, DIRECTION_UP);

		SetTimer(0, 1000 / 60, NULL);

		timer = 0;

		defaultPosition.SetPosition(5, 6);
		PlayerObject *testPlayerObject = new PlayerObject(defaultPosition, filePath, DIRECTION_UP);
		rootPlayerObject->SetNextGameObject(testPlayerObject);

		defaultPosition.SetPosition(5, 7);
		PlayerObject *testPlayerObject2 = new PlayerObject(defaultPosition, filePath, DIRECTION_UP);
		testPlayerObject->SetNextGameObject(testPlayerObject2);
	}
}

void CChildView::RecursiveMove() {
	int direction = rootPlayerObject->GetDirection();
	int x = rootPlayerObject->GetX(), y = rootPlayerObject->GetY();
	switch(direction) {
	case DIRECTION_LEFT:
		x = x - 1;
		break;
	case DIRECTION_UP:
		y = y - 1;
		break;
	case DIRECTION_RIGHT:
		x = x + 1;
		break;
	case DIRECTION_DOWN:
		y = y + 1;
		break;
	}
	Position position;
	position.SetPosition(x, y);
	rootPlayerObject->SetPosition(position);
}

void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	//CWnd::OnTimer(nIDEvent);
	if(nIDEvent == 0) {
		Invalidate();
	}
}


void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	//CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
	switch(nChar) {
	case VK_LEFT:
		rootPlayerObject->SetDirection(DIRECTION_LEFT);
		movingTimer = 0;
		break;
	case VK_UP:
		rootPlayerObject->SetDirection(DIRECTION_UP);
		movingTimer = 0;
		break;
	case VK_RIGHT:
		rootPlayerObject->SetDirection(DIRECTION_RIGHT);
		movingTimer = 0;
		break;
	case VK_DOWN:
		rootPlayerObject->SetDirection(DIRECTION_DOWN);
		movingTimer = 0;
		break;
	}
}

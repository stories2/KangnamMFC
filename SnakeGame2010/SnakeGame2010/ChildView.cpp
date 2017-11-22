
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
	//delete rootPlayerObject;
	/*GameObject *indexOfObject = rootPlayerObject->GetLastGameObject();
	while(indexOfObject != rootPlayerObject) {
	GameObject *temp = indexOfObject;
	indexOfObject = indexOfObject->GetBeforeGameObject();
	delete temp;
	}*/
	delete rootPlayerObject;
	delete itemObject;
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_WM_KEYDOWN()
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
	Init(dc);

	BackgroundDraw(dc);
	ItemDraw(dc);
	RecursiveDraw(dc);

	GameRuleManager();
	if(movingTimer % PLAYER_MOVE_TIME == 0) {
		RecursiveMove();
	}

	if(isGameOver != true) {
		movingTimer += 1;
		timer += 1;
	}
}

int CChildView::GetRandomInt(int nMin, int nMax)
{
	return nMin + (int)((double)rand() / (RAND_MAX+1) * (nMax-nMin+1));
}

void CChildView::GameRuleManager() {
	Position rootPosition = rootPlayerObject->GetPosition(),
		itemPosition = itemObject->GetPosition();
	if(rootPosition.GetX() == itemPosition.GetX() &&
		rootPosition.GetY() == itemPosition.GetY()) {
			if(timer % PLAYER_MOVE_TIME == 0) {
				Position newItemPosition;
				newItemPosition.SetPosition(GetRandomInt(0, PLAYGROUND_SCALE - 1), GetRandomInt(0, PLAYGROUND_SCALE - 1));
				itemObject->SetPosition(newItemPosition);

				PlayerObject *newPlayerObject;
				PlayerObject *lastPlayerObject = (PlayerObject *)rootPlayerObject->GetLastGameObject();
				if(lastPlayerObject == NULL) {
					lastPlayerObject = rootPlayerObject;
					Position position;
					switch(lastPlayerObject->GetDirection()) {
					case DIRECTION_LEFT:
						position.SetPosition(lastPlayerObject->GetX() + 1, lastPlayerObject->GetY());
						break;
					case DIRECTION_UP:
						position.SetPosition(lastPlayerObject->GetX(), lastPlayerObject->GetY() + 1);
						break;
					case DIRECTION_RIGHT:
						position.SetPosition(lastPlayerObject->GetX() - 1, lastPlayerObject->GetY());
						break;
					case DIRECTION_DOWN:
						position.SetPosition(lastPlayerObject->GetX(), lastPlayerObject->GetY() - 1);
						break;
					}
					newPlayerObject = new PlayerObject(position, CString("res/player.png"), lastPlayerObject->GetDirection());
				}
				else {
					newPlayerObject = new PlayerObject(lastPlayerObject->GetPosition(), CString("res/player.png"), lastPlayerObject->GetDirection());
				}
				lastPlayerObject->SetNextGameObject(newPlayerObject);
				newPlayerObject->SetBeforeGameObject(lastPlayerObject);
			}
	}

	if(rootPosition.GetX() < 0 || rootPosition.GetX() >= PLAYGROUND_SCALE || rootPosition.GetY() < 0 || rootPosition.GetY() >= PLAYGROUND_SCALE) {
		isGameOver = true;
	}

	GameObject *indexOfPlayerObject = rootPlayerObject->GetLastGameObject();
	if(indexOfPlayerObject != NULL) {
		while(indexOfPlayerObject != rootPlayerObject->GetNextGameObject()) {
			if(rootPlayerObject->GetX() == indexOfPlayerObject->GetX() && 
				rootPlayerObject->GetY() == indexOfPlayerObject->GetY()) {
					isGameOver = true;
			}
			indexOfPlayerObject = indexOfPlayerObject->GetBeforeGameObject();
		}
	}
}

void CChildView::BackgroundDraw(CPaintDC &dc) {
	dc.Rectangle(viewPosition.GetX(), viewPosition.GetY(), viewPosition.GetX() + PLAYGROUND_SCALE * 32, viewPosition.GetY() + PLAYGROUND_SCALE * 32);
}

void CChildView::ItemDraw(CPaintDC &dc) {
	memDC.SelectObject(&bitmapItem);

	if(timer % IMAGE_UPDATE_TIME == 0) {
		itemObject->SetAnimeFrame((itemObject->GetAnimeFrame() + 1) % 4);
	}

	dc.BitBlt(viewPosition.GetX() + itemObject->GetX() * 32, viewPosition.GetY() + itemObject->GetY() * 32, 32, 32, &memDC, itemObject->GetAnimeFrame() * 32, 0, SRCCOPY);
}

void CChildView::RecursiveDraw(CPaintDC &dc) {
	memDC.SelectObject(&bitmapPlayer);
	GameObject *indexOfGameObject = rootPlayerObject->GetLastGameObject();
	GameObject *previousGameObject = NULL;
	Position *backupPosition = NULL;
	int cnt = 0, backupDirection = DIRECTION_NOT_AVAILABLE;
	if(indexOfGameObject == NULL) {
		indexOfGameObject = rootPlayerObject;
	}
	while(true) {
		int x = indexOfGameObject->GetX(), y = indexOfGameObject->GetY(), 
			direction = indexOfGameObject->GetDirection(), animeFrame = indexOfGameObject->GetAnimeFrame();
		//printf("#%d x: %d y: %d dir: %d\n", cnt, x, y, direction);
		cnt += 1;
		if(timer % IMAGE_UPDATE_TIME == 0) {
			indexOfGameObject->SetAnimeFrame((animeFrame + 1) % 4);
		}
		if(movingTimer % PLAYER_MOVE_TIME == 0 && indexOfGameObject != rootPlayerObject) {
			indexOfGameObject->SetPosition(indexOfGameObject->GetBeforeGameObject()->GetPosition());
			indexOfGameObject->SetDirection(indexOfGameObject->GetBeforeGameObject()->GetDirection());
		}
		else if(movingTimer % PLAYER_MOVE_TIME == 0 && indexOfGameObject != rootPlayerObject) {

		}
		previousGameObject = indexOfGameObject;
		indexOfGameObject = indexOfGameObject->GetBeforeGameObject();
		dc.BitBlt(viewPosition.GetX() + x * 32, viewPosition.GetY() + y * 32, 32, 32, &memDC, animeFrame * 32, direction * 32, SRCCOPY);

		if(indexOfGameObject == NULL) {
			break;
		}
	}
}

void CChildView::Init(CPaintDC &dc) {
	if(hardResetFlag) {
		hardResetFlag = !hardResetFlag;

		CImage imagePlayer, imageItem;
		imagePlayer.Load(CString("res/player.png"));
		imageItem.Load(CString("res/item.png"));

		bitmapPlayer.Attach(imagePlayer.Detach());
		bitmapItem.Attach(imageItem.Detach());

		memDC.CreateCompatibleDC(&dc); 
		GetClientRect(&rect);

		viewPosition.SetPosition((rect.Width() - PLAYGROUND_SCALE * 32) / 2, (rect.Height() - PLAYGROUND_SCALE * 32) / 2);
	}
	if(resetFlag) {
		resetFlag = !resetFlag;
		isGameOver = false;

		Position defaultPosition;
		defaultPosition.SetPosition(5, 5);
		CString filePath("res/player.png");
		rootPlayerObject = new PlayerObject(defaultPosition, filePath, DIRECTION_UP);

		itemObject = new GameObject();
		defaultPosition.SetPosition(4, 4);
		itemObject->SetPosition(defaultPosition);

		SetTimer(0, 1000 / 60, NULL);

		timer = 0;
		/*
		defaultPosition.SetPosition(5, 6);
		PlayerObject *secondPlayerObject = new PlayerObject(defaultPosition, filePath, DIRECTION_UP);

		rootPlayerObject->SetNextGameObject(secondPlayerObject);
		secondPlayerObject->SetBeforeGameObject(rootPlayerObject);*/
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
		movingTimer = - 1;
		break;
	case VK_UP:
		rootPlayerObject->SetDirection(DIRECTION_UP);
		movingTimer = - 1;
		break;
	case VK_RIGHT:
		rootPlayerObject->SetDirection(DIRECTION_RIGHT);
		movingTimer = - 1;
		break;
	case VK_DOWN:
		rootPlayerObject->SetDirection(DIRECTION_DOWN);
		movingTimer = - 1;
		break;
	case VK_SPACE:
		if(isGameOver) {
			resetFlag = true;
			delete rootPlayerObject;
			delete itemObject;
			Invalidate();
		}
		break;
	}
}


BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	//CWnd::OnEraseBkgnd(pDC);
	return false;
}

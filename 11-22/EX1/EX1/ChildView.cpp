
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
	ON_WM_CREATE()
	ON_BN_CLICKED(101, OnButtonClicked)
	ON_BN_CLICKED(102, OnButtonClicked)
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
}



int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	testButton.Create(L"Press me", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, CRect(100, 100, 200, 130), this, 101);

	checkButton.Create(L"체크 박스", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
                                CRect(20, 60, 160, 90), this, 102);
	checkButton.SetCheck(false);
	return 0;
}

void CChildView::OnButtonClicked() {
	bool checkStatus = checkButton.GetCheck() == BST_CHECKED ? true : false;
	if(checkStatus) {
		MessageBox(L"You pressed button");
	}
}
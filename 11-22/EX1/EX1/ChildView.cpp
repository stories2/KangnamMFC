
// ChildView.cpp : CChildView Ŭ������ ����
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



// CChildView �޽��� ó����

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
	CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.
	
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	
	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.
}



int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	testButton.Create(L"Press me", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, CRect(100, 100, 200, 130), this, 101);

	checkButton.Create(L"üũ �ڽ�", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
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
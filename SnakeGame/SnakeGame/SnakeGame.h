
// SnakeGame.h : SnakeGame ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CSnakeGameApp:
// �� Ŭ������ ������ ���ؼ��� SnakeGame.cpp�� �����Ͻʽÿ�.
//

class CSnakeGameApp : public CWinApp
{
public:
	CSnakeGameApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSnakeGameApp theApp;

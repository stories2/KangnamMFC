
// SnakeGame2010.h : SnakeGame2010 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CSnakeGame2010App:
// �� Ŭ������ ������ ���ؼ��� SnakeGame2010.cpp�� �����Ͻʽÿ�.
//

class CSnakeGame2010App : public CWinAppEx
{
public:
	CSnakeGame2010App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSnakeGame2010App theApp;

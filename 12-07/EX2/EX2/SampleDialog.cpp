// SampleDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "EX2.h"
#include "SampleDialog.h"
#include "afxdialogex.h"


// SampleDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC(SampleDialog, CDialogEx)

SampleDialog::SampleDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(SampleDialog::IDD, pParent)
{

}

SampleDialog::~SampleDialog()
{
}

void SampleDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, etxtView);
	DDX_Control(pDX, IDC_RADIO1, radioColor);
}


BEGIN_MESSAGE_MAP(SampleDialog, CDialogEx)
END_MESSAGE_MAP()


// SampleDialog 메시지 처리기입니다.

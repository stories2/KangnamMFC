// SampleDialog.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "EX2.h"
#include "SampleDialog.h"
#include "afxdialogex.h"


// SampleDialog ��ȭ �����Դϴ�.

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


// SampleDialog �޽��� ó�����Դϴ�.

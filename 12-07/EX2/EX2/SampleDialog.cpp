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
}


BEGIN_MESSAGE_MAP(SampleDialog, CDialogEx)
END_MESSAGE_MAP()


// SampleDialog �޽��� ó�����Դϴ�.

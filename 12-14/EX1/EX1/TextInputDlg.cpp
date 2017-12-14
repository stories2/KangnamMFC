// TextInputDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "EX1.h"
#include "TextInputDlg.h"
#include "afxdialogex.h"


// TextInputDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(TextInputDlg, CDialogEx)

TextInputDlg::TextInputDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(TextInputDlg::IDD, pParent)
{

}

TextInputDlg::TextInputDlg(CWnd* pParent /*=NULL*/, CChildView *childView)
	: CDialogEx(TextInputDlg::IDD, pParent)
{
	this->childView = childView;
}

TextInputDlg::~TextInputDlg()
{
}

void TextInputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, etxtView);
	DDX_Control(pDX, IDC_RADIO1, radioButtons[0]);
	DDX_Control(pDX, IDC_RADIO2, radioButtons[1]);
	DDX_Control(pDX, IDC_RADIO3, radioButtons[2]);
}


BEGIN_MESSAGE_MAP(TextInputDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &TextInputDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// TextInputDlg �޽��� ó�����Դϴ�.


void TextInputDlg::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int i;
	for(i = 0; i < 3; i += 1) {
		if(radioButtons[i].GetCheck() == true) {
			selectedColor = i;
		}
	}

	UpdateData(TRUE);
	childView->Invaildate();

	CDialogEx::OnOK();
}

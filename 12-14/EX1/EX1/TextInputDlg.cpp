// TextInputDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "EX1.h"
#include "TextInputDlg.h"
#include "afxdialogex.h"


// TextInputDlg 대화 상자입니다.

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


// TextInputDlg 메시지 처리기입니다.


void TextInputDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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

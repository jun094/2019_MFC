// TextInputDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Week15_Day2.h"
#include "TextInputDlg.h"
#include "afxdialogex.h"


// CTextInputDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CTextInputDlg, CDialogEx)

CTextInputDlg::CTextInputDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTextInputDlg::IDD, pParent)
	, m_editStr(_T(""))
	, m_red(0)
	, m_green(0)
	, m_blue(0)
{

}

CTextInputDlg::~CTextInputDlg()
{
}

void CTextInputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_editStr);
	DDX_Text(pDX, IDC_EDIT_RED, m_red);
	DDV_MinMaxInt(pDX, m_red, 0, 255);
	DDX_Text(pDX, IDC_EDIT_GREEN, m_green);
	DDV_MinMaxInt(pDX, m_green, 0, 255);
	DDX_Text(pDX, IDC_EDIT_BLUE, m_blue);
	DDV_MinMaxInt(pDX, m_blue, 0, 255);


}


BEGIN_MESSAGE_MAP(CTextInputDlg, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO3, &CTextInputDlg::OnBnClickedRadio3)
END_MESSAGE_MAP()


// CTextInputDlg 메시지 처리기입니다.


void CTextInputDlg::OnBnClickedRadio3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


BOOL CTextInputDlg::OnInitDialog()
{
	BOOL result = CDialogEx::OnInitDialog();

	if(m_red== 255)
		m_radio1.SetCheck(true);
	if(m_green == 255)
		m_radio2.SetCheck(true);
	if(m_blue == 255)
		m_radio3.SetCheck(true);
}

void CTextInputDlg::OnOK()
{
	UpdateData(true);

	if(m_radio1.GetCheck()==true)
	{
		m_red = 255;
		m_green = 0;
		m_blue = 0;
	}
	if(m_radio2.GetCheck()==true)
	{
		m_red = 0;
		m_green = 255;
		m_blue = 0;
	}
	if(m_radio3.GetCheck()==true)
	{
		m_red = 0;
		m_green = 0;
		m_blue = 255;
	}
	EndDialog(IDOK);
}
// TextInput.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "final_ex02.h"
#include "TextInput.h"
#include "afxdialogex.h"


// CTextInput 대화 상자입니다.

IMPLEMENT_DYNAMIC(CTextInput, CDialogEx)

CTextInput::CTextInput(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTextInput::IDD, pParent)
	, m_edit(_T("hi"))
	, m_r(0)
	, m_g(0)
	, m_b(0)
{

}

CTextInput::~CTextInput()
{
}

void CTextInput::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, ID_EDIT, m_edit);
	DDX_Text(pDX, ID_R, m_r);
	DDV_MinMaxInt(pDX, m_r, 0, 255);
	DDX_Text(pDX, ID_G, m_g);
	DDV_MinMaxInt(pDX, m_g, 0, 255);
	DDX_Text(pDX, ID_B, m_b);
	DDV_MinMaxInt(pDX, m_b, 0, 255);
}


BEGIN_MESSAGE_MAP(CTextInput, CDialogEx)
END_MESSAGE_MAP()


// CTextInput 메시지 처리기입니다.

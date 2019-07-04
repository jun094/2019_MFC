#pragma once


// CTextInput 대화 상자입니다.

class CTextInput : public CDialogEx
{
	DECLARE_DYNAMIC(CTextInput)

public:
	CTextInput(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CTextInput();

// 대화 상자 데이터입니다.
	enum { IDD = ID_TEXTINPUT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString m_edit;
	int m_r;
	int m_g;
	int m_b;
};

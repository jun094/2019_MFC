#pragma once


// CTextInput ��ȭ �����Դϴ�.

class CTextInput : public CDialogEx
{
	DECLARE_DYNAMIC(CTextInput)

public:
	CTextInput(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CTextInput();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = ID_TEXTINPUT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CString m_edit;
	int m_r;
	int m_g;
	int m_b;
};

#pragma once


// CTextInputDlg 대화 상자입니다.

class CTextInputDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTextInputDlg)

public:
	CTextInputDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CTextInputDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

	BOOL OnInitDialog(); // 모달 띄울때 가장먼저 불리는 함수 --> ppt27(s35)
	void OnOK();
public:
	CString m_editStr; //value값 저장한 string
	int m_red;
	int m_green;
	int m_blue;
	CButton m_radio1;
	CButton m_radio2;
	CButton m_radio3;

	afx_msg void OnBnClickedRadio3();
};

#pragma once


// CTextInputDlg ��ȭ �����Դϴ�.

class CTextInputDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTextInputDlg)

public:
	CTextInputDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CTextInputDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

	BOOL OnInitDialog(); // ��� ��ﶧ ������� �Ҹ��� �Լ� --> ppt27(s35)
	void OnOK();
public:
	CString m_editStr; //value�� ������ string
	int m_red;
	int m_green;
	int m_blue;
	CButton m_radio1;
	CButton m_radio2;
	CButton m_radio3;

	afx_msg void OnBnClickedRadio3();
};

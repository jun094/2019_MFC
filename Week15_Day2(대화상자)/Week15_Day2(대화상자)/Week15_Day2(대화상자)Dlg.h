
// Week15_Day2(��ȭ����)Dlg.h : ��� ����
//

#pragma once
#include "afxwin.h"


// CWeek15_Day2��ȭ����Dlg ��ȭ ����
class CWeek15_Day2��ȭ����Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CWeek15_Day2��ȭ����Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_WEEK15_DAY2_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCheck1();
	CButton m_check1;
	afx_msg void OnEnChangeEdit1();
	CEdit m_edit;
	afx_msg void OnEnSetfocusEdit1();
};


// Week15_Day1(2)Dlg.h : ��� ����
//

#pragma once
#include "afxwin.h"


// CWeek15_Day12Dlg ��ȭ ����
class CWeek15_Day12Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CWeek15_Day12Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_WEEK15_DAY12_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCancel();
	CButton m_check2;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedPush();
	CEdit m_edit;
};

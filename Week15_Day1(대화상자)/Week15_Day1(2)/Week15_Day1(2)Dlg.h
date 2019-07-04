
// Week15_Day1(2)Dlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"


// CWeek15_Day12Dlg 대화 상자
class CWeek15_Day12Dlg : public CDialogEx
{
// 생성입니다.
public:
	CWeek15_Day12Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_WEEK15_DAY12_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
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

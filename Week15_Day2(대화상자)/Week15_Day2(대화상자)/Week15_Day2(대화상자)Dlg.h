
// Week15_Day2(대화상자)Dlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"


// CWeek15_Day2대화상자Dlg 대화 상자
class CWeek15_Day2대화상자Dlg : public CDialogEx
{
// 생성입니다.
public:
	CWeek15_Day2대화상자Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_WEEK15_DAY2_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
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

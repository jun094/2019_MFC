
// ChildView.h : CChildView 클래스의 인터페이스
//


#pragma once
#include "MyCircle.h"

// CChildView 창

class CChildView : public CWnd
{
// 생성입니다.
public:
	CChildView();
	CList<CMyCircle *> m_circle;
// 특성입니다.
public:
	int m_num;
	bool m_Lbutton;
	int m_mode;
	POSITION m_pos;
	bool flag;
	int m_x;
	int m_y;
	
// 작업입니다.
public:

// 재정의입니다.
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 구현입니다.
public:
	virtual ~CChildView();

	// 생성된 메시지 맵 함수
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnActionMinus();
	afx_msg void OnActionPlus();
	afx_msg void OnDrawCircle();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};


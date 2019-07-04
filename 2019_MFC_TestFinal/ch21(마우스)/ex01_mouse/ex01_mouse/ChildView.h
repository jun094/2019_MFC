
// ChildView.h : CChildView 클래스의 인터페이스
//


#pragma once
#include "MyShape.h"

// CChildView 창

class CChildView : public CWnd
{
// 생성입니다.
public:
	CChildView();

// 특성입니다.
public:
	int m_num;
	int m_mode; // 왼쪽 클릭할때마다 도형 모드 변경 
	CMyShape *m_pShape[100];
	bool m_bLbutton;


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
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnShapesRect();
	afx_msg void OnShapesCircle();
	afx_msg void OnShapesCurve();
	afx_msg void OnViewToolbar();
};


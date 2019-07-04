
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
	CList<CMyShape *> m_shapes; //링크드리스트 사용
	//CMyShape *m_pShape[100]; //동적배열 사용x
	
	int m_num;
	int m_mode; // 왼쪽 클릭할때마다 도형 모드 변경 
	bool m_bLbutton;

	POSITION m_pos; // select했을때 선택한 도형 찾는 iterator
	//CPoint m_prePoint; //드래그 시작 좌표

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
	afx_msg void OnActionSelect();
};


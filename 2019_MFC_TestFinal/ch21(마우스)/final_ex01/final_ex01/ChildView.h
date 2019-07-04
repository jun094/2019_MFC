
// ChildView.h : CChildView Ŭ������ �������̽�
//


#pragma once
#include "MyCircle.h"

// CChildView â

class CChildView : public CWnd
{
// �����Դϴ�.
public:
	CChildView();
	CList<CMyCircle *> m_circle;
// Ư���Դϴ�.
public:
	int m_num;
	bool m_Lbutton;
	int m_mode;
	POSITION m_pos;
	bool flag;
	int m_x;
	int m_y;
	
// �۾��Դϴ�.
public:

// �������Դϴ�.
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// �����Դϴ�.
public:
	virtual ~CChildView();

	// ������ �޽��� �� �Լ�
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


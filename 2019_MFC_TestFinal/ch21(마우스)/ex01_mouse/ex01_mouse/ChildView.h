
// ChildView.h : CChildView Ŭ������ �������̽�
//


#pragma once
#include "MyShape.h"

// CChildView â

class CChildView : public CWnd
{
// �����Դϴ�.
public:
	CChildView();

// Ư���Դϴ�.
public:
	int m_num;
	int m_mode; // ���� Ŭ���Ҷ����� ���� ��� ���� 
	CMyShape *m_pShape[100];
	bool m_bLbutton;


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
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnShapesRect();
	afx_msg void OnShapesCircle();
	afx_msg void OnShapesCurve();
	afx_msg void OnViewToolbar();
};


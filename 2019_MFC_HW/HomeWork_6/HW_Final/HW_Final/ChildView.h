
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
	CList<CMyShape *> m_shapes; //��ũ�帮��Ʈ ���
	//CMyShape *m_pShape[100]; //�����迭 ���x
	
	int m_num;
	int m_mode; // ���� Ŭ���Ҷ����� ���� ��� ���� 
	bool m_bLbutton;

	POSITION m_pos; // select������ ������ ���� ã�� iterator
	//CPoint m_prePoint; //�巡�� ���� ��ǥ

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
	afx_msg void OnActionSelect();
};


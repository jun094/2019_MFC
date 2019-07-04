
// ChildView.h : interface of the CChildView class
//


#pragma once


// CChildView window
#include "MyShape.h"

class CChildView : public CWnd
{
// Construction
public:
	CChildView();

// Attributes
public:
	
	bool m_bLButton;
	//int m_num; // 리스트로 구현했으니 숫자 필요 없음
	int m_mode;
	//CMyShape * m_pShapes[100]; // 리스트로 구현할꺼임!
	CList<CMyShape *> m_pShapes;

// Operations
public:

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};


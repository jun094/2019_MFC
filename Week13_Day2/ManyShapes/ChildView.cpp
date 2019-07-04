
// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "ManyShapes.h"
#include "ChildView.h"

#include "MyRect.h"
#include "MyCircle.h"
#include "MyCurve.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
	: m_bLButton(false), m_mode(CMyShape::RECT)
{
	//m_pt1 = CPoint(100,100);
	//m_bLButton = false;

}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	CRect rect;
	GetClientRect(rect);
	int w = rect.Width();
	int h = rect.Height();

	CDC memDC;
	memDC.CreateCompatibleDC(&dc);
	CBitmap bmp;
	bmp.CreateCompatibleBitmap(&dc, w, h);
	memDC.SelectObject(bmp);
	memDC.Rectangle(0,0,w,h);
	
	////////////////////////////////////////
	POSITION pos = m_pShapes.GetHeadPosition();
	while(pos != NULL)
		(m_pShapes.GetNext(pos))->draw(memDC); // 

	////////////////////////////////////////
	
	dc.BitBlt(0,0,w,h,&memDC, 0,0, SRCCOPY);
}

BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	//return CWnd::OnEraseBkgnd(pDC);
	return true;
}


void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	switch(m_mode)
	{
	case CMyShape::RECT:
		m_pShapes.AddTail(new CMyRect());
		break;
	case CMyShape::CIRCLE:
		m_pShapes.AddTail(new CMyCircle());
		break;
	case CMyShape::CURVE:
		m_pShapes.AddTail(new CMyCurve());
		break;
	default:
		return;
	}

	m_pShapes.GetTail()->setMouseDown(point);

	m_bLButton = true;
	SetCapture();
	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	m_pShapes.GetTail()->setMouseUp(point);
	
	//TRACE("");
	m_bLButton = false;
	Invalidate();
	ReleaseCapture();


	CWnd::OnLButtonUp(nFlags, point);
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	if(m_bLButton == true)
	{
		m_pShapes.GetTail()->setMouseMove(point);
		Invalidate();
	}

	CWnd::OnMouseMove(nFlags, point);
}


void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	m_mode ++;
	m_mode = m_mode % CMyShape::NUM_SHAPES;

	CWnd::OnRButtonDown(nFlags, point);
}

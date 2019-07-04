
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "ex02.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
	:m_LButton(false), m_prePos(0,0), selectCheck(false)
{
	m_rect.SetRect(100,100,500,500);
	dotRect.SetRect(m_rect.left-10, m_rect.top-10, m_rect.right+10, m_rect.bottom+10);
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()



// CChildView 메시지 처리기
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
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	
	CPen dotPen(PS_DOT, 1, RGB(255,0,0));
	CBrush brush(RGB(0,255,0));
	CPen pen(PS_SOLID, 3,RGB(0,255,0));


	if(selectCheck == true)
	{	
		dc.SelectObject(dotPen);
		dc.Rectangle(dotRect);
	}	
	dc.SelectObject(brush);
	dc.SelectObject(pen);
	dc.Rectangle(m_rect);
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	
	if(m_rect.PtInRect(point))
	{
		m_LButton = true;
		m_prePos = point;
		selectCheck = true;
		
		Invalidate();
				
		SetCapture();
	}
	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	if(m_LButton == true)
	{
		m_LButton = false;
		ReleaseCapture();
	}

	CWnd::OnLButtonUp(nFlags, point);
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	if(m_LButton == true)
	{
		CPoint movePos;

		movePos.x = point.x - m_prePos.x;
		movePos.y = point.y - m_prePos.y;

		m_rect.left += movePos.x;
		m_rect.top +=  movePos.y;
		m_rect.right += movePos.x;
		m_rect.bottom +=  movePos.y;

		dotRect.left += movePos.x;
		dotRect.top += movePos.y;
		dotRect.right += movePos.x;
		dotRect.bottom += movePos.y;

		m_prePos = point;
		
		Invalidate();
	}

	CWnd::OnMouseMove(nFlags, point);
}

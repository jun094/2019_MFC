
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "final_ex03.h"
#include "ChildView.h"
#include "MyCurve.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
	:m_Lbuuton(false)
{
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
END_MESSAGE_MAP()



// CChildView �޽��� ó����

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
	CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.
	
	CRect rect;
	GetClientRect(rect);

	int w = rect.Width();
	int h = rect.Height();

	CDC memDC;
	memDC.CreateCompatibleDC(&dc);

	CBitmap bmp;
	bmp.CreateCompatibleBitmap(&dc,w,h);

	memDC.SelectObject(bmp);
	memDC.Rectangle(0,0,w,h);

	//////////
	POSITION pos = m_shapes.GetHeadPosition();
	while(pos!=NULL)
	{
		m_shapes.GetNext(pos)->draw(dc);
	}
	//////////

	memDC.BitBlt(0,0,w,h,&memDC,0,0,SRCCOPY);



	CRect rect;
	GetClientRect(rect);

	int w = rect.Width();
	int h = rect.Height();

	CDC memDC;
	memDC.CreateCompatibleDC(&dc);

	CBitmap bmp;
	bmp.CreateCompatibleBitmap(&dc,w,h);

	memDC.SelectObject(bmp);
	memDC.Rectangle(0,0,w,h);
	//
	//
	memDC.BitBlt(0,0,w,h,&memDC,0,0,SRCCOPY);
}
BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	return true;
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	m_Lbuuton = true;

	m_shapes.AddTail(new CMyCurve());

	m_shapes.GetTail()->setMouseDown(point);

	SetCapture();
	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	if(m_Lbuuton==true)
	{
		m_shapes.GetTail()->setMouseUp(point);
		ReleaseCapture();
		m_Lbuuton = false;
		Invalidate();
	}
	
	
	CWnd::OnLButtonUp(nFlags, point);
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	if(m_Lbuuton==true)
	{
		m_shapes.GetTail()->setMouseMove(point);
		Invalidate();

	}
			CWnd::OnMouseMove(nFlags, point);
}

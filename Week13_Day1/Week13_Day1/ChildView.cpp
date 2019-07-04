
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "Week13_Day1.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "MyRect.h"
#include "MyCircle.h"
// CChildView

CChildView::CChildView()
	//:m_pt1(100,100), m_pt2(200,200), m_bLButton(false)
	: m_bLButton(false), m_num(0), m_mode(CMyShape::RECT)
{
	//m_bLButton = false;
	
}

CChildView::~CChildView()
{
	for(int i=0; i<m_num ; i++)
	{
		delete m_pShapes[i];
	}
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
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

// 그림그리는 곳
void CChildView::OnPaint() 
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

	CRect rect;
	GetClientRect(rect);
	int w = rect.Width();
	int h = rect.Height();

	CDC memDC; // 새로운 도화지
	memDC.CreateCompatibleDC(&dc); // 현재까지 양식만 존재
	CBitmap bmp;
	bmp.CreateCompatibleBitmap(&dc,w,h);
	memDC.SelectObject(bmp); 
	// 여기까지 그림그리기 준비 완료 (검정색 바탕)

	memDC.Rectangle(0,0,w,h); // 하얀색 사각형으로 창을 덮음 -> 하얀색배경

	/////////////////////////////////////////////////////////////
	// 여기가 우리가 그림 코딩할 곳
	for(int i=0;i<m_num;i++)
	{
		m_pShapes[i]->draw(memDC);
	}
	/////////////////////////////////////////////////////////////

	dc.BitBlt(0,0,w,h,&memDC,0,0,SRCCOPY);

}
// 화면을 지운다. -> 이것도 기본 포맷
BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	//return CWnd::OnEraseBkgnd(pDC);
	return true;
}


// 마우스 찍어서 시작점 기억
void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	switch(m_mode)
	{
	case CMyShape::RECT:
		m_pShapes[m_num] = new CMyRect();
		break;
	case CMyShape::CIRCLE:
		m_pShapes[m_num] = new CMyCircle();
		break;
	default:
		break;
	}
	
	m_pShapes[m_num]->setMouseDown(point);

	m_bLButton = true;
	SetCapture(); // <-> ReleaseCapture; // 화면 밖에 나가면 그대로 사각형 생성
	CWnd::OnLButtonDown(nFlags, point);

	m_num++;
}

// 마우스 땔 때 끝점 기억
void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	m_pShapes[m_num-1]->setMouseUp(point);
	m_bLButton = false;
	ReleaseCapture();

	Invalidate();

	CWnd::OnLButtonUp(nFlags, point);
}

// 드래깅 될 때도 그리게 할려고 
void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	if(m_bLButton == true)
	{
		m_pShapes[m_num-1]->setMouseMove(point); // 움직이고 있으면 두번째 점을 계속 갱신해줌
		Invalidate();
	}
	CWnd::OnMouseMove(nFlags, point);
}



void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_mode ++;
	m_mode = m_mode%2; // 0,1이 계속 왔다갔다함

	CWnd::OnRButtonDown(nFlags, point);
}

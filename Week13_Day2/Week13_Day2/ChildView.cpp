
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "Week13_Day2.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
	:m_bRButton(false) // 기본값은로 안 눌린 상태로 세팅
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
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
	
	POSITION pos = m_pts.GetHeadPosition();

	while(pos!=NULL)
	{
		//CPoint pt = m_pts.GetAt(pos); // pos 위치 받는거는 생략 가능 -> getnext에 포함되어 있음
		CPoint pt = m_pts.GetNext(pos); // position 이 앞으로 감
		//m_pts.GetPrev(pos); // position ㅇ 뒤로 이동

		dc.SetPixelV(pt,RGB(0,0,0)); // 검정색 점 찍기
		//dc.LineTo(pt); // 선을 그리고싶다면!?
	}
	CString str;
	str.Format(_T("count = %d"), m_pts.GetCount()); // 점 몇개 찍혔는지 확인해보기
	dc.TextOutW(0,0,str);

	if(m_bRButton = true) // 왼쪽 사각형 그림
	{
		dc.SelectStockObject(NULL_BRUSH);
		dc.Rectangle(m_pt1.x, m_pt1.y, m_pt2.x, m_pt2.y);
	}
}


// 왼쪽 드래깅 할때 마다 점이 찍힘
void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	if((nFlags & MK_LBUTTON) == MK_LBUTTON ) // 숙어처럼 외우기 !! -> 왼쪽 드래깅을 하고있다면
	{
		m_pts.AddTail(point); 
		Invalidate();
	}
	if(m_bRButton = true)
	{
		m_pt2 = point;
		Invalidate();
	}
	CWnd::OnMouseMove(nFlags, point);
}


// 사각형 영역을 지우기 용도
void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{	
	m_pt1 = point;
	m_bRButton = true;

	SetCapture();
	
	CWnd::OnRButtonDown(nFlags, point);
}


void CChildView::OnRButtonUp(UINT nFlags, CPoint point)
{
	m_pt2 = point;
	m_bRButton = false;
	Invalidate();
	ReleaseCapture();

	
	//여기가 사각형 영역 지우는 코드
	POSITION pos = m_pts.GetHeadPosition();
	while(pos != NULL)
	{
		POSITION pos_current = pos;
		CPoint pt = m_pts.GetNext(pos);

		if(pt.x>m_pt1.x && pt.x<m_pt2.x &&
			pt.y>m_pt1.y && pt.y<m_pt2.y) // 이 조건을 충족하면 점이 사각형 안에 있다.!
		{
			m_pts.RemoveAt(pos);
		}
	}
	Invalidate();
	/////////////////////////////


	CWnd::OnRButtonUp(nFlags, point);
}

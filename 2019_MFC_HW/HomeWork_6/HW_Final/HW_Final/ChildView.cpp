// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "HW_Final.h"
#include "ChildView.h"
#include "MyRect.h"
#include "MyCircle.h"
#include "MyCurve.h"
#include<iostream>
#include<string>

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView
CChildView::CChildView()
	:m_num(0), m_mode(CMyShape::RECT), m_bLbutton(false) // 마우스 클릭 안 한 상태
{  
}

CChildView::~CChildView()
{
	//for(int i=0; i<m_num ; i++)
	//{
	//	delete m_pShape[i];
	//}
	POSITION pos = m_shapes.GetHeadPosition();
	while(pos!=NULL)
	{
		delete	m_shapes.GetNext(pos);
	}
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_SHAPES_RECT, &CChildView::OnShapesRect)
	ON_COMMAND(ID_SHAPES_CIRCLE, &CChildView::OnShapesCircle)
	ON_COMMAND(ID_SHAPES_CURVE, &CChildView::OnShapesCurve)
	ON_COMMAND(ID_VIEW_TOOLBAR, &CChildView::OnViewToolbar)
	ON_COMMAND(ID_ACTION_SELECT, &CChildView::OnActionSelect)
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

	CRect rect;
	GetClientRect(rect);

	int w = rect.Width();
	int h = rect.Height();

	CDC memDC; 
	memDC.CreateCompatibleDC(&dc);
	CBitmap bmp;
	bmp.CreateCompatibleBitmap(&dc,w,h);
	memDC.SelectObject(bmp); 
	// 여기까지 그림그리기 준비 완료 (검정색 바탕)
	memDC.Rectangle(0,0,w,h); // 하얀색 사각형으로 창을 덮음 -> 하얀색배경


	/////////////////////////////////////////////////////////////
	// 여기가 우리가 그림 코딩할 곳
	// 배열 사용 x
	//for(int i=0;i<m_num;i++)
	//{
	//	m_pShape[i]->draw(memDC);
	//}
	//list 사용 o

	POSITION pos = m_shapes.GetHeadPosition();
	bool selectCheck = false;
	while(pos!=NULL)
	{
		if(m_mode==5)//선택했을때만
		{
			selectCheck = m_shapes.GetAt(pos)->getSelectBool();
			if(selectCheck == true)
			{
				m_shapes.GetAt(pos)->selectDraw(memDC);
				selectCheck = false;
			}
			m_shapes.GetAt(pos)->draw(memDC);
		}
		else
		{
			m_shapes.GetAt(pos)->draw(memDC);
		}
		m_shapes.GetNext(pos);
	}

	CString str;
	str.Format(_T("Shapes Num : %d"), m_shapes.GetCount()); // str.format : printf
	memDC.TextOutW(0,0,str);
	/////////////////////////////////////////////////////////////

	dc.BitBlt(0,0,w,h,&memDC,0,0,SRCCOPY);
}

// 화면을 지운다. -> 이것도 기본 포맷
BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	// "화면을 지울 필요가 있다"라는 메시지를 받아서 지우지 말자고 하자
	return true;
}


//마우스를 찍어서 시작점 기억
void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	POSITION pos_temp = m_shapes.GetTailPosition();
	if(m_mode==5 && m_bLbutton == false)  // 도형 선택했을때
	{
		int temp=0;

		while(pos_temp != NULL)
		{
			temp = m_shapes.GetAt(pos_temp)->InPoint(point);
			if(temp == 1) // 도형 내를 클릭했다면 !
			{
				//MessageBox(_T("click!"));
				m_pos = pos_temp;

				m_bLbutton = true;
				m_shapes.GetAt(pos_temp)->setPrePos(point);
				
				break;				
			}
			else{
				//MessageBox(_T("no"));
			}
			m_shapes.GetPrev(pos_temp);
		}
		
	}
	else // 도형 만들때
	{
		switch(m_mode)
		{
		case CMyShape::RECT:
			//m_pShape[m_num] = new CMyRect();
			m_shapes.AddTail(new CMyRect());
			break;
		case CMyShape::CIRCLE:
			//m_pShape[m_num] = new CMyCircle();
			m_shapes.AddTail(new CMyCircle());
			break;
		case CMyShape::CURVE:
			//m_pShape[m_num] = new CMyCurve();
			m_shapes.AddTail(new CMyCurve());
			break;
		default:
			break;
		}

		//m_pShape[m_num]->setMouseDown(point);
		m_shapes.GetTail()->setMouseDown(point);

		m_bLbutton = true;
		SetCapture(); // <-> ReleaseCapture; // 화면 밖에 나가면 그대로 사각형 생성
		CWnd::OnLButtonDown(nFlags, point);

		m_num++;
	}

}

//마우스 뗄 때 끝 점 기억
void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	if(m_mode==5) // 도형 선택했을때
	{
		m_bLbutton = false;	
		//ReleaseCapture();
		
		m_shapes.GetAt(m_pos)->checkSelect();
		Invalidate();
	}
	if(m_bLbutton == true && m_mode != 5)
	{
		//m_pShape[m_num-1]->setMouseUp(point);
		if(m_bLbutton==true)
		{
			m_shapes.GetTail()->setMouseUp(point);
			m_bLbutton = false;
			ReleaseCapture();

			Invalidate();
		}
	}

	CWnd::OnLButtonUp(nFlags, point);
}

// 드래깅 될 때도 그리게 할려고 
void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	if(m_mode==5) //도형 선택했을때 
	{
		if(m_bLbutton == true)
		{
			m_shapes.GetAt(m_pos)->selectMouseMove(point);
			Invalidate();
		}
	}

	if(m_bLbutton == true && m_mode != 5)
	{
		//m_pShape[m_num-1]->setMouseMove(point); // 움직이고 있으면 두번째 점을 계속 갱신해줌
		m_shapes.GetTail()->setMouseMove(point);

		Invalidate();
	}


	CWnd::OnMouseMove(nFlags, point);
}


//도형 변경
void CChildView::OnShapesRect()
{
	m_mode = 0;
	m_bLbutton = false;
	Invalidate();
}

void CChildView::OnShapesCircle()
{
	m_mode = 1;
	m_bLbutton = false;
	Invalidate();
}
void CChildView::OnShapesCurve()
{
	m_mode = 2;
	m_bLbutton = false;
	Invalidate();
}
void CChildView::OnViewToolbar()
{}

//select 클릭
void CChildView::OnActionSelect()
{
	m_mode = 5;
	m_bLbutton = false;
}

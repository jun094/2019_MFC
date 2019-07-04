
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "Week14.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
	:m_mode(0)
{
	m_color=RGB(0,0,0);
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_COLOR_RED, &CChildView::OnColorRed) // &CChildView:: 이거는 생략가능
	ON_COMMAND(ID_COLOR_BLUE, OnColorBlue)
	ON_COMMAND(ID_COLOR_GREEN, OnColorGreen)
	ON_COMMAND(ID_COLOR_NULL, OnColorNULL)
	ON_UPDATE_COMMAND_UI(ID_COLOR_RED, &CChildView::OnUpdateColorRed) 
	ON_UPDATE_COMMAND_UI(ID_COLOR_GREEN, &CChildView::OnUpdateColorGreen)
	ON_UPDATE_COMMAND_UI(ID_COLOR_BLUE, &CChildView::OnUpdateColorBlue)
	ON_COMMAND(ID_SHAPE_CIRCLE, &CChildView::OnShapeCircle)
	ON_COMMAND(ID_SHAPE_RECTANGLE, &CChildView::OnShapeRectangle)
	ON_WM_CREATE()
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

	CBrush brush(m_color);
	dc.SelectObject(brush);

	if(m_mode == 0 )
	{
		dc.Rectangle(100,100,200,200);
	}
	else if(m_mode == 1 )
	{
		dc.Ellipse(100,100,200,200);
	}
	
}



void CChildView::OnColorRed()
{
	//MessageBox(_T("RED!"));
	m_color = RGB(255,0,0);
	Invalidate();
}
void CChildView::OnColorBlue()
{
	//MessageBox(_T("BLUE!"));
	m_color = RGB(0,0,255);
	Invalidate();

}
void CChildView::OnColorGreen()
{
	//MessageBox(_T("GREEN!"));
	m_color = RGB(0,255,0);
	Invalidate();
}

// Update할때
void CChildView::OnUpdateColorRed(CCmdUI *pCmdUI)
{
	if(m_color == RGB(255,0,0)) // 사각형이 빨간색인 경운
	{
		pCmdUI->SetCheck(true);
		pCmdUI->SetText(_T("이미빨간색"));
		pCmdUI->Enable(false);//ENABLE은 T/F를 받음 -> false이면 메뉴 사용 불가로 마우스 선택이 안되게 됨
	}
	else
	{
		pCmdUI->SetCheck(false);
		pCmdUI->Enable(true);
	}
}


void CChildView::OnUpdateColorGreen(CCmdUI *pCmdUI)
{
	if(m_color == RGB(0,255,0)) // 사각형이 빨간색인 경운
	{
		pCmdUI->SetCheck(true);
		pCmdUI->SetText(_T("이미초록색"));
		pCmdUI->Enable(false);//ENABLE은 T/F를 받음 -> false이면 메뉴 사용 불가로 마우스 선택이 안되게 됨
	}
	else
	{
		pCmdUI->SetCheck(false);
		pCmdUI->Enable(true);
	}
}


void CChildView::OnUpdateColorBlue(CCmdUI *pCmdUI)
{
	if(m_color == RGB(0,0,255)) // 사각형이 빨간색인 경운
	{
		pCmdUI->SetCheck(true);
		pCmdUI->SetText(_T("이미파랑색"));
		pCmdUI->Enable(false);//ENABLE은 T/F를 받음 -> false이면 메뉴 사용 불가로 마우스 선택이 안되게 됨
	}
	else
	{
		pCmdUI->SetCheck(false);
		pCmdUI->Enable(true);
	}
}


void CChildView::OnShapeCircle()
{
	m_mode=1;
	Invalidate();
}


void CChildView::OnShapeRectangle()
{
	m_mode=0;
	Invalidate();
}


void CChildView::OnColorNULL()
{
	m_color = RGB(255,255,255);
	Invalidate();
}


int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	/*m_button.Create(_T("빨강 버튼"), BS_PUSHBUTTON, 
					CRect(0,0,100,50),this,ID_COLOR_RED);
	m_button.ShowWindow(true);*/

	return 0;
}

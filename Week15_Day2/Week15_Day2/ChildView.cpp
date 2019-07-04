
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "Week15_Day2.h"
#include "ChildView.h"
#include "TextInputDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	m_str = _T("Click me!");
	m_rect = CRect(100,100,400,200);
	m_color = RGB(0,0,0);
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
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
	CPaintDC dc(this); 
	dc.Rectangle(m_rect); // 생성자에서 만든 사각형을 그리고 

	//dc.TextOutW(0,0,m_str);
	dc.SetTextColor(m_color); // 글자색은 draw전에 !!!
	dc.DrawText(m_str, m_rect, DT_CENTER|DT_VCENTER|DT_SINGLELINE);// 사각형 안에 글 쓸꺼임 !
									 // DT_LEFT:왼쪽 정렬 , DT_CENTER|DT_VCENTER|DT_SINGLELINE : 가로 세로 가운데정렬
}

void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	//사각형을 클릭했을 떄
	if(m_rect.PtInRect(point)) // PtInRect(point) : 좌표가 사각형 안에 있는지 검사해주는 함수
	{
		//클릭하면 내가 만든 DLG 띄우기 !

		CTextInputDlg dlg; // 내가 만든 이 클래스 사용할려면 #include "TextInputDlg.h"
		dlg.m_editStr = m_str; // value값을 click me로 바꿈

		dlg.m_red = GetRValue(m_color);
		dlg.m_green = GetGValue(m_color);
		dlg.m_blue = GetBValue(m_color);


		if(dlg.DoModal() == IDOK ) // dlg.DoModal() : 모달 띄우는 함수 -> 이게 IDOK(확인)버튼누르면..
		//또는  if(dlg.DoModal() == IDCNACEL ) 취소 버튼을 누르면...
		{
			m_str = dlg.m_editStr;
			m_color = RGB(dlg.m_red,dlg.m_green,dlg.m_blue);
			
			Invalidate();
		}
		
	}
	CWnd::OnLButtonDown(nFlags, point);
}

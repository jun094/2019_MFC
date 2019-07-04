
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "final_ex02.h"
#include "ChildView.h"
#include "TextInput.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
	: str("hi")
{
	m_rect.SetRect(100,100,200,200);
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONDOWN()
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

	////////////////
	memDC.Rectangle(100,100,200,200);
	memDC.SetTextColor(m_color);
	memDC.DrawText(str,m_rect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	//////////////
	dc.BitBlt(0,0,w,h,&memDC,0,0,SRCCOPY);
}
BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	return true;
}


void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CTextInput dlg;
	dlg.m_edit = str;

	dlg.m_r = GetRValue(m_color);
	dlg.m_g = GetGValue(m_color);
	dlg.m_b = GetBValue(m_color);

	if(	dlg.DoModal() == IDOK)
	{
		str=dlg.m_edit;
		m_color = RGB(dlg.m_r, dlg.m_g,dlg.m_b);
		Invalidate();
	}
	
	
	CWnd::OnLButtonDown(nFlags, point);
}

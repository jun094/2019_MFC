
// ChildView.cpp : CChildView Ŭ������ ����
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
	CPaintDC dc(this); 
	dc.Rectangle(m_rect); // �����ڿ��� ���� �簢���� �׸��� 

	//dc.TextOutW(0,0,m_str);
	dc.SetTextColor(m_color); // ���ڻ��� draw���� !!!
	dc.DrawText(m_str, m_rect, DT_CENTER|DT_VCENTER|DT_SINGLELINE);// �簢�� �ȿ� �� ������ !
									 // DT_LEFT:���� ���� , DT_CENTER|DT_VCENTER|DT_SINGLELINE : ���� ���� �������
}

void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	//�簢���� Ŭ������ ��
	if(m_rect.PtInRect(point)) // PtInRect(point) : ��ǥ�� �簢�� �ȿ� �ִ��� �˻����ִ� �Լ�
	{
		//Ŭ���ϸ� ���� ���� DLG ���� !

		CTextInputDlg dlg; // ���� ���� �� Ŭ���� ����ҷ��� #include "TextInputDlg.h"
		dlg.m_editStr = m_str; // value���� click me�� �ٲ�

		dlg.m_red = GetRValue(m_color);
		dlg.m_green = GetGValue(m_color);
		dlg.m_blue = GetBValue(m_color);


		if(dlg.DoModal() == IDOK ) // dlg.DoModal() : ��� ���� �Լ� -> �̰� IDOK(Ȯ��)��ư������..
		//�Ǵ�  if(dlg.DoModal() == IDCNACEL ) ��� ��ư�� ������...
		{
			m_str = dlg.m_editStr;
			m_color = RGB(dlg.m_red,dlg.m_green,dlg.m_blue);
			
			Invalidate();
		}
		
	}
	CWnd::OnLButtonDown(nFlags, point);
}

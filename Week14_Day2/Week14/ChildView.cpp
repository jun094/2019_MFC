
// ChildView.cpp : CChildView Ŭ������ ����
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
	ON_COMMAND(ID_COLOR_RED, &CChildView::OnColorRed) // &CChildView:: �̰Ŵ� ��������
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

// Update�Ҷ�
void CChildView::OnUpdateColorRed(CCmdUI *pCmdUI)
{
	if(m_color == RGB(255,0,0)) // �簢���� �������� ���
	{
		pCmdUI->SetCheck(true);
		pCmdUI->SetText(_T("�̹̻�����"));
		pCmdUI->Enable(false);//ENABLE�� T/F�� ���� -> false�̸� �޴� ��� �Ұ��� ���콺 ������ �ȵǰ� ��
	}
	else
	{
		pCmdUI->SetCheck(false);
		pCmdUI->Enable(true);
	}
}


void CChildView::OnUpdateColorGreen(CCmdUI *pCmdUI)
{
	if(m_color == RGB(0,255,0)) // �簢���� �������� ���
	{
		pCmdUI->SetCheck(true);
		pCmdUI->SetText(_T("�̹��ʷϻ�"));
		pCmdUI->Enable(false);//ENABLE�� T/F�� ���� -> false�̸� �޴� ��� �Ұ��� ���콺 ������ �ȵǰ� ��
	}
	else
	{
		pCmdUI->SetCheck(false);
		pCmdUI->Enable(true);
	}
}


void CChildView::OnUpdateColorBlue(CCmdUI *pCmdUI)
{
	if(m_color == RGB(0,0,255)) // �簢���� �������� ���
	{
		pCmdUI->SetCheck(true);
		pCmdUI->SetText(_T("�̹��Ķ���"));
		pCmdUI->Enable(false);//ENABLE�� T/F�� ���� -> false�̸� �޴� ��� �Ұ��� ���콺 ������ �ȵǰ� ��
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

	/*m_button.Create(_T("���� ��ư"), BS_PUSHBUTTON, 
					CRect(0,0,100,50),this,ID_COLOR_RED);
	m_button.ShowWindow(true);*/

	return 0;
}

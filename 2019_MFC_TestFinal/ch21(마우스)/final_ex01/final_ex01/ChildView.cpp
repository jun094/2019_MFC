
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "final_ex01.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "MyCircle.h"
// CChildView

CChildView::CChildView()
	:m_num(0), m_Lbutton(false), m_mode(0), m_pos(nullptr), flag(true)
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
	ON_COMMAND(ID_ACTION_MINUS, &CChildView::OnActionMinus)
	ON_COMMAND(ID_ACTION_PLUS, &CChildView::OnActionPlus)
	ON_COMMAND(ID_DRAW_CIRCLE, &CChildView::OnDrawCircle)
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

	//1. ��ü â SIZE ���
	CRect rect;
	GetClientRect(rect);

	int w = rect.Width();
	int h = rect.Height();

	//2. RePain dc �����
	CDC memDC;
	memDC.CreateCompatibleDC(&dc);

	CBitmap bmp;
	bmp.CreateCompatibleBitmap(&dc, w,h);
	memDC.SelectObject(bmp);

	memDC.Rectangle(0,0,w,h);
	/////////////////////////////////////
	POSITION pos = m_circle.GetHeadPosition();

	while(pos != NULL)
	{
		m_circle.GetNext(pos)->draw(memDC);
	}
	CString str;
	str.Format(_T("x=%d, y=%d"),m_x,m_y);
	memDC.TextOutW(10,10,str);
	////////////////////////////////////
	dc.BitBlt(0,0,w,h,&memDC,0,0,SRCCOPY);
}
BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	return true;
}


void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{

	if(m_mode==0)
	{
		float preR = 0; //������ ��
		m_Lbutton = true;
		m_circle.AddTail(new CMyCircle());
		m_circle.GetTail()->setMouseDown(point, m_mode,flag, preR);
	}
	else if(m_mode==1)
	{
		m_Lbutton = true;
		POSITION pos = m_circle.GetTailPosition();
		while(pos!=NULL)
		{
			if(m_circle.GetAt(pos)->InPoint(point)) // �������� �� ���� ������
			{
				m_pos = pos; // �װ� ������ ����
				break;
			}
			m_circle.GetPrev(pos);
		}
	}
	else if(m_mode==2)
	{
		m_Lbutton = true;
		POSITION pos2 = m_circle.GetTailPosition();
		while(pos2!=NULL)
		{
			if(m_circle.GetAt(pos2)->InPoint(point)) // �������� �� ���� ������
			{
				float preR = m_circle.GetAt(pos2)->getR();
				CPoint preCenter = m_circle.GetAt(pos2)->getPreCenter();

				m_circle.RemoveAt(pos2); // ���� �� �����ϰ� 
				m_circle.AddTail(new CMyCircle); // ������ �߰�
				m_circle.GetTail()->setMouseDown(preCenter, m_mode,flag, preR);
				flag = false;

				m_circle.AddTail(new CMyCircle); // ������2 �߰�
				m_circle.GetTail()->setMouseDown(preCenter, m_mode,flag, preR);
				flag = true;
				break;
			}
			m_circle.GetPrev(pos2);
		}
	}

	CWnd::OnLButtonDown(nFlags, point);
}
void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	if(m_mode==1 && m_Lbutton == true)
	{
		if(m_pos!=nullptr)
		{
			m_circle.GetAt(m_pos)->setMouseMove(point);
			Invalidate();
		}
	}
	CWnd::OnMouseMove(nFlags, point);
}

void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// ���� ��ǥ ����غ���
	m_x = point.x;
	m_y= point.y;
	//////


	m_Lbutton = false;
	m_pos = nullptr;
	Invalidate();
	CWnd::OnLButtonUp(nFlags, point);
}



void CChildView::OnActionMinus()
{
	m_mode = 2;
	m_Lbutton = false;
	Invalidate();
}
void CChildView::OnActionPlus()
{
	m_mode = 1;
	m_Lbutton = false;
	Invalidate();
}


void CChildView::OnDrawCircle()
{
	m_mode = 0;
	m_Lbutton = false;
	Invalidate();
}

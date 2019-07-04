
// ChildView.cpp : CChildView Ŭ������ ����
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

// �׸��׸��� ��
void CChildView::OnPaint() 
{
	CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

	CRect rect;
	GetClientRect(rect);
	int w = rect.Width();
	int h = rect.Height();

	CDC memDC; // ���ο� ��ȭ��
	memDC.CreateCompatibleDC(&dc); // ������� ��ĸ� ����
	CBitmap bmp;
	bmp.CreateCompatibleBitmap(&dc,w,h);
	memDC.SelectObject(bmp); 
	// ������� �׸��׸��� �غ� �Ϸ� (������ ����)

	memDC.Rectangle(0,0,w,h); // �Ͼ�� �簢������ â�� ���� -> �Ͼ�����

	/////////////////////////////////////////////////////////////
	// ���Ⱑ �츮�� �׸� �ڵ��� ��
	for(int i=0;i<m_num;i++)
	{
		m_pShapes[i]->draw(memDC);
	}
	/////////////////////////////////////////////////////////////

	dc.BitBlt(0,0,w,h,&memDC,0,0,SRCCOPY);

}
// ȭ���� �����. -> �̰͵� �⺻ ����
BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	//return CWnd::OnEraseBkgnd(pDC);
	return true;
}


// ���콺 �� ������ ���
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
	SetCapture(); // <-> ReleaseCapture; // ȭ�� �ۿ� ������ �״�� �簢�� ����
	CWnd::OnLButtonDown(nFlags, point);

	m_num++;
}

// ���콺 �� �� ���� ���
void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	m_pShapes[m_num-1]->setMouseUp(point);
	m_bLButton = false;
	ReleaseCapture();

	Invalidate();

	CWnd::OnLButtonUp(nFlags, point);
}

// �巡�� �� ���� �׸��� �ҷ��� 
void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	if(m_bLButton == true)
	{
		m_pShapes[m_num-1]->setMouseMove(point); // �����̰� ������ �ι�° ���� ��� ��������
		Invalidate();
	}
	CWnd::OnMouseMove(nFlags, point);
}



void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	m_mode ++;
	m_mode = m_mode%2; // 0,1�� ��� �Դٰ�����

	CWnd::OnRButtonDown(nFlags, point);
}


// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "ex01_mouse.h"
#include "ChildView.h"
#include "MyRect.h"
#include "MyCircle.h"
#include "MyCurve.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView
CChildView::CChildView()
	:m_num(0), m_mode(CMyShape::RECT), m_bLbutton(false)
{
}

CChildView::~CChildView()
{
	for(int i=0; i<m_num ; i++)
	{
		delete m_pShape[i];
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
	// ������� �׸��׸��� �غ� �Ϸ� (������ ����)

	memDC.Rectangle(0,0,w,h); // �Ͼ�� �簢������ â�� ���� -> �Ͼ�����

	/////////////////////////////////////////////////////////////
	// ���Ⱑ �츮�� �׸� �ڵ��� ��
	//CString str;
	//str.Format(_T("Rect Num : %d"), m_num,0,0); // str.format : printf

	for(int i=0;i<m_num;i++)
	{
		m_pShape[i]->draw(memDC);
	}
	/////////////////////////////////////////////////////////////

	dc.BitBlt(0,0,w,h,&memDC,0,0,SRCCOPY);
}


// ȭ���� �����. -> �̰͵� �⺻ ����
BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	// ��ȭ���� ���� �ʿ䰡 �ִ١���� �޽����� �޾Ƽ� ������ ���ڰ� ����
	return true;
}


//���콺�� �� ������ ���
void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	switch(m_mode)
	{
	case CMyShape::RECT:
		m_pShape[m_num] = new CMyRect();
		break;
	case CMyShape::CIRCLE:
		m_pShape[m_num] = new CMyCircle();
		break;
	case CMyShape::CURVE:
		m_pShape[m_num] = new CMyCurve();
		break;
	default:
		break;
	}

	m_pShape[m_num]->setMouseDown(point);

	m_bLbutton = true;
	SetCapture(); // <-> ReleaseCapture; // ȭ�� �ۿ� ������ �״�� �簢�� ����
	CWnd::OnLButtonDown(nFlags, point);

	m_num++;
}

//���콺 �� �� �� �� ���
void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	m_pShape[m_num-1]->setMouseUp(point);
	m_bLbutton = false;
	ReleaseCapture();

	Invalidate();

	CWnd::OnLButtonUp(nFlags, point);
}

// �巡�� �� ���� �׸��� �ҷ��� 
void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	if(m_bLbutton == true)
	{
		m_pShape[m_num-1]->setMouseMove(point); // �����̰� ������ �ι�° ���� ��� ��������
		Invalidate();
	}
	CWnd::OnMouseMove(nFlags, point);
}


//���� ����
void CChildView::OnShapesRect()
{
	m_mode = 0;
	Invalidate();
}

void CChildView::OnShapesCircle()
{
	m_mode = 1;
	Invalidate();
}
void CChildView::OnShapesCurve()
{
	m_mode = 2;
	Invalidate();
}


void CChildView::OnViewToolbar()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}

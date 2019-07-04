// ChildView.cpp : CChildView Ŭ������ ����
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
	:m_num(0), m_mode(CMyShape::RECT), m_bLbutton(false) // ���콺 Ŭ�� �� �� ����
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
	// �迭 ��� x
	//for(int i=0;i<m_num;i++)
	//{
	//	m_pShape[i]->draw(memDC);
	//}
	//list ��� o

	POSITION pos = m_shapes.GetHeadPosition();
	bool selectCheck = false;
	while(pos!=NULL)
	{
		if(m_mode==5)//������������
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

// ȭ���� �����. -> �̰͵� �⺻ ����
BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	// "ȭ���� ���� �ʿ䰡 �ִ�"��� �޽����� �޾Ƽ� ������ ���ڰ� ����
	return true;
}


//���콺�� �� ������ ���
void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	POSITION pos_temp = m_shapes.GetTailPosition();
	if(m_mode==5 && m_bLbutton == false)  // ���� ����������
	{
		int temp=0;

		while(pos_temp != NULL)
		{
			temp = m_shapes.GetAt(pos_temp)->InPoint(point);
			if(temp == 1) // ���� ���� Ŭ���ߴٸ� !
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
	else // ���� ���鶧
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
		SetCapture(); // <-> ReleaseCapture; // ȭ�� �ۿ� ������ �״�� �簢�� ����
		CWnd::OnLButtonDown(nFlags, point);

		m_num++;
	}

}

//���콺 �� �� �� �� ���
void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	if(m_mode==5) // ���� ����������
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

// �巡�� �� ���� �׸��� �ҷ��� 
void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	if(m_mode==5) //���� ���������� 
	{
		if(m_bLbutton == true)
		{
			m_shapes.GetAt(m_pos)->selectMouseMove(point);
			Invalidate();
		}
	}

	if(m_bLbutton == true && m_mode != 5)
	{
		//m_pShape[m_num-1]->setMouseMove(point); // �����̰� ������ �ι�° ���� ��� ��������
		m_shapes.GetTail()->setMouseMove(point);

		Invalidate();
	}


	CWnd::OnMouseMove(nFlags, point);
}


//���� ����
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

//select Ŭ��
void CChildView::OnActionSelect()
{
	m_mode = 5;
	m_bLbutton = false;
}

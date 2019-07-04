
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "Week12_Day2.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
	:m_pt1(100,100), m_pt2(300,300)
{
	//�������� 1 ppt23 : ���׸��� 
	//������� ����������� �������� x,y��ǥ�� �����ڿ��� �ʱ�ȭ ���ش�. 
	//�׷���,, CPoint�� Ŭ�����̴�. �׷� childview �� �����ڰ� �Ҹ���, cpoint �����ڵ� �Ҹ� ���̴�.
	//�׷� cpoint �����ڵ� ������־�� �ϴµ�,, �ְ� default �����ڰ� �� ������� �ִٸ�???
	// ���� ó�� {} ���� ������ ���� ���ָ�ȴ�..!!!!
	m_pt1=CPoint(0,0);
	m_pt2=CPoint(0,0); 
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
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

//mouse & key
void CChildView::OnPaint() 
{
	CPaintDC dc(this); // childe view���� ������

	
	CRect rect;
	GetClientRect(rect);
	int w= rect.Width();
	int h = rect.Height();//rect.Width(),rect.Height(): ���� ȭ���� ũ��

	CDC memDC; //   ���� �Ƕ��� ����� -> �ӵ� ���
	memDC.CreateCompatibleDC(&dc);
	CBitmap bmp;
	bmp.CreateCompatibleBitmap(&dc,w,h); //rect.Width(),rect.Height(): ���� ȭ���� ũ��
	memDC.SelectObject(bmp);

	/*
	for(int x=0;x<256;x++)
		for(int y=0;y<256;y++)
			//dc.SetPixelV(x,y,RGB(x,0,y)); //���� �ٸ� ��ġ�� ���� �ٸ� �� ���
			memDC.SetPixelV(x,y,RGB(x,0,y)); // ������ �׸���
	dc.BitBlt(0,0,w,h,&memDC,0,0,SRCCOPY);
	*/


	//�������� 1 ppt23 : ���׸���
	memDC.Rectangle(0,0,w,h); // ��� �Ͼ������ ä���
	memDC.MoveTo(m_pt1);
	memDC.MoveTo(m_pt2);
}


//�̺�Ʈ ����ϱ� : childview -> �Ӽ� -> �޼��� -> WM_ERASEBKGND �� ADD �ϱ�
//�Լ� �̸�(�ؿ��ִ°�), �Լ� ���(������Ͽ� afx_msg), �Լ�ȣ��(BEGIN_MESSAGE_MAP) �� 3���� �߰� �� 
BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{

	return true; // �׳� �̷��� �ϴ°�.. ������ ������..!
}

typedef float STLSOO; // STLSOO : �Ǽ�?

//���콺 ���� Ŭ���ϸ� �߻��ϴ� �̺�Ʈ
void CChildView::OnLButtonDown(UINT nFlags, CPoint point) 
	// UINT nFlags, CPoint point: ���� Ŭ������ �� ���� ������(flag:��Ŭ���ߴ���,point:��ǥ)
{
	/*
	//����1 �ܼ� �ؽ�Ʈ ���
	//MessageBox(_T("���� Ŭ��!"));
	
	//����2 ��ǥ ���
	CString str;
	str.Format(_T("x=%d, y=%d, flag=%d"), point.x,point.y,nFlags); // str.format : printf
	MessageBox(str);

	// <nFlags> 1, 2, 4, 8, 16, 32, 64, ...
	//          L  R  Sh Ct Mid .... --> shift + ctrl + L Ŭ���ϸ�? = 13!!

	//����3 : ����, CTRL ���� Ŭ������ ����
	if(nFlags==(MK_LBUTTON + MK_CONTROL))
	{
		CString str;
		str.Format(_T("x=%d, y=%d, flag=%d"), point.x,point.y,nFlags);
		MessageBox(str);
	}
	*/

	//�������� 1 ppt23 : ���׸���
	m_pt1=point;
	SetCapture(); // ȭ�� ������ �������� 

	CWnd::OnLButtonDown(nFlags, point);
}

//�������� 1 ppt23 : ���׸��� 
void CChildView::OnLButtonUp(UINT nFlags, CPoint point) // ������ ���� ����ؼ� �Ʊ� �������� �̾�
{
	m_pt2=point; // �����ϋ�
	
	Invalidate(); // �ٽ� �׷��� ( invalidate : ��ȿȭ )

	CWnd::OnLButtonUp(nFlags, point);
	
	ReleaseCapture(); // ȭ�� ������ �������� 
}

// ���콺�� �����϶����� ��� �Ҹ��� �ϰ� �ʹٸ�
void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	//if(nFlags == MK_LBUTTON) // L��ư�� �����鼭 ���콺�� �����δٸ�
	if((nFlags & MK_LBUTTON) == MK_LBUTTON) // ����ó�� �Ⱦ��� �̷��� ��,, �׳� �׷�
	{
		m_pt2 = point;
		Invalidate();
	}

	CWnd::OnMouseMove(nFlags, point);

}

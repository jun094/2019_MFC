
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "ex0115.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
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

	// ���� 3)
	dc.TextOutW(100,200,_T("������б�")); // MFC������ ��� String�� _T�� ���´�..!
	dc.SetTextColor(RGB(255,0,0)); //�۾� �� ����
	//dc.SetBkColor(RGB(255,0,0)); // �۾� ��� ��
	dc.SetBkMode(TRANSPARENT); // �۾� ���� ����
	
	// ���� 4) �� �Ӽ� ����
	CPen pen(PS_SOLID, 3, RGB(0,0,255)); // PenStyle�� solid�� 3? �Ķ���
	dc.SelectObject(pen);

	// ���� 5) �귯�� �Ӽ� ����
	CBrush brush(HS_DIAGCROSS, RGB(0,255,0));
	dc.SelectObject(brush);
	dc.Rectangle(100,100,200,200);

	CRect r;
	GetClientRect(r);
	r.left;
	r.top;
	r.right;
	r.bottom;

	// ���� 1)
	/*
	dc.Ellipse(r.left,r.top,r.right,r.bottom); // Ÿ���� �׸�

	dc.MoveTo(100,100);
	dc.LineTo(200,100); // �Ѻ� �׸��� (100,100) ~ (200,100)
	dc.LineTo(200,200); // 200,100 ~ (200,200) 
	// �� ���� 2��
	*/

	// ����2) S45
	
	float div = 30; //�ٰ���
	float width = r.right - r.left;
	float height = r.bottom - r.top;

	float dw = width/div;
	float dh = height/div;

	for(int i=0;i<div;i++)
	{
		dc.MoveTo(0,dh*i);
		dc.LineTo(i*dw, r.bottom);
	}

	// ���� 6) ��Ʈ �Ӽ� ����
	CFont font;
	font.CreatePointFont(400,_T("�ü�ü"));
	dc.SelectObject(font);


	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	
	//dc.RectANGLE(100,100,200,200);
	/*for(int i=0;i<10;i++)
	{
		int x1=100+i*10;
		int y1=100+i*10;
		int x2=300+i*10;
		int y2=300+i*10;
	}*/
	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.
}



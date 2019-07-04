
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "HomeWork_6.h"
#include "ChildView.h"
#include <math.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	m_color = RGB(255,255,0);
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

	//â ��ġ ���
	CRect r;
	GetClientRect(r);
	//r.left; r.right; r.top; r.bottom;
	dc.Ellipse(r.left,r.top,r.right,r.bottom);

	//1. �����׸���
	dc.Rectangle(100,100,200,200); // �簢�� �׸���
	dc.Ellipse(100,100,200,200); // Ÿ���׸���

	//2. �۾� ����			
	dc.SetTextColor(RGB(255,0,0,)); //���ڻ�
	//dc.SetBkColor(RGB(0,255,0)); // ���� ����
	dc.TextOutW(300,200,_T("�ȳ��ϼ���")); //���ھ���

	//3. ���� �׸���
	dc.MoveTo(200,200); //������ ��ġ ���
	dc.LineTo(300,400);
	dc.LineTo(400,200);


	// 4.select object(GDI��ü) : ���� ��(CPen), ���� ��(CBrush), �۲�(CFont) �ٲٱ� 
	// SelectObject ��� :  Bitmap, Pen, Brush, Font --> select object �����ϰ� ����,���� �׸���.!!!
	
	// 4-1. CPen
	CPen pen(PS_SOLID, 3, RGB(0,0,255)); //PS_DOT : ����, PS_DASH : dash��
										//(������, ����, ��)
	dc.SelectObject(pen);
	
	// 4-2. CBrush
	//CBrush brush(RGB(255,0,0)); //�⺻ ��������
	CBrush brush(HS_DIAGCROSS,RGB(255,0,0)); //x���� ���� ��������
	dc.SelectObject(brush);
	dc.Rectangle(400,400,500,500);

	// 4-3. CFont
	CFont font; // �۾�ü 
	font.CreatePointFont(150,_T("�ü�ü"));

	dc.SelectObject(font);
	dc.TextOutW(0,0,_T("�ü�ü�Դϴ�.")); //���ھ���

	// 4-4. CPoint���� �� -> CRgn (�ٰ���) -> SelectStockObject
	//ex1) �ﰢ��
	CPoint pt[3];
	
	pt[0] = CPoint(500,100);
	pt[1] = CPoint(600,200);
	pt[2] = CPoint(400,200); // �� ���� ��,

	CRgn rgn;
	rgn.CreatePolygonRgn(pt, 3, WINDING); // �ٰ��� ���� ��,
							//WINDING : ��ġ�� �κ��� ������ ��ĥ��
							//ALTERNATE : ��ġ�� �κ��� ������ ���������
	dc.SelectStockObject(BLACK_BRUSH);
	dc.PaintRgn(&rgn); // ������ �׷��ֱ�


	// 4-5. CBitmap(�ҷ�����) -> BITMAP(��������ϱ�)   �̰� �׳� �ܿ��!!!!!!
	// ex1) ������ brush�� �����ϴ� ��� (������ ���� x) -> �ٵ��ǽ�
	CBitmap bmp;
	bmp.LoadBitmapW(IDB_BITMAP1); // �ҷ�����
	
	BITMAP bmpInfo; // bitmap ���� ����ϱ�
	bmp.GetBitmap(&bmpInfo);
	
	int w = bmpInfo.bmWidth;
	int h = bmpInfo.bmHeight;

	CString str; // mfc������ ���ڿ� ������ Ÿ�� : CString
	str.Format(_T("bitmap ũ�� => w=%d, h=%d"),w,h); // Format �޼ҵ� : printf�� �Ȱ��� ���
	dc.TextOutW(600,600, str); // �۾� ���

	//�ٰ��� ����� �ű⿡ bmp������
	const int num = 10;
	int radius = 100; // ������
	CPoint pt2[num];

	for(int i=0;i<num;i++)
	{
		float theta = 2*3.141592/num*i;
		float x = 1100 + radius*cos(theta);
		float y = 600 + radius*sin(theta);
		pt2[i] = CPoint(x,y);
	}
	CRgn rgnTen;
	rgnTen.CreatePolygonRgn(pt2,num,ALTERNATE);


	CBrush brush_bmp(&bmp);
	dc.SelectObject(brush_bmp);	
	dc.PaintRgn(&rgnTen);


	//ex2) �Ѳ����� ���� (������ ���� o) -> cover�� ����
	/*
	1. �޸�DC ����� (CreateCompatibleDC)
	2. �׸��׸� �޸� ����� (CreateCompatibleBitmap)
	3. DC�� Bitmap�� ���� (SelectObject)
	4. �׸� �׸���
	5. �׷��� �׸��� ȭ��DC�� BitBlt */	

	//CRect rectBmp;
	////GetClientRect(&rectBmp); // ���� â ��ü�� �ϰ� �ʹٸ�??
	////rectBmp.SetRect(600,300,700,400);
	//
	//// ������ ����̽� ����Ʈ�� �ϳ� �� �����.
	//CDC memDC;
	//memDC.CreateCompatibleDC(&dc); // 1. �޸�DC ����� 

	//CBitmap bitmap;
	//bitmap.CreateCompatibleBitmap(&dc,rectBmp.Width(),rectBmp.Height()); //2. �׸��׸� �޸� ����� -> bmp�� �簢�� ũ�⸸ŭ �����
	//memDC.SelectObject(&bitmap); //3. DC�� Bitmap�� ����
	//memDC.Rectangle(600,300,700,400);

	//dc.BitBlt(600,300,rectBmp.Width(),rectBmp.Height(),&memDC,600,300,SRCCOPY);
	


	// �Ź��� ġ�� ����
	float div = 30; //�ٰ���
	float width = r.right - r.left; // â ���� ����
	float height = r.bottom - r.top; // â ���� ����

	float dw = width/div; // �ٰ� ����
	float dh = height/div;

	for(int i=0;i<div;i++) 
	{
		dc.MoveTo(0,i*dh); // ���� �� ���� ��ŭ ��� �׸�
		dc.LineTo(i*dw,r.bottom);
	}
	for(int i=0;i<div;i++) 
	{
		dc.MoveTo(i*dw,0); // ���� �� ���� ��ŭ ��� �׸�
		dc.LineTo(r.right,i*dh);
	}




}


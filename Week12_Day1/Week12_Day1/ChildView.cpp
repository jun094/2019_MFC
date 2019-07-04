
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "Week12_Day1.h"
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

#include<cmath>
void CChildView::OnPaint() // ����� �׸��� �׸���.!!!!!!!
{
	CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.
	
	//�ﰢ��
	//CPoint pt[3];
	//pt[0] = CPoint(200,200);
	//pt[1] = CPoint(100,300);
	//pt[2] = CPoint(300,300);

	//CRgn rgn;
	//rgn.CreatePolygonRgn(pt,3,WINDING); // ���ε� ppt ����

	//dc.SelectStockObject(BLACK_BRUSH);
	//dc.PaintRgn(&rgn);

	//10����
	const int num = 10;
	int r = 200;
	CPoint pt[num];

	for(int i=0 ; i<num;i++)
	{
		float theta = 2*3.141592/num*i; // / 180.f*3.141592; // 180.f*3.141592�� �������ν� 0~360�� �� �ƴ϶�, ��ǻ�� �� �°� 0~���� 
		float x = 300 + r* cos(theta); // �ﰢ�Լ� : ������ * �ڻ���(��Ÿ) = ���� ��ǥ 
		float y = 300 + r* sin(theta); //
		pt[i] = CPoint(x,y);
	}
	CRgn rgn;
	rgn.CreatePolygonRgn(pt,num,WINDING); // ���ε� ppt ����

	//bitmap �ҷ�����
	CBitmap bmp;
	bmp.LoadBitmapW(IDB_BITMAP3);
	
	//bitmap ���� ����ϱ�
	BITMAP bmpInfo;
	bmp.GetBitmap(&bmpInfo); // ��Ʈ���� ������ �˰������
	int w = bmpInfo.bmWidth;
	int h = bmpInfo.bmHeight;
	CString str; // mfc������ ���ڿ� ������ Ÿ�� : CString
	str.Format(_T("w=%d, h=%d"),w,h); // Format �޼ҵ� : printf�� �Ȱ��� ���
	dc.TextOutW(0,0, str);

	CBrush brush(&bmp);

	dc.SelectObject(brush);
	dc.PaintRgn(&rgn);


	// �簢���� �ٿ���� bmp �ֱ�
	dc.Rectangle(400,100,600,400);


	// �׷� ���� ���ϴ� ��ġ�� ���ϴ� ũ�⸸ŭ ����ҷ���??
	// ������ ����̽� ����Ʈ�� �ϳ� �� �����.
	CDC memDC;
	memDC.CreateCompatibleDC(&dc);
	memDC.SelectObject(bmp);

	// 100,100 ���� w,h ��ŭ memDC�� 0,0���� �����ͼ� �׸�����
	dc.BitBlt(100,100,w,h,&memDC,0,0,SRCCOPY);
	dc.BitBlt(150,150,w,h,&memDC,0,0,SRCCOPY);
	dc.BitBlt(200,200,w,h,&memDC,0,0,SRCCOPY);

	//ũ�⸦ �÷��� ���
	dc.StretchBlt(100,100,2*w,2*h,&memDC,0,0,w,h,SRCCOPY);
}


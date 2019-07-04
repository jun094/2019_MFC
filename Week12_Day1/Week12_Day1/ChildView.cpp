
// ChildView.cpp : CChildView 클래스의 구현
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



// CChildView 메시지 처리기

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
void CChildView::OnPaint() // 여기다 그림을 그린다.!!!!!!!
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	
	//삼각형
	//CPoint pt[3];
	//pt[0] = CPoint(200,200);
	//pt[1] = CPoint(100,300);
	//pt[2] = CPoint(300,300);

	//CRgn rgn;
	//rgn.CreatePolygonRgn(pt,3,WINDING); // 와인딩 ppt 참고

	//dc.SelectStockObject(BLACK_BRUSH);
	//dc.PaintRgn(&rgn);

	//10각형
	const int num = 10;
	int r = 200;
	CPoint pt[num];

	for(int i=0 ; i<num;i++)
	{
		float theta = 2*3.141592/num*i; // / 180.f*3.141592; // 180.f*3.141592을 해줌으로써 0~360도 가 아니라, 컴퓨터 언어에 맞게 0~파이 
		float x = 300 + r* cos(theta); // 삼각함수 : 반지름 * 코사인(세타) = 원의 좌표 
		float y = 300 + r* sin(theta); //
		pt[i] = CPoint(x,y);
	}
	CRgn rgn;
	rgn.CreatePolygonRgn(pt,num,WINDING); // 와인딩 ppt 참고

	//bitmap 불러오기
	CBitmap bmp;
	bmp.LoadBitmapW(IDB_BITMAP3);
	
	//bitmap 정보 출력하기
	BITMAP bmpInfo;
	bmp.GetBitmap(&bmpInfo); // 비트맵의 정보를 알고싶을떄
	int w = bmpInfo.bmWidth;
	int h = bmpInfo.bmHeight;
	CString str; // mfc에서의 문자열 데이터 타입 : CString
	str.Format(_T("w=%d, h=%d"),w,h); // Format 메소드 : printf와 똑같은 기능
	dc.TextOutW(0,0, str);

	CBrush brush(&bmp);

	dc.SelectObject(brush);
	dc.PaintRgn(&rgn);


	// 사각형에 다운받은 bmp 넣기
	dc.Rectangle(400,100,600,400);


	// 그럼 내가 원하는 위치에 원하는 크기만큼 출력할려면??
	// 가상의 디바이스 컨택트를 하나 더 만든다.
	CDC memDC;
	memDC.CreateCompatibleDC(&dc);
	memDC.SelectObject(bmp);

	// 100,100 부터 w,h 만큼 memDC의 0,0부터 가져와서 그릴꺼야
	dc.BitBlt(100,100,w,h,&memDC,0,0,SRCCOPY);
	dc.BitBlt(150,150,w,h,&memDC,0,0,SRCCOPY);
	dc.BitBlt(200,200,w,h,&memDC,0,0,SRCCOPY);

	//크기를 늘려서 출력
	dc.StretchBlt(100,100,2*w,2*h,&memDC,0,0,w,h,SRCCOPY);
}


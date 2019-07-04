
// ChildView.cpp : CChildView 클래스의 구현
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

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

	//창 위치 얻기
	CRect r;
	GetClientRect(r);
	//r.left; r.right; r.top; r.bottom;
	dc.Ellipse(r.left,r.top,r.right,r.bottom);

	//1. 도형그리기
	dc.Rectangle(100,100,200,200); // 사각형 그리기
	dc.Ellipse(100,100,200,200); // 타원그리기

	//2. 글씨 쓰기			
	dc.SetTextColor(RGB(255,0,0,)); //글자색
	//dc.SetBkColor(RGB(0,255,0)); // 글자 배경색
	dc.TextOutW(300,200,_T("안녕하세여")); //글자쓰기

	//3. 선분 그리기
	dc.MoveTo(200,200); //시작점 위치 기억
	dc.LineTo(300,400);
	dc.LineTo(400,200);


	// 4.select object(GDI객체) : 선의 색(CPen), 면의 색(CBrush), 글꼴(CFont) 바꾸기 
	// SelectObject 사용 :  Bitmap, Pen, Brush, Font --> select object 먼저하고 도형,선을 그린다.!!!
	
	// 4-1. CPen
	CPen pen(PS_SOLID, 3, RGB(0,0,255)); //PS_DOT : 점선, PS_DASH : dash선
										//(선종류, 굵기, 색)
	dc.SelectObject(pen);
	
	// 4-2. CBrush
	//CBrush brush(RGB(255,0,0)); //기본 색입히기
	CBrush brush(HS_DIAGCROSS,RGB(255,0,0)); //x형태 빗금 색입히기
	dc.SelectObject(brush);
	dc.Rectangle(400,400,500,500);

	// 4-3. CFont
	CFont font; // 글씨체 
	font.CreatePointFont(150,_T("궁서체"));

	dc.SelectObject(font);
	dc.TextOutW(0,0,_T("궁서체입니다.")); //글자쓰기

	// 4-4. CPoint정의 후 -> CRgn (다각형) -> SelectStockObject
	//ex1) 삼각형
	CPoint pt[3];
	
	pt[0] = CPoint(500,100);
	pt[1] = CPoint(600,200);
	pt[2] = CPoint(400,200); // 점 정의 후,

	CRgn rgn;
	rgn.CreatePolygonRgn(pt, 3, WINDING); // 다각형 생성 후,
							//WINDING : 겹치는 부분이 있으면 덧칠함
							//ALTERNATE : 겹치는 부분이 있으면 빈공간으로
	dc.SelectStockObject(BLACK_BRUSH);
	dc.PaintRgn(&rgn); // 마지막 그려주기


	// 4-5. CBitmap(불러오기) -> BITMAP(정보출력하기)   이건 그냥 외우기!!!!!!
	// ex1) 한점씩 brush에 맵핑하는 방법 (사이즈 변경 x) -> 바둑판식
	CBitmap bmp;
	bmp.LoadBitmapW(IDB_BITMAP1); // 불러오기
	
	BITMAP bmpInfo; // bitmap 정보 출력하기
	bmp.GetBitmap(&bmpInfo);
	
	int w = bmpInfo.bmWidth;
	int h = bmpInfo.bmHeight;

	CString str; // mfc에서의 문자열 데이터 타입 : CString
	str.Format(_T("bitmap 크기 => w=%d, h=%d"),w,h); // Format 메소드 : printf와 똑같은 기능
	dc.TextOutW(600,600, str); // 글씨 출력

	//다각형 만들고 거기에 bmp입히기
	const int num = 10;
	int radius = 100; // 반지름
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


	//ex2) 한꺼번에 맵핑 (사이즈 변경 o) -> cover도 가능
	/*
	1. 메모리DC 만들기 (CreateCompatibleDC)
	2. 그림그릴 메모리 만들기 (CreateCompatibleBitmap)
	3. DC와 Bitmap을 연결 (SelectObject)
	4. 그림 그리기
	5. 그려진 그림을 화면DC로 BitBlt */	

	//CRect rectBmp;
	////GetClientRect(&rectBmp); // 만약 창 전체에 하고 싶다면??
	////rectBmp.SetRect(600,300,700,400);
	//
	//// 가상의 디바이스 컨택트를 하나 더 만든다.
	//CDC memDC;
	//memDC.CreateCompatibleDC(&dc); // 1. 메모리DC 만들기 

	//CBitmap bitmap;
	//bitmap.CreateCompatibleBitmap(&dc,rectBmp.Width(),rectBmp.Height()); //2. 그림그릴 메모리 만들기 -> bmp를 사각형 크기만큼 만들기
	//memDC.SelectObject(&bitmap); //3. DC와 Bitmap을 연결
	//memDC.Rectangle(600,300,700,400);

	//dc.BitBlt(600,300,rectBmp.Width(),rectBmp.Height(),&memDC,600,300,SRCCOPY);
	


	// 거미줄 치기 예제
	float div = 30; //줄개수
	float width = r.right - r.left; // 창 가로 길이
	float height = r.bottom - r.top; // 창 세로 길이

	float dw = width/div; // 줄간 간격
	float dh = height/div;

	for(int i=0;i<div;i++) 
	{
		dc.MoveTo(0,i*dh); // 세로 줄 간격 만큼 계속 그림
		dc.LineTo(i*dw,r.bottom);
	}
	for(int i=0;i<div;i++) 
	{
		dc.MoveTo(i*dw,0); // 세로 줄 간격 만큼 계속 그림
		dc.LineTo(r.right,i*dh);
	}




}


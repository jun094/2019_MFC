
// ChildView.cpp : CChildView 클래스의 구현
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

	// 예제 3)
	dc.TextOutW(100,200,_T("世種대학교")); // MFC에서는 모든 String은 _T로 묶는다..!
	dc.SetTextColor(RGB(255,0,0)); //글씨 색 빨강
	//dc.SetBkColor(RGB(255,0,0)); // 글씨 배경 색
	dc.SetBkMode(TRANSPARENT); // 글씨 배경색 투명
	
	// 예제 4) 펜 속성 변경
	CPen pen(PS_SOLID, 3, RGB(0,0,255)); // PenStyle을 solid로 3? 파랑색
	dc.SelectObject(pen);

	// 예제 5) 브러쉬 속성 변경
	CBrush brush(HS_DIAGCROSS, RGB(0,255,0));
	dc.SelectObject(brush);
	dc.Rectangle(100,100,200,200);

	CRect r;
	GetClientRect(r);
	r.left;
	r.top;
	r.right;
	r.bottom;

	// 예제 1)
	/*
	dc.Ellipse(r.left,r.top,r.right,r.bottom); // 타원형 그림

	dc.MoveTo(100,100);
	dc.LineTo(200,100); // 한붓 그리기 (100,100) ~ (200,100)
	dc.LineTo(200,200); // 200,100 ~ (200,200) 
	// 총 직선 2개
	*/

	// 예제2) S45
	
	float div = 30; //줄개수
	float width = r.right - r.left;
	float height = r.bottom - r.top;

	float dw = width/div;
	float dh = height/div;

	for(int i=0;i<div;i++)
	{
		dc.MoveTo(0,dh*i);
		dc.LineTo(i*dw, r.bottom);
	}

	// 예제 6) 폰트 속성 변경
	CFont font;
	font.CreatePointFont(400,_T("궁서체"));
	dc.SelectObject(font);


	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	//dc.RectANGLE(100,100,200,200);
	/*for(int i=0;i<10;i++)
	{
		int x1=100+i*10;
		int y1=100+i*10;
		int x2=300+i*10;
		int y2=300+i*10;
	}*/
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



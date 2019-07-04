
// ChildView.cpp : CChildView 클래스의 구현
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
	//연습문제 1 ppt23 : 선그리기 
	//헤더파일 멤버변수에서 선언해준 x,y좌표를 생성자에서 초기화 해준다. 
	//그런데,, CPoint도 클래스이다. 그럼 childview 의 생성자가 불릴때, cpoint 생성자도 불릴 것이다.
	//그럼 cpoint 생성자도 만들어주어야 하는데,, 애가 default 생성자가 안 만들어져 있다면???
	// 위에 처럼 {} 오기 직전에 선언 해주면된다..!!!!
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

//mouse & key
void CChildView::OnPaint() 
{
	CPaintDC dc(this); // childe view에서 받은거

	
	CRect rect;
	GetClientRect(rect);
	int w= rect.Width();
	int h = rect.Height();//rect.Width(),rect.Height(): 현재 화면의 크기

	CDC memDC; //   내가 맨땅에 만들기 -> 속도 향상
	memDC.CreateCompatibleDC(&dc);
	CBitmap bmp;
	bmp.CreateCompatibleBitmap(&dc,w,h); //rect.Width(),rect.Height(): 현재 화면의 크기
	memDC.SelectObject(bmp);

	/*
	for(int x=0;x<256;x++)
		for(int y=0;y<256;y++)
			//dc.SetPixelV(x,y,RGB(x,0,y)); //서로 다른 위치에 서로 다른 색 출력
			memDC.SetPixelV(x,y,RGB(x,0,y)); // 빠르게 그리기
	dc.BitBlt(0,0,w,h,&memDC,0,0,SRCCOPY);
	*/


	//연습문제 1 ppt23 : 선그리기
	memDC.Rectangle(0,0,w,h); // 배경 하얀색으로 채우기
	memDC.MoveTo(m_pt1);
	memDC.MoveTo(m_pt2);
}


//이벤트 등록하기 : childview -> 속성 -> 메세지 -> WM_ERASEBKGND 를 ADD 하기
//함수 이름(밑에있는거), 함수 모양(헤더파일에 afx_msg), 함수호출(BEGIN_MESSAGE_MAP) 총 3개가 추가 됨 
BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{

	return true; // 그냥 이렇게 하는거.. 무조건 써주자..!
}

typedef float STLSOO; // STLSOO : 실수?

//마우스 왼쪽 클릭하면 발생하는 이벤트
void CChildView::OnLButtonDown(UINT nFlags, CPoint point) 
	// UINT nFlags, CPoint point: 왼쪽 클릭했을 때 담기는 정보들(flag:뭘클릭했는지,point:좌표)
{
	/*
	//예제1 단순 텍스트 출력
	//MessageBox(_T("왼쪽 클릭!"));
	
	//예제2 좌표 출력
	CString str;
	str.Format(_T("x=%d, y=%d, flag=%d"), point.x,point.y,nFlags); // str.format : printf
	MessageBox(str);

	// <nFlags> 1, 2, 4, 8, 16, 32, 64, ...
	//          L  R  Sh Ct Mid .... --> shift + ctrl + L 클릭하면? = 13!!

	//예제3 : 왼쪽, CTRL 동시 클릭했을 때만
	if(nFlags==(MK_LBUTTON + MK_CONTROL))
	{
		CString str;
		str.Format(_T("x=%d, y=%d, flag=%d"), point.x,point.y,nFlags);
		MessageBox(str);
	}
	*/

	//연습문제 1 ppt23 : 선그리기
	m_pt1=point;
	SetCapture(); // 화면 밖으로 나갔을때 

	CWnd::OnLButtonDown(nFlags, point);
}

//연습문제 1 ppt23 : 선그리기 
void CChildView::OnLButtonUp(UINT nFlags, CPoint point) // 끝나는 점을 기억해서 아까 시작점과 이어
{
	m_pt2=point; // 끝점일떄
	
	Invalidate(); // 다시 그려줘 ( invalidate : 무효화 )

	CWnd::OnLButtonUp(nFlags, point);
	
	ReleaseCapture(); // 화면 밖으로 나갔을때 
}

// 마우스가 움직일때마다 계속 불리게 하고 싶다면
void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	//if(nFlags == MK_LBUTTON) // L버튼이 눌르면서 마우스를 움직인다면
	if((nFlags & MK_LBUTTON) == MK_LBUTTON) // 위에처럼 안쓰고 이렇게 써,, 그냥 그래
	{
		m_pt2 = point;
		Invalidate();
	}

	CWnd::OnMouseMove(nFlags, point);

}

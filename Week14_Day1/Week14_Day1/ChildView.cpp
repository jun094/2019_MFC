
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "Week14_Day1.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
	:m_pt(100,100), m_size(100), m_time(0)
{
	
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_KEYDOWN()
	ON_WM_CHAR()
	ON_WM_TIMER()
	ON_WM_CREATE()
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
	CPaintDC dc(this); 

	dc.Rectangle(m_pt.x-m_size/2, m_pt.y-m_size/2, m_pt.x+m_size/2, m_pt.y+m_size/2); 
	// 사각형 중심부터 그림 그리기

	dc.TextOutW(0,0,m_str);

	CString time; // 타이머 기능 구현
	time.Format(_T("%f"),m_time);
	dc.TextOutW(0,20,time);
}

//키보드를 눌려 사각형을 움직이게 !!
void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	TRACE("%d %d %d",nChar, nRepCnt, nFlags);  // TRACE : console.log같은거!!
											   // nChar이 키보드 눌릴때마다 다른값을 출력하는 것을 알 수 있음

	switch(nChar)
	{
	case VK_UP:
		m_pt.y-=10;
		break;
	case VK_DOWN:
		m_pt.y+=10;
		break;
	case VK_LEFT:
		m_pt.x-=10;
		break;
	case VK_RIGHT:
		m_pt.x+=10;
		break;
	case 'A': // 알파벳 a누르면 사각형 크기 증가
		m_size += 10;
		break;
	case 'Z': // 알파벳 z누르면 사각형 크기 감소
		m_size -= 10;
		break;
	case VK_SPACE: // 스페이스키 누르면 타이머 시작
		SetTimer(0,10,NULL); // 0.01초
		break;
	case VK_RETURN: // 엔터키 누르면 타이머 종료
		KillTimer(0);
		break;

	default:
		break;
	}

	// 키보드 누를때마다 글씨를 출력
	// char -> 1byte   <-> UNICODE CHAR -> 2byte
	//m_str += TCHAR(nChar); // TCHAR : 유니코드로 바꾸는 함수( 배열로 )
						     // 근데 이거는 문제가 대문자만 출력함..! 그래서 밑에 onChar 메소드!!
	Invalidate(); 
	
	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}

// 키보드 누를때마다 글씨를 출력
void CChildView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if(nChar== VK_BACK) // onChar는 백스페이스 기능 없음 !! 직접 구현
		m_str.Delete(m_str.GetLength()-1, 1); //Delete(a,b) : a부터 b까지 지운다
	else
		m_str += TCHAR(nChar);

	CWnd::OnChar(nChar, nRepCnt, nFlags);
}

// 타이머 기능 구현
void CChildView::OnTimer(UINT_PTR nIDEvent) //nIDEvent : 타이머마다 아이디값 생성 -> 여러개 생성이 가능하다.
											// 여기서는 SetTimer(0,100,NULL); -> id값 '0'번 타이머 1개 생성했음
{
	static int dsize =1;
	static int dx = 10;
	static int dy = 10;
	if(nIDEvent == 0 )
	{
		m_size += dsize;
		if(m_size > 200) dsize = -dsize; // 200보다 크면 크기가 1씩 감소
		if(m_size < 0) dsize = -dsize; // 0보다 작으면 크기가 1씩 감소
		Invalidate();
	}

	if(nIDEvent == 1) // 타이머 기능 구현
	{
		m_time+=0.01;

		CRect rect;
		GetClientRect(rect);
		
		m_pt.x += dx;
		m_pt.y += dy; // 시간마다 좌표를 최신화 해주어 애니매이션 기능 구현


		//////////////////////////// 애니메이션 조건 (벽튕기기)
		if(m_pt.x+m_size/2 > rect.right) dx = -dx;
		if(m_pt.y+m_size/2 > rect.bottom) dy = -dy;
		if(m_pt.x-m_size/2 < rect.left) dx = -dx;
		if(m_pt.y-m_size/2 < rect.top) dy = -dy;
		/////////////////////////////////////////////////////


		Invalidate();
	}


	CWnd::OnTimer(nIDEvent);
}


int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	SetTimer(1,10,NULL); // 타이머 초기화 : 생성자에서 해주지 않고 여기서 해줌
						 // OnCreate : mainframe에 있는거 -> 최초에?생성해줘야함.

	return 0;
}

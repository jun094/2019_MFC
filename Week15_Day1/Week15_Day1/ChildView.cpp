
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "Week15_Day1.h"
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
	ON_WM_CREATE()
	ON_BN_CLICKED(101,OnPushButton) // 버튼을 누르면 OnPushButton함수를 발생시킴
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
	
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	m_button.Create(_T("push me"), WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON, 
					CRect(0,0,100,100),this,101);
	// push me라는 텍스트를 가진 pushbutton형식의 사각형 (0,0,100,100)만큼의 공간을 가지는 101번이라는 id를 가짐
	// WS_VISIBLE : 를 하면 SHOWWINDOW안해줘도됨 ( | 는 and개념)
	//m_button.ShowWindow(true); //m_button의 기복속성은 안보여진다임-> true로 바꾸어줘야 보여짐
	
	//m_button2.Create(_T("push me"), WS_CHILD|WS_VISIBLE|BS_AUTOCHECKBOX, 
	//				CRect(200,200,200,200),this,102);

	m_edit.Create(WS_CHILD|WS_VISIBLE|ES_LEFT|ES_AUTOHSCROLL,
				  CRect(0,100,100,200), this,103);
	return 0;
}
void CChildView::OnPushButton() // button누르면 발생하는 함수
{
	m_button.MoveWindow(100,100,50,50);//MoveWindow: 움직이는거


}
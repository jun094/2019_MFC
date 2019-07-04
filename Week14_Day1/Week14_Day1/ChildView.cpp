
// ChildView.cpp : CChildView Ŭ������ ����
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
	CPaintDC dc(this); 

	dc.Rectangle(m_pt.x-m_size/2, m_pt.y-m_size/2, m_pt.x+m_size/2, m_pt.y+m_size/2); 
	// �簢�� �߽ɺ��� �׸� �׸���

	dc.TextOutW(0,0,m_str);

	CString time; // Ÿ�̸� ��� ����
	time.Format(_T("%f"),m_time);
	dc.TextOutW(0,20,time);
}

//Ű���带 ���� �簢���� �����̰� !!
void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	TRACE("%d %d %d",nChar, nRepCnt, nFlags);  // TRACE : console.log������!!
											   // nChar�� Ű���� ���������� �ٸ����� ����ϴ� ���� �� �� ����

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
	case 'A': // ���ĺ� a������ �簢�� ũ�� ����
		m_size += 10;
		break;
	case 'Z': // ���ĺ� z������ �簢�� ũ�� ����
		m_size -= 10;
		break;
	case VK_SPACE: // �����̽�Ű ������ Ÿ�̸� ����
		SetTimer(0,10,NULL); // 0.01��
		break;
	case VK_RETURN: // ����Ű ������ Ÿ�̸� ����
		KillTimer(0);
		break;

	default:
		break;
	}

	// Ű���� ���������� �۾��� ���
	// char -> 1byte   <-> UNICODE CHAR -> 2byte
	//m_str += TCHAR(nChar); // TCHAR : �����ڵ�� �ٲٴ� �Լ�( �迭�� )
						     // �ٵ� �̰Ŵ� ������ �빮�ڸ� �����..! �׷��� �ؿ� onChar �޼ҵ�!!
	Invalidate(); 
	
	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}

// Ű���� ���������� �۾��� ���
void CChildView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if(nChar== VK_BACK) // onChar�� �齺���̽� ��� ���� !! ���� ����
		m_str.Delete(m_str.GetLength()-1, 1); //Delete(a,b) : a���� b���� �����
	else
		m_str += TCHAR(nChar);

	CWnd::OnChar(nChar, nRepCnt, nFlags);
}

// Ÿ�̸� ��� ����
void CChildView::OnTimer(UINT_PTR nIDEvent) //nIDEvent : Ÿ�̸Ӹ��� ���̵� ���� -> ������ ������ �����ϴ�.
											// ���⼭�� SetTimer(0,100,NULL); -> id�� '0'�� Ÿ�̸� 1�� ��������
{
	static int dsize =1;
	static int dx = 10;
	static int dy = 10;
	if(nIDEvent == 0 )
	{
		m_size += dsize;
		if(m_size > 200) dsize = -dsize; // 200���� ũ�� ũ�Ⱑ 1�� ����
		if(m_size < 0) dsize = -dsize; // 0���� ������ ũ�Ⱑ 1�� ����
		Invalidate();
	}

	if(nIDEvent == 1) // Ÿ�̸� ��� ����
	{
		m_time+=0.01;

		CRect rect;
		GetClientRect(rect);
		
		m_pt.x += dx;
		m_pt.y += dy; // �ð����� ��ǥ�� �ֽ�ȭ ���־� �ִϸ��̼� ��� ����


		//////////////////////////// �ִϸ��̼� ���� (��ƨ���)
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

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	SetTimer(1,10,NULL); // Ÿ�̸� �ʱ�ȭ : �����ڿ��� ������ �ʰ� ���⼭ ����
						 // OnCreate : mainframe�� �ִ°� -> ���ʿ�?�����������.

	return 0;
}

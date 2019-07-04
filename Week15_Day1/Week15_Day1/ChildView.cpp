
// ChildView.cpp : CChildView Ŭ������ ����
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
	ON_BN_CLICKED(101,OnPushButton) // ��ư�� ������ OnPushButton�Լ��� �߻���Ŵ
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
	
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	
	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.
}



int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	m_button.Create(_T("push me"), WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON, 
					CRect(0,0,100,100),this,101);
	// push me��� �ؽ�Ʈ�� ���� pushbutton������ �簢�� (0,0,100,100)��ŭ�� ������ ������ 101���̶�� id�� ����
	// WS_VISIBLE : �� �ϸ� SHOWWINDOW�����൵�� ( | �� and����)
	//m_button.ShowWindow(true); //m_button�� �⺹�Ӽ��� �Ⱥ���������-> true�� �ٲپ���� ������
	
	//m_button2.Create(_T("push me"), WS_CHILD|WS_VISIBLE|BS_AUTOCHECKBOX, 
	//				CRect(200,200,200,200),this,102);

	m_edit.Create(WS_CHILD|WS_VISIBLE|ES_LEFT|ES_AUTOHSCROLL,
				  CRect(0,100,100,200), this,103);
	return 0;
}
void CChildView::OnPushButton() // button������ �߻��ϴ� �Լ�
{
	m_button.MoveWindow(100,100,50,50);//MoveWindow: �����̴°�


}
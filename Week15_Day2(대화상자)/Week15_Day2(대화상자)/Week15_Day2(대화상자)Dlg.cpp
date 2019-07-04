
// Week15_Day2(대화상자)Dlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "Week15_Day2(대화상자).h"
#include "Week15_Day2(대화상자)Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWeek15_Day2대화상자Dlg 대화 상자




CWeek15_Day2대화상자Dlg::CWeek15_Day2대화상자Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CWeek15_Day2대화상자Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWeek15_Day2대화상자Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK1, m_check1);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
}

BEGIN_MESSAGE_MAP(CWeek15_Day2대화상자Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CHECK1, &CWeek15_Day2대화상자Dlg::OnBnClickedCheck1)
	ON_EN_CHANGE(IDC_EDIT1, &CWeek15_Day2대화상자Dlg::OnEnChangeEdit1)
	ON_EN_SETFOCUS(IDC_EDIT1, &CWeek15_Day2대화상자Dlg::OnEnSetfocusEdit1)
END_MESSAGE_MAP()


// CWeek15_Day2대화상자Dlg 메시지 처리기

BOOL CWeek15_Day2대화상자Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CWeek15_Day2대화상자Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CWeek15_Day2대화상자Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CWeek15_Day2대화상자Dlg::OnBnClickedCheck1()
{
	
	if(m_check1.GetCheck()==false)
		m_check1.SetCheck(true);
	else
		m_check1.SetCheck(false);
}


void CWeek15_Day2대화상자Dlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CWeek15_Day2대화상자Dlg::OnEnSetfocusEdit1()
{
	m_edit.SetWindowTextW(_T("")); // FOCUS 나갔다 오면 빈칸으로
}

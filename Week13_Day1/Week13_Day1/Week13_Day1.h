
// Week13_Day1.h : Week13_Day1 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CWeek13_Day1App:
// �� Ŭ������ ������ ���ؼ��� Week13_Day1.cpp�� �����Ͻʽÿ�.
//

class CWeek13_Day1App : public CWinApp
{
public:
	CWeek13_Day1App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CWeek13_Day1App theApp;

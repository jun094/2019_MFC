
// Week13_Day2.h : Week13_Day2 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CWeek13_Day2App:
// �� Ŭ������ ������ ���ؼ��� Week13_Day2.cpp�� �����Ͻʽÿ�.
//

class CWeek13_Day2App : public CWinApp
{
public:
	CWeek13_Day2App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CWeek13_Day2App theApp;

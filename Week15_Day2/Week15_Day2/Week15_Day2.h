
// Week15_Day2.h : Week15_Day2 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CWeek15_Day2App:
// �� Ŭ������ ������ ���ؼ��� Week15_Day2.cpp�� �����Ͻʽÿ�.
//

class CWeek15_Day2App : public CWinAppEx
{
public:
	CWeek15_Day2App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CWeek15_Day2App theApp;


// Week15_Day2(��ȭ����).h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CWeek15_Day2��ȭ����App:
// �� Ŭ������ ������ ���ؼ��� Week15_Day2(��ȭ����).cpp�� �����Ͻʽÿ�.
//

class CWeek15_Day2��ȭ����App : public CWinApp
{
public:
	CWeek15_Day2��ȭ����App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CWeek15_Day2��ȭ����App theApp;
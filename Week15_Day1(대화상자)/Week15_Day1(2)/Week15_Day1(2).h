
// Week15_Day1(2).h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CWeek15_Day12App:
// �� Ŭ������ ������ ���ؼ��� Week15_Day1(2).cpp�� �����Ͻʽÿ�.
//

class CWeek15_Day12App : public CWinApp
{
public:
	CWeek15_Day12App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CWeek15_Day12App theApp;
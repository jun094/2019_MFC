
// ex0115.h : ex0115 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cex0115App:
// �� Ŭ������ ������ ���ؼ��� ex0115.cpp�� �����Ͻʽÿ�.
//

class Cex0115App : public CWinApp
{
public:
	Cex0115App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cex0115App theApp;

#pragma once
#include "myshape.h"
class CMyRect :
	public CMyShape
{
public:
	CMyRect(void);
	~CMyRect(void);
	CPoint m_pt;
	int m_w;
	int m_h;
};


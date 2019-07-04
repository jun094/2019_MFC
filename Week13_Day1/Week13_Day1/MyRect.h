#pragma once
#include "myshape.h"
class CMyRect :
	public CMyShape
{
public:
	CMyRect(void);
	CMyRect(CPoint pt, int w=0, int h=0);
	~CMyRect(void);

	CPoint m_pt;
	int m_w; 
	int m_h;

	void draw(CDC &dc);
	void setMouseDown(CPoint pt);
	void setMouseUp(CPoint pt);
	void setMouseMove(CPoint pt);
};


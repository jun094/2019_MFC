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

	virtual void draw(CDC & dc);
	virtual void setMouseDown(CPoint pt);
	virtual void setMouseUp(CPoint pt);
	virtual void setMouseMove(CPoint pt);

};


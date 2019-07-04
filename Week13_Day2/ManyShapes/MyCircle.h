#pragma once
#include "myshape.h"
class CMyCircle :
	public CMyShape
{
public:
	CMyCircle(void);
	~CMyCircle(void);
	CPoint m_ct;
	float m_r;

	virtual void draw(CDC & dc);
	virtual void setMouseDown(CPoint pt);
	virtual void setMouseUp(CPoint pt);
	virtual void setMouseMove(CPoint pt);

};


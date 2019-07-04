#pragma once
#include "myshape.h"
class CMyCurve :
	public CMyShape
{
public:
	CMyCurve(void);
	~CMyCurve(void);
	
	//°î¼± ±×¸®±â
	CList <CPoint> m_pts;

	virtual void draw(CDC & dc);
	virtual void setMouseDown(CPoint pt);
	virtual void setMouseUp(CPoint pt);
	virtual void setMouseMove(CPoint pt);
};


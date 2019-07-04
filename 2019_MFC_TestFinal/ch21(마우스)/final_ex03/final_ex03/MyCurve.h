#pragma once
#include "myshape.h"
class CMyCurve :
	public CMyShape
{
public:
	CMyCurve(void);
	~CMyCurve(void);

	CList<CPoint> m_pts;

	void draw(CDC &dc);
	void setMouseDown(CPoint pt);
	void setMouseUp(CPoint pt);
	void setMouseMove(CPoint pt);
};


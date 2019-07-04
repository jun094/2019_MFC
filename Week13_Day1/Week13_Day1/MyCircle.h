#pragma once
#include "myshape.h"
class CMyCircle :
	public CMyShape
{
public:
	CMyCircle(void);
	~CMyCircle(void);

	CPoint m_center; // ¿ø Áß½É
	float m_radius;

	void draw(CDC &dc);
	void setMouseDown(CPoint pt);
	void setMouseUp(CPoint pt);
	void setMouseMove(CPoint pt);
};


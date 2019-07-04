#pragma once
class CMyShape
{
public:
	CMyShape(void);
	~CMyShape(void);

	COLORREF m_color;
	CBrush m_brush;
	CPen m_pen;

	virtual void draw(CDC &dc);
	virtual void setMouseDown(CPoint pt) {};
	virtual void setMouseUp(CPoint pt){};
	virtual void setMouseMove(CPoint pt){};
};


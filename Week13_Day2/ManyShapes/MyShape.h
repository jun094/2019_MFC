#pragma once
class CMyShape
{
public:
	enum {RECT, CIRCLE, CURVE};
	static const int NUM_SHAPES; // 모양은 3가지 있어

	CMyShape(void);
	~CMyShape(void);
	
	COLORREF m_color;

	virtual void draw(CDC & dc);
	virtual void setMouseDown(CPoint pt) = 0;
	virtual void setMouseUp(CPoint pt){};
	virtual void setMouseMove(CPoint pt){};

};


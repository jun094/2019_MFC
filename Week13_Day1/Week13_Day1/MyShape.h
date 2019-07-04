#pragma once
class CMyShape
{
public:
	enum {RECT,CIRCLE}; // enum = define

	CMyShape(void);
	~CMyShape(void);

	COLORREF m_color;

	virtual void draw(CDC &dc) = 0;
	virtual void setMouseDown(CPoint pt) = 0; // 반드시 구현해야함 -> 반드시 클릭은 해야함 
	virtual void setMouseUp(CPoint pt) {}; // 마우스 안 때도 됨
	virtual void setMouseMove(CPoint pt){}; // 마우스 드래그 안해도 됨
};


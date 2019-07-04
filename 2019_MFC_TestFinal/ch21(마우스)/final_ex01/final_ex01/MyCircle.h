#pragma once
class CMyCircle
{
public:
	CMyCircle(void);
	~CMyCircle(void);

	CPoint m_center; // 중심
	float m_r; // 반지름 무조건 50
	float m_radius; 
	COLORREF m_color;
	CBrush m_brush;

	void draw(CDC &dc);

	void setMouseDown(CPoint pt, int mode, bool flag, float preR);
	void setMouseUp(CPoint pt);
	void setMouseMove(CPoint pt);

	void separte(CPoint pt);
	bool InPoint(CPoint pt);

	float getR();
	CPoint getPreCenter();
};
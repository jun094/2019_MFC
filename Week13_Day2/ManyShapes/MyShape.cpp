#include "StdAfx.h"
#include "MyShape.h"

const int CMyShape::NUM_SHAPES = 3;

CMyShape::CMyShape(void)
{
	int r = rand()%256;
	int g = rand()%256;
	int b = rand()%256;
	m_color = RGB(r,g,b);

	COLORREF pen_color;
	CPen m_pen;
	CBrush m_brush;

	pen_color = RGB(GetRValue(m_color)*0.8,
					GetGValue(m_color)*0.8,
					GetBValue(m_color)*0.8);

	m_pen.CreatePen(PS_SOLID, 3, m_color);
	m_brush.CreateSolidBrush(m_color);
}


CMyShape::~CMyShape(void)
{
}

void CMyShape::draw(CDC & dc)
{
	dc.SelectObject(m_pen);
	dc.SelectObject(m_brush);
}
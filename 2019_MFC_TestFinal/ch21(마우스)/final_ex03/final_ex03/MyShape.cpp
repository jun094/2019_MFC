#include "StdAfx.h"
#include "MyShape.h"


CMyShape::CMyShape(void)
{
	int r = rand()%256;
	int g = rand()%256;
	int b = rand()%256;

	m_color = RGB(r,g,b);

	m_brush.CreateSolidBrush(m_color);
	m_pen.CreatePen(PS_SOLID,3,m_color);
}
CMyShape::~CMyShape(void)
{
}
void CMyShape::draw(CDC &dc)
{
	dc.SelectObject(m_brush);
	dc.SelectObject(m_pen);
}




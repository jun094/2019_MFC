#include "StdAfx.h"
#include "MyShape.h"


CMyShape::CMyShape(void)
{
	int r = rand()%256;
	int g = rand()%256;
	int b = rand()%256; // 색은 랜덤값

	m_color = RGB(r,g,b);

	//원, 사각형, 별 색 지정 --> CBrush
	m_brush.CreateSolidBrush(m_color);

	// 선 색 지정 --> CPen
	COLORREF pen_color;
	pen_color = RGB(GetRValue(m_color)*0.9,
					GetGValue(m_color)*0.9,
					GetBValue(m_color)*0.9); // 테두리 색은 좀 다르게 할려고
	m_pen.CreatePen(PS_SOLID,3,pen_color);
}


CMyShape::~CMyShape(void)
{
}

void CMyShape::draw(CDC & dc)
{
	dc.SelectObject(m_pen);
	dc.SelectObject(m_brush);
}
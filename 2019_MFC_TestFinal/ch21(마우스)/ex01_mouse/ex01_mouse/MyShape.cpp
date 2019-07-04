#include "StdAfx.h"
#include "MyShape.h"


CMyShape::CMyShape(void)
{
	int r = rand()%256;
	int g = rand()%256;
	int b = rand()%256; // ���� ������

	m_color = RGB(r,g,b);

	//��, �簢��, �� �� ���� --> CBrush
	m_brush.CreateSolidBrush(m_color);

	// �� �� ���� --> CPen
	COLORREF pen_color;
	pen_color = RGB(GetRValue(m_color)*0.9,
					GetGValue(m_color)*0.9,
					GetBValue(m_color)*0.9); // �׵θ� ���� �� �ٸ��� �ҷ���
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
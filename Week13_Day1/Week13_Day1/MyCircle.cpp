#include "StdAfx.h"
#include "MyCircle.h"
#include <math.h>

CMyCircle::CMyCircle(void)
	:m_center(0,0), m_radius(0)
{
}


CMyCircle::~CMyCircle(void)
{
}

void CMyCircle::draw(CDC &dc)
{
	CBrush brush(m_color);
	dc.SelectObject(brush);
	dc.Ellipse(m_center.x - m_radius, m_center.y - m_radius,
			   m_center.x + m_radius, m_center.y + m_radius); // �̰� ���� x
}
void CMyCircle::setMouseDown(CPoint pt)
{
	m_center = pt; // ù��° �� Ŭ�������� �̰� �߽�
}
void CMyCircle::setMouseUp(CPoint pt)
{
	float dist2 = (m_center.x-pt.x)*(m_center.x-pt.x)
				  +(m_center.y-pt.y)*(m_center.y-pt.y);
	m_radius = sqrt(dist2);
}
void CMyCircle::setMouseMove(CPoint pt)
{

}

#include "StdAfx.h"
#include "MyCircle.h"
#include <math.h>

CMyCircle::CMyCircle(void)
	: m_center(0,0), m_r(0)
{
}


CMyCircle::~CMyCircle(void)
{
}

void CMyCircle::draw(CDC &dc)
{
	CMyShape::draw(dc);

	//�׸� �׸���
	dc.Ellipse(m_center.x-m_r, m_center.y-m_r, 
		m_center.x+m_r, m_center.y+m_r);

}

void CMyCircle::setMouseDown(CPoint pt) // ���콺 Ŭ���ϸ�
{
	m_center = pt;
}
void CMyCircle::setMouseUp(CPoint pt)
{
	float dist2 = (m_center.x-pt.x)*(m_center.x-pt.x)
				  +(m_center.y-pt.y)*(m_center.y-pt.y); 
	m_r = sqrt(dist2);
}
void CMyCircle::setMouseMove(CPoint pt)
{
	setMouseUp(pt);
}

#include "StdAfx.h"
#include "MyCircle.h"


CMyCircle::CMyCircle(void) : m_ct(0,0), m_r(0)
{
}


CMyCircle::~CMyCircle(void)
{
}

void CMyCircle::draw(CDC & dc)
{
	CMyShape::draw(dc);
	
	dc.Ellipse(m_ct.x-m_r, m_ct.y-m_r,
		       m_ct.x+m_r, m_ct.y+m_r);
}
void CMyCircle::setMouseDown(CPoint pt)
{
	m_ct = pt;
}
#include <cmath>
void CMyCircle::setMouseUp(CPoint pt)
{
	float dist2 = (m_ct.x-pt.x)*(m_ct.x-pt.x)
		         +(m_ct.y-pt.y)*(m_ct.y-pt.y);
	m_r = sqrt(dist2);
}
void CMyCircle::setMouseMove(CPoint pt)
{
	setMouseUp(pt);
}


#include "StdAfx.h"
#include "MyCircle.h"
#include <math.h>

CMyCircle::CMyCircle(void)
	:m_r(50)
{
	int r = rand()%256;
	int g = rand()%256;
	int b = rand()%256;
	m_color = RGB(r,g,b);
	
	m_brush.CreateSolidBrush(m_color);
}
CMyCircle::~CMyCircle(void)
{
}

void CMyCircle::draw(CDC &dc)
{
	dc.SelectObject(m_brush);
	dc.Ellipse(m_center.x-m_r,m_center.y-m_r,
			   m_center.x+m_r,m_center.y+m_r);
}

void CMyCircle::setMouseDown(CPoint pt, int mode, bool flag, float preR)
{
	if(mode == 0)
	{
		m_center = pt;
	}
	else if(mode == 2)
	{
		if(flag == true)
		{
			m_r = preR/2;
			m_center.x = pt.x-m_r;
			m_center.y = pt.y+m_r;
			flag = false;
		}
		else
		{
			m_r = preR/2;
			m_center.x = pt.x+m_r;
			m_center.y = pt.y-m_r;
			flag = true;
		}
	}
}
void CMyCircle::setMouseUp(CPoint pt)
{
	
}
void CMyCircle::setMouseMove(CPoint pt)
{
	CPoint movePt;
	movePt = pt;

	m_center = movePt;
}

void CMyCircle::separte(CPoint pt)
{
}
bool CMyCircle::InPoint(CPoint pt)
{	
	if((pt.x-m_center.x)*(pt.x-m_center.x) + 
		(-pt.y+m_center.y)*(-pt.y+m_center.y) <= 2500) // pt가 원 내에 있으면
	{
		return true;
	}
	else
	{
		return false;
	}
}
float CMyCircle::getR()
{
	return m_r;
}
CPoint  CMyCircle::getPreCenter()
{
	return m_center;
}
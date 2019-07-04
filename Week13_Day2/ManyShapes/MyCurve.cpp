#include "StdAfx.h"
#include "MyCurve.h"


CMyCurve::CMyCurve(void)
{
}


CMyCurve::~CMyCurve(void)
{
}
void CMyCurve::draw(CDC & dc)
{
	CPen pen(PS_SOLID, 3, m_color);
	dc.SelectObject(pen); // 선 종류

	POSITION pos = m_pts.GetHeadPosition();
	int ind = 0;
	while(pos != NULL)
	{
		CPoint pt = m_pts.GetNext(pos);
		if(ind == 0)
			dc.MoveTo(pt);
		else
			dc.LineTo(pt);
		ind++;
	}
}
void CMyCurve::setMouseDown(CPoint pt)
{
	m_pts.AddTail(pt); // 마우스 눌러도 뒤에 점 이어 붙이고
}
void CMyCurve::setMouseUp(CPoint pt)
{
	m_pts.AddTail(pt); // 마우스 뗴도 뒤에 점 이어 붙이고
}
void CMyCurve::setMouseMove(CPoint pt)
{
	m_pts.AddTail(pt); // 움직여도 뒤에 점 이어 붙이고
}
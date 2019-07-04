#include "StdAfx.h"
#include "MyCurve.h"


CMyCurve::CMyCurve(void)
{
}
CMyCurve::~CMyCurve(void)
{
}
void CMyCurve::draw(CDC &dc)
{

	CMyShape::draw(dc);

	POSITION pos = m_pts.GetHeadPosition();
	int ind=0;
	while(pos!=NULL)
	{
		CPoint pt = m_pts.GetNext(pos);
		if(ind==0)
			dc.MoveTo(pt);
		else
			dc.LineTo(pt);
		ind++;
	}
}
void CMyCurve::setMouseDown(CPoint pt)
{
	m_pts.AddTail(pt);
}
void CMyCurve::setMouseUp(CPoint pt)
{
	m_pts.AddTail(pt);
}
void CMyCurve::setMouseMove(CPoint pt)
{
	m_pts.AddTail(pt);
}
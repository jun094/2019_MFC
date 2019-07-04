#include "StdAfx.h"
#include "MyRect.h"


CMyRect::CMyRect(void)
{
}


CMyRect::~CMyRect(void)
{
}
void CMyRect::setMouseDown(CPoint pt)
{
	m_pt = pt;
}
void CMyRect::setMouseUp(CPoint pt)
{
	m_w = pt.x-m_pt.x;
	m_h = pt.x-m_pt.y;
}
void CMyRect::setMouseMove(CPoint pt)
{
	setMouseUp(pt);
}
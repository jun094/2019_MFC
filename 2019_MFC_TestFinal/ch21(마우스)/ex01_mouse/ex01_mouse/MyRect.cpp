#include "StdAfx.h"
#include "MyRect.h"


CMyRect::CMyRect(void)
	:m_pt(0,0), m_w(0), m_h(0)
{
}
CMyRect::CMyRect(CPoint pt, int w, int h)
	:m_pt(pt), m_w(w), m_h(h)
{
}
CMyRect::~CMyRect(void)
{
}


void CMyRect::draw(CDC &dc)
{
	/* 색지정 이겨서 할 필요없음 -> 모든 도형이 색칠하는것이 필요함 --> shpae에서 !
	CBrush brush(m_color);
	dc.SelectObject(brush); */

	CMyShape::draw(dc);

	//그림 그리기
	dc.Rectangle(m_pt.x, m_pt.y, m_pt.x+m_w, m_pt.y+m_h);
}

void CMyRect::setMouseDown(CPoint pt) // 마우스 클릭하면
{
	m_pt = pt;
}
void CMyRect::setMouseUp(CPoint pt)
{
	m_w = pt.x - m_pt.x; // 마우스 뗄 때 x좌표 - 마우스 클릭 했을때 x좌표
	m_h = pt.y - m_pt.y;

}
void CMyRect::setMouseMove(CPoint pt)
{
	setMouseUp(pt);
}
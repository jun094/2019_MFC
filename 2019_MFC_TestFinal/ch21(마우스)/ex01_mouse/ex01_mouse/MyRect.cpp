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
	/* ������ �̰ܼ� �� �ʿ���� -> ��� ������ ��ĥ�ϴ°��� �ʿ��� --> shpae���� !
	CBrush brush(m_color);
	dc.SelectObject(brush); */

	CMyShape::draw(dc);

	//�׸� �׸���
	dc.Rectangle(m_pt.x, m_pt.y, m_pt.x+m_w, m_pt.y+m_h);
}

void CMyRect::setMouseDown(CPoint pt) // ���콺 Ŭ���ϸ�
{
	m_pt = pt;
}
void CMyRect::setMouseUp(CPoint pt)
{
	m_w = pt.x - m_pt.x; // ���콺 �� �� x��ǥ - ���콺 Ŭ�� ������ x��ǥ
	m_h = pt.y - m_pt.y;

}
void CMyRect::setMouseMove(CPoint pt)
{
	setMouseUp(pt);
}
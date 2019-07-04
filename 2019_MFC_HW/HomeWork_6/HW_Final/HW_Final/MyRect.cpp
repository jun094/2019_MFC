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

void CMyRect::selectDraw(CDC &dc)
{
	dotRect.SetRect(m_rect.left-10, m_rect.top-10, m_rect.right+10, m_rect.bottom+10);
	CMyShape::selectDraw(dc);

	//���� �簢�� �׸���
	dc.Rectangle(dotRect);
}
void CMyRect::draw(CDC &dc)
{
	/* ������ �̰ܼ� �� �ʿ���� -> ��� ������ ��ĥ�ϴ°��� �ʿ��� --> shpae���� !
	CBrush brush(m_color);
	dc.SelectObject(brush); */
	m_rect.SetRect(m_pt.x, m_pt.y, m_pt.x+m_w, m_pt.y+m_h);

	CMyShape::draw(dc);

	//�׸� �׸���

	dc.Rectangle(m_rect);
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

void CMyRect::selectMouseMove(CPoint point)
{
	CPoint movePos;

	movePos.x = point.x-m_prePos.x;
	movePos.y = point.y-m_prePos.y;

	m_rect.left += movePos.x;
	m_rect.top +=  movePos.y;
	m_rect.right += movePos.x;
	m_rect.bottom +=  movePos.y;

	dotRect.left += movePos.x;
	dotRect.top +=  movePos.y;
	dotRect.right += movePos.x;
	dotRect.bottom +=  movePos.y;

	m_prePos = point;
}
int CMyRect::InPoint(CPoint pt)
{

	if(m_rect.PtInRect(pt))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void CMyRect::setPrePos(CPoint point)
{
	m_prePos = point;
}
#include "StdAfx.h"
#include "MyShape.h"


CMyShape::CMyShape(void)
{
	//선택했을 때 점선
	m_selectBool = false;
	dotPen.CreatePen(PS_DOT, 1, RGB(255,0,0));
	dotBrush.CreateSolidBrush(RGB(255,255,255));

	int r = rand()%256;
	int g = rand()%256;
	int b = rand()%256; // 색은 랜덤값
	
	// 면 색 지정 --> CBrush
	m_color = RGB(r,g,b);

	// 선 색 지정 --> CPen
	COLORREF pen_color;
	pen_color = RGB(GetRValue(m_color)*0.9,
					GetGValue(m_color)*0.9,
					GetBValue(m_color)*0.9); // 테두리 색은 좀 다르게 할려고

	//원, 사각형, 별 색 생성 --> CBrush
	m_brush.CreateSolidBrush(m_color);
	// 선 생성
	m_pen.CreatePen(PS_SOLID,3,pen_color);
}

CMyShape::~CMyShape(void)
{
}

void CMyShape::selectDraw(CDC & dc)
{
	dc.SelectObject(dotBrush);
	dc.SelectObject(dotPen); 
}
void CMyShape::draw(CDC & dc)
{
	dc.SelectObject(m_brush);
	dc.SelectObject(m_pen);
}


//void CMyShape::selectMouseMove(CPoint pt, CPoint prePt)
//{
//	CPoint cp(0,0);
//	return cp;
//}
int CMyShape::InPoint(CPoint pt)
{
	return 0;
}
void CMyShape::checkSelect()
{
	if(m_selectBool==false)
	{
		m_selectBool = true;
	}
	else
	{
		m_selectBool = false;
	}
}
bool CMyShape::getSelectBool()
{
	return m_selectBool;
}
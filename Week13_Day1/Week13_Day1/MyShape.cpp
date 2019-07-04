#include "StdAfx.h"
#include "MyShape.h"


CMyShape::CMyShape(void)
{
	int r = rand()%256;
	int g = rand()%256;
	int b = rand()%256;
	m_color = RGB(r,g,b); // 매번 색을 랜덤하게


}


CMyShape::~CMyShape(void)
{
}

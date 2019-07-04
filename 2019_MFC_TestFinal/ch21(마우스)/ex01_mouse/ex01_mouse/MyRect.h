#pragma once
#include "MyShape.h"
class CMyRect 
	: public CMyShape
{
public:
	CMyRect(void); // default 생성자
	CMyRect(CPoint pt, int w=0, int h=0);  //좌표가 설정 될 때
	~CMyRect(void);
	
	CPoint m_pt; // 사각형 좌표 설정
	int m_w;
	int m_h;
	
	void draw(CDC &dc);
	void setMouseDown(CPoint pt);
	void setMouseUp(CPoint pt);
	void setMouseMove(CPoint pt);
};


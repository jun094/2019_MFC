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
	CRect m_rect;
	
	int m_w;
	int m_h;

	//select했을때 기억해야할 좌표들
	CPoint dotPt;
	CRect dotRect;

	//mousemove 할 때 
	CPoint m_prePos;
	CPoint movePos;
	void selectDraw(CDC &dc);
	void draw(CDC &dc);
	void setMouseDown(CPoint pt);
	void setMouseUp(CPoint pt);
	void setMouseMove(CPoint pt);

	//void selectMouseDown(CPoint pt);
	void selectMouseMove(CPoint pt);
	int InPoint(CPoint pt);
	void setPrePos(CPoint point);
};


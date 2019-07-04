#pragma once
#include "MyShape.h"
class CMyRect 
	: public CMyShape
{
public:
	CMyRect(void); // default ������
	CMyRect(CPoint pt, int w=0, int h=0);  //��ǥ�� ���� �� ��
	~CMyRect(void);

	CPoint m_pt; // �簢�� ��ǥ ����
	CRect m_rect;
	
	int m_w;
	int m_h;

	//select������ ����ؾ��� ��ǥ��
	CPoint dotPt;
	CRect dotRect;

	//mousemove �� �� 
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


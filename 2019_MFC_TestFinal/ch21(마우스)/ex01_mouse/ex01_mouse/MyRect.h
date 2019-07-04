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
	int m_w;
	int m_h;
	
	void draw(CDC &dc);
	void setMouseDown(CPoint pt);
	void setMouseUp(CPoint pt);
	void setMouseMove(CPoint pt);
};


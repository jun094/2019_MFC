#pragma once
#include "myshape.h"
class CMyCircle :
	public CMyShape
{
public:
	CMyCircle(void);

	~CMyCircle(void);

	CPoint m_center; // �� �߽� ��ǥ ����
	float m_r; //������
	
	void draw(CDC &dc);
	void setMouseDown(CPoint pt);
	void setMouseUp(CPoint pt);
	void setMouseMove(CPoint pt);
};


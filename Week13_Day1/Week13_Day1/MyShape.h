#pragma once
class CMyShape
{
public:
	enum {RECT,CIRCLE}; // enum = define

	CMyShape(void);
	~CMyShape(void);

	COLORREF m_color;

	virtual void draw(CDC &dc) = 0;
	virtual void setMouseDown(CPoint pt) = 0; // �ݵ�� �����ؾ��� -> �ݵ�� Ŭ���� �ؾ��� 
	virtual void setMouseUp(CPoint pt) {}; // ���콺 �� ���� ��
	virtual void setMouseMove(CPoint pt){}; // ���콺 �巡�� ���ص� ��
};


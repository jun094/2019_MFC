#pragma once
class CMyShape
{
public:
	enum {RECT,CIRCLE,CURVE}; // enum = define

	CMyShape(void);
	~CMyShape(void);

	//�������� �� ����
	CPen dotPen;
	CBrush dotBrush;
	bool m_selectBool;
	///////////////

	COLORREF m_color;
	CPen m_pen;
	CBrush m_brush;	

	virtual void selectDraw(CDC &dc);
	virtual void draw(CDC &dc); // shpae������ �����Ҳ���

	virtual void setMouseDown(CPoint pt) = 0; // �ݵ�� �Ļ�Ŭ�������� �����ؾ��� -> �ݵ�� Ŭ���� �ؾ��� 
	virtual void setMouseUp(CPoint pt) {}; // ���콺 �� ���� �� -> ȭ�� �ۿ� ������ ���
	virtual void setMouseMove(CPoint pt){}; // ���콺 �巡�� ���ص� ��
	
	//virtual void selectMouseDown(CPoint pt){};
	virtual void selectMouseMove(CPoint pt){};
	virtual int InPoint(CPoint pt);
	virtual void setPrePos(CPoint point) {};
	void checkSelect();
	bool getSelectBool();

};


#pragma once
class CMyShape
{
public:
	enum {RECT,CIRCLE,CURVE}; // enum = define

	CMyShape(void);
	~CMyShape(void);

	//선택했을 때 변수
	CPen dotPen;
	CBrush dotBrush;
	bool m_selectBool;
	///////////////

	COLORREF m_color;
	CPen m_pen;
	CBrush m_brush;	

	virtual void selectDraw(CDC &dc);
	virtual void draw(CDC &dc); // shpae에서만 구현할꺼임

	virtual void setMouseDown(CPoint pt) = 0; // 반드시 파생클래스에서 구현해야함 -> 반드시 클릭은 해야함 
	virtual void setMouseUp(CPoint pt) {}; // 마우스 안 때도 됨 -> 화면 밖에 나가는 경우
	virtual void setMouseMove(CPoint pt){}; // 마우스 드래그 안해도 됨
	
	//virtual void selectMouseDown(CPoint pt){};
	virtual void selectMouseMove(CPoint pt){};
	virtual int InPoint(CPoint pt);
	virtual void setPrePos(CPoint point) {};
	void checkSelect();
	bool getSelectBool();

};


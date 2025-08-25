#pragma once

#include "shape.h"

class circle : public shape
{
private:
	Point MA;
	Point r;
	int radius;
public:
	circle(Point,Point,double radius, GfxInfo shapeGfxInfo);
	virtual ~circle();
	virtual void Draw(GUI* pUI) const;
	virtual string printforselection();
	bool is_in_fig(int x, int y);
	shape* copy();
	void Move(Point P1, Point P2);
	void Zoom(double factor);
	void Resize(double factor);

	void Rotate() ;

	void ChngDrawClr(color Dclr);
	



};





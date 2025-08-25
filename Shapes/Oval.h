#pragma once

#include "shape.h"



class oval : public shape
{
private:
	Point Corner1;
	Point Corner2;
public:
	oval(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~oval();
	virtual void Draw(GUI* pUI)const;
	virtual string printforselection();
	bool is_in_fig(int x, int y);
	shape* copy();
	void Move(Point P1, Point P2);
	void Zoom(double factor);

	void Resize(double factor);

	void Rotate();

	void ChngDrawClr(color Dclr);

};



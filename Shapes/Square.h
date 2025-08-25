#pragma once

#include "shape.h"




class square : public shape
{
private:
	Point Corner1;
	Point Corner2;
	
public:

	square(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~square();
	virtual void Draw(GUI* pUI) const;
	virtual string printforselection();
	bool is_in_fig(int x, int y);
	shape* copy();
	void Move(Point P1, Point P2);
	void Zoom(double factor);
	void Resize(double factor);
	Point CalculateCenter() const;
	void Rotate();
	void ChngDrawClr(color Dclr);
};

#pragma once

#include "shape.h"



class Tri : public shape
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
	Point CalculateCentroid() const;
	GfxInfo TriGfxInfo;
public:
	Tri(Point, Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Tri();
	virtual void Draw(GUI* pUI) const;
	virtual string printforselection();
	bool is_in_fig(int x, int y);
	shape* copy();
	void Move(Point P1, Point P2);
	void Zoom(double factor);
	void Resize(double factor);
	void Rotate();
	void ChngDrawClr(color Dclr);
};









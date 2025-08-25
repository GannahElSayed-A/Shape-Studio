#pragma once

#include "shape.h"


class regpoly : public shape
{
private:
	Point* POI; // Pointer to array of vertices
	int ivertices; // Number of vertices
	Point Center;
	int* ArrX = new int[2000];
	int* ArrY = new int[2000];
public:
	regpoly(Point* P1, int ivertices, GfxInfo shapeGfxInfo);
	virtual ~regpoly();
	virtual void Draw(GUI* pUI) const;
	virtual string printforselection();
	bool is_in_fig(int x, int y);
	shape* copy();
	void Move(Point P1, Point P2);
	void Resize(double factor);
	void Rotate();
	void ChngDrawClr(color Dclr);
};


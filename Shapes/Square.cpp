#include "Square.h"


square::square(Point P1, Point P2,GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}


square::~square()
{}

void square::Draw(GUI* pUI) const
{
	pUI->DrawRect(Corner1, Corner2, ShpGfxInfo);
}
bool square::is_in_fig(int x, int y) {
	if ((x > Corner1.x && x < Corner2.x && y > Corner1.y && y < Corner2.y))
	{
		return true;
	}
	else if ((x < Corner1.x && x > Corner2.x && y > Corner1.y && y < Corner2.y))
	{
		return true;
	}
	else if ((x < Corner1.x && x > Corner2.x && y < Corner1.y && y > Corner2.y))
	{
		return true;
	}
	else if ((x > Corner1.x && x < Corner2.x && y < Corner1.y && y > Corner2.y))
	{
		return true;
	}
	else
	{
		return false;
	}
}
string square::printforselection() {
	double Length = sqrt(pow((Corner1.x - Corner2.x), 2) + pow((Corner1.y - Corner2.y), 2));
	string msg = "selecteed shape is square with side length (" + to_string(Length) + ")";
	return msg;
}

shape* square::copy() {

	square* newSquare = new square(Corner1, Corner2, ShpGfxInfo);
	return newSquare;
}

void square::Move(Point P1, Point P2) {
	Corner1.x = P2.x - P1.x + Corner1.x;
	Corner2.x = P2.x - P1.x + Corner2.x;
	Corner1.y = P2.y - P1.y + Corner1.y;
	Corner2.y = P2.y - P1.y + Corner2.y;
}

void square::Zoom(double factor) {
	Point centre;
	centre.x = (Corner2.x + Corner1.x) / 2;
	centre.y = (Corner2.y + Corner1.y) / 2;
	Corner1.x = centre.x - ((Corner2.x - Corner1.x) * factor) / 2;
	Corner1.y = centre.y - ((Corner2.y - Corner1.y) * factor) / 2;
	Corner2.x = centre.x + ((Corner2.x - Corner1.x) * factor) / 2;
	Corner2.y = centre.y + ((Corner2.y - Corner1.y) * factor) / 2;
}
void square::Resize(double factor) {
	double Length = sqrt(pow((Corner1.x - Corner2.x), 2) + pow((Corner1.y - Corner2.y), 2));
	Length *= factor;

	double centerX = (Corner1.x + Corner2.x) / 2;
	double centerY = (Corner1.y + Corner2.y) / 2;
	double halfLength = Length / 2;

	Corner1.x = centerX - halfLength;
	Corner1.y = centerY - halfLength;
	Corner2.x = centerX + halfLength;
	Corner2.y = centerY + halfLength;
}

Point square::CalculateCenter() const {
	// Calculate the center of the square
	Point center;
	center.x = (Corner1.x + Corner2.x) / 2;
	center.y = (Corner1.y + Corner2.y) / 2;
	return center;
}


void square::Rotate() {
	// Calculate the center of the square
	Point center = CalculateCenter();

	double x_new1 = center.x + (Corner1.y - center.y);
	double y_new1 = center.y - (Corner1.x - center.x);
	Corner1.x = x_new1;
	Corner1.y = y_new1;

	
	double x_new2 = center.x + (Corner2.y - center.y);
	double y_new2 = center.y - (Corner2.x - center.x);
	Corner2.x = x_new2;
	Corner2.y = y_new2;
}

void square::ChngDrawClr(color Dclr)
{
	ShpGfxInfo.DrawClr = Dclr;
}
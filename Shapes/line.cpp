#include "line.h"
line::line(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}

line::~line()
{}

void line::Draw(GUI* pUI) const
{	
	pUI->DrawLine(Corner1, Corner2, ShpGfxInfo);
}
bool line::is_in_fig(int x, int y) {

	int LineLength = sqrt(pow((Corner1.x - Corner2.x), 2) + pow((Corner1.y - Corner2.y), 2));
	int Line1 = sqrt(pow((Corner1.x - x), 2) + pow((Corner1.y - y), 2));
	int Line2 = sqrt(pow((x - Corner2.x), 2) + pow((y - Corner2.y), 2));
	if (Line1 + Line2 == LineLength) {
		return true;

	}
	else {
		return false;
	}
}
string line::printforselection() {
	int LineLength = sqrt(pow((Corner1.x - Corner2.x), 2) + pow((Corner1.y - Corner2.y), 2));
	string msg = "selecteed shape is line with coordinates  (" + to_string(Corner1.x) + "," + to_string(Corner1.y) + ")"
		" and (" + to_string(Corner2.x) + ", " + to_string(Corner2.y) + ")and Length (" + to_string(LineLength) + ")";
	return msg;
}

shape* line::copy()
{
	line* newLine = new line(Corner1, Corner2, ShpGfxInfo);
	return newLine;
}

void line::Move(Point P1, Point P2) {

	Corner1.x = P2.x - P1.x + Corner1.x;
	Corner2.x = P2.x - P1.x + Corner2.x;
	Corner1.y = P2.y - P1.y + Corner1.y;
	Corner2.y = P2.y - P1.y + Corner2.y;
}
void line::Zoom(double factor) {
	Point centre;
	centre.x = (Corner2.x + Corner1.x) / 2;
	centre.y = (Corner2.y + Corner1.y) / 2;
	Corner1.x = centre.x - ((Corner2.x - Corner1.x) * factor) / 2;
	Corner1.y = centre.y - ((Corner2.y - Corner1.y) * factor) / 2;
	Corner2.x = centre.x + ((Corner2.x - Corner1.x) * factor) / 2;
	Corner2.y = centre.y + ((Corner2.y - Corner1.y) * factor) / 2;
 }
void line::Resize(double factor) {
	// Calculate midpoint of the line
	Point midpoint = { (Corner1.x + Corner2.x) / 2, (Corner1.y + Corner2.y) / 2 };

	// Calculate new endpoint distances
	double currentLength = sqrt(pow((Corner1.x - Corner2.x), 2) + pow((Corner1.y - Corner2.y), 2));
	double newLength = currentLength * factor;

	// Calculate new corner points
	double angle = atan2(Corner2.y - Corner1.y, Corner2.x - Corner1.x);
	double newHalfLength = newLength / 2;
	Corner1.x = midpoint.x - newHalfLength * cos(angle);
	Corner1.y = midpoint.y - newHalfLength * sin(angle);
	Corner2.x = midpoint.x + newHalfLength * cos(angle);
	Corner2.y = midpoint.y + newHalfLength * sin(angle);
}


void line::Rotate()
{

	Point center = { (Corner1.x + Corner2.x) / 2, (Corner1.y + Corner2.y) / 2 };

	double x1_new = center.x + (Corner1.y - center.y);
	double y1_new = center.y - (Corner1.x - center.x);
	Corner1.x = x1_new;
	Corner1.y = y1_new;

	double x2_new = center.x + (Corner2.y - center.y);
	double y2_new = center.y - (Corner2.x - center.x);
	Corner2.x = x2_new;
	Corner2.y = y2_new;
}

void line::ChngDrawClr(color Dclr)
{
	ShpGfxInfo.DrawClr = Dclr;
}
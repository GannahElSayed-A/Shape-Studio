#include "Rect.h"
#include "Reg.h"

Rect::Rect(Point P1, Point P2, GfxInfo shapeGfxInfo):shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}

Rect::~Rect()
{}

void Rect::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawRect(Corner1, Corner2, ShpGfxInfo);
}

bool Rect::is_in_fig(int x, int y) {
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
string Rect::printforselection() {

	string msg = "selecteed shape is rectangle with corner coordinates  (" + to_string(Corner1.x) + "," + to_string(Corner1.y) + ") and (" + to_string(Corner2.x) + ", " + to_string(Corner2.y) + ")";
	return msg;
}

shape* Rect::copy() {

	Rect* newRectangle = new Rect(Corner1, Corner2, ShpGfxInfo);
	return newRectangle;
}


void Rect::Move(Point P1, Point P2) {
	Corner1.x = P2.x - P1.x + Corner1.x;
	Corner2.x = P2.x - P1.x + Corner2.x;
	Corner1.y = P2.y - P1.y + Corner1.y;
	Corner2.y = P2.y - P1.y + Corner2.y;
}
void Rect::Zoom(double factor) {
	Point centre;
	centre.x = (Corner2.x + Corner1.x) / 2;
	centre.y = (Corner2.y + Corner1.y) / 2;
	Corner1.x = centre.x - ((Corner2.x - Corner1.x) * factor) / 2;
	Corner1.y = centre.y - ((Corner2.y - Corner1.y) * factor) / 2;
	Corner2.x = centre.x + ((Corner2.x - Corner1.x) * factor) / 2;
	Corner2.y = centre.y + ((Corner2.y - Corner1.y) * factor) / 2;
	/*centre.x += (Corner2.x + Corner1.x) / 2;
	centre.y += (Corner2.y + Corner1.y) / 2;*/
}

void Rect::Resize(double factor) {
	Point center = { (Corner1.x + Corner2.x) / 2, (Corner1.y + Corner2.y) / 2 };
	int width = Corner2.x - Corner1.x;
	int height = Corner2.y - Corner1.y;

	width = static_cast<int>(width * factor);
	height = static_cast<int>(height * factor);

	Corner1.x = center.x - width / 2;
	Corner1.y = center.y - height / 2;
	Corner2.x = center.x + width / 2;
	Corner2.y = center.y + height / 2;
}


void Rect::Rotate() {

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




void Rect::ChngDrawClr(color Dclr)
{
	ShpGfxInfo.DrawClr = Dclr;
}
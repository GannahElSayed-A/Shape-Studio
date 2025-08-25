#include "Oval.h"

oval::oval(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
oval :: ~oval() {}

void oval::Draw(GUI* pUI) const
{
	pUI->DrawEllipse(Corner1, Corner2, ShpGfxInfo);
}
bool oval::is_in_fig(int x, int y) {
	double h = (Corner1.x + Corner2.x) / 2;
	double k = (Corner1.y + Corner2.y) / 2;
	double a = sqrt(pow((Corner1.x - h), 2));
	double b = sqrt(pow((Corner1.y - k), 2));
	if ((pow((x - h), 2) / pow(a, 2)) + (pow((y - k), 2) / pow(b, 2)) <= 1) {
		return true;
	}
	else {
		return false;
	}
}

string oval::printforselection() {
	int h = (Corner1.x + Corner1.x) / 2;
	int k = (Corner1.y + Corner1.y) / 2;
	int a = sqrt(pow((Corner1.x - h), 2));
	int b = sqrt(pow((Corner1.y - k), 2));
	string msg = "selecteed shape is Oval with center (" + to_string(h) + " ," + to_string(k) + ") and axis(" + to_string(a) + ") and (" + to_string(b) + ")";
	return msg;
}

shape* oval::copy() {

	oval* newoval = new oval(Corner1, Corner2, ShpGfxInfo);
	return newoval;
}

void oval::Move(Point P1, Point P2) {
	Corner1.x = P2.x - P1.x + Corner1.x;
	Corner2.x = P2.x - P1.x + Corner2.x;
	Corner1.y = P2.y - P1.y + Corner1.y;
	Corner2.y = P2.y - P1.y + Corner2.y;
}
void oval::Zoom(double factor) {
	Point centre;
	centre.x = (Corner2.x + Corner1.x) / 2;
	centre.y = (Corner2.y + Corner1.y) / 2;
	Corner1.x = centre.x - ((Corner2.x - Corner1.x) * factor) / 2;
	Corner1.y = centre.y - ((Corner2.y - Corner1.y) * factor) / 2;
	Corner2.x = centre.x + ((Corner2.x - Corner1.x) * factor) / 2;
	Corner2.y = centre.y + ((Corner2.y - Corner1.y) * factor) / 2;
}
void oval::Resize(double factor) {
	double h = (Corner1.x + Corner2.x) / 2;
	double k = (Corner1.y + Corner2.y) / 2;
	double a = fabs(Corner1.x - h);
	double b = fabs(Corner1.y - k);

	a *= factor;
	b *= factor;

	Corner1.x = h - a;
	Corner1.y = k - b;
	Corner2.x = h + a;
	Corner2.y = k + b;
}
void oval::Rotate() {

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

void oval::ChngDrawClr(color Dclr)
{
	ShpGfxInfo.DrawClr = Dclr;
}
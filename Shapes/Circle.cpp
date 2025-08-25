 #include "Circle.h"


circle::circle(Point P1, Point P2, double radius, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	MA = P1;
	r = P2;
}

circle::~circle()
{}

void circle::Draw(GUI* pUI) const
{
	pUI->Drawcircle(MA,r, radius, ShpGfxInfo);
}
bool circle::is_in_fig(int x, int y) {
	double RadiusLength = sqrt(pow((r.x - MA.x), 2) + pow((r.y - MA.y), 2));
	double ClickLength = sqrt(pow((x - MA.x), 2) + pow((y - MA.y), 2));
	if (ClickLength <= RadiusLength) {

		return true;
	}
	else {
		return false;
	}
	return false;

}
string circle::printforselection() {
	int RadiusLength = sqrt(pow((r.x - MA.x), 2) + pow((r.y - MA.y), 2));
	string msg = "selecteed shape is circle with center coordinates  (" + to_string(MA.x) + "," + to_string(MA.y) + ")"
		" and radius(" + to_string(r.x) + ", " + to_string(r.y) + ")and raduis Length (" + to_string(RadiusLength) + ")";
	return msg;
}
shape* circle::copy()
{
	circle* newcircle = new circle (MA, r, radius, ShpGfxInfo);
	return newcircle;
}
void circle::Move(Point P1, Point P2) {
	MA.x = P2.x - P1.x + MA.x;
	r.x = P2.x - P1.x + r.x;
	MA.y = P2.y - P1.y + MA.y;
	r.y = P2.y - P1.y + r.y;
}
void circle::Zoom(double factor) {
	MA.x *= factor;
	MA.y *= factor;
	r.x *= factor;
	r.y *= factor;

	radius *= factor;
}
void circle::Resize(double factor) {
	// Calculate the new radius based on the scaling factor
	double currentRadius = sqrt(pow((r.x - MA.x), 2) + pow((r.y - MA.y), 2));
	double newRadius = currentRadius * factor;

	// Update the radius
	radius = newRadius;

	// Update the 'r' point to reflect the new radius
	// This maintains the circle's center but moves the boundary point
	double angle = atan2(r.y - MA.y, r.x - MA.x); // Angle between center and boundary point
	r.x = MA.x + newRadius * cos(angle);
	r.y = MA.y + newRadius * sin(angle);
}
void circle::Rotate() {

	double x_new = MA.x + (r.y - MA.y);
	double y_new = MA.y - (r.x - MA.x);
	r.x = x_new;
	r.y = y_new;
}

void circle::ChngDrawClr(color Dclr)
{
	ShpGfxInfo.DrawClr = Dclr;
}
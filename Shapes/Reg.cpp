#include "Reg.h"
regpoly::regpoly(Point* P1, int ivertices, GfxInfo shapeGfxInfo)
	: shape(shapeGfxInfo), ivertices(ivertices)
{
	// Allocate and copy the points
	POI = new Point[ivertices];
	for (int i = 0; i < ivertices; i++)
	{
		POI[i] = P1[i];
	}
}

regpoly::~regpoly()
{
	delete[] POI; // Free allocated memory
}

void regpoly::Draw(GUI* pUI) const
{
	// Call GUI::DrawPolygon to draw the polygon on the screen
	pUI->DrawPolygon(POI, ivertices, ShpGfxInfo);
}
bool regpoly::is_in_fig(int x, int y) {
	double RadiusLength = sqrt(pow((POI->x - Center.x), 2) + pow((POI->y - Center.y), 2));
	double ClickLength = sqrt(pow((x - Center.x), 2) + pow((y - Center.y), 2));
	if (ClickLength <= RadiusLength) {
		return true;
	}
	else {
		return false;
	}
	return false;
}
string regpoly::printforselection() {

	string msg = "selecteed shape is Regular Polygon with  (" + to_string(ivertices) + ") Vertices";
	return msg;
}

shape* regpoly::copy() {
	regpoly* newregpoly = new regpoly ( POI, ivertices, ShpGfxInfo);
	return newregpoly;

	shape* p = new regpoly ( POI, ivertices, ShpGfxInfo);
	return p;
}

void regpoly::Move(Point P1, Point P2) {
	for (int i = 0; i < ivertices; i++) {
		ArrX[i] = P2.x - P1.x + ArrX[i];
		ArrY[i] = P2.y - P1.y + ArrY[i];
	}
}
void regpoly::Resize(double factor) {
	// Calculate the center of the polygon
	double centerX = 0;
	double centerY = 0;
	for (int i = 0; i < ivertices; i++) {
		centerX += POI[i].x;
		centerY += POI[i].y;
	}
	centerX /= ivertices;
	centerY /= ivertices;

	// Resize vertices
	for (int i = 0; i < ivertices; i++) {
		double dx = POI[i].x - centerX;
		double dy = POI[i].y - centerY;
		POI[i].x = centerX + dx * factor;
		POI[i].y = centerY + dy * factor;
	}
}
void regpoly::Rotate() {
	double angle = ivertices / static_cast<double>(2); // 90 degrees in radians

	for (int i = 0; i < ivertices; ++i) {
		// Calculate the new coordinates after rotation
		double x_new = Center.x + (POI[i].y - Center.y);
		double y_new = Center.y - (POI[i].x - Center.x);
		POI[i].x = x_new;
		POI[i].y = y_new;
	}
}

void regpoly::ChngDrawClr(color Dclr)
{
	ShpGfxInfo.DrawClr = Dclr;
}
#include "Tri.h"
Tri::Tri(Point P1, Point P2, Point P3, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}

Tri::~Tri()
{}

void Tri::Draw(GUI* pUI) const
{
	pUI->DrawTri(Corner1, Corner2, Corner3, ShpGfxInfo);
};
bool Tri::is_in_fig(int x, int y) {

	double TriArea = abs((Corner1.x * (Corner2.y - Corner3.y) + Corner2.x * (Corner3.y - Corner1.y) + Corner3.x * (Corner1.y - Corner2.y)) / 2.0);
	double TriArea1 = abs((x * (Corner2.y - Corner3.y) + Corner2.x * (Corner3.y - y) + Corner3.x * (y - Corner2.y)) / 2.0);
	double TriArea2 = abs((Corner1.x * (y - Corner3.y) + x * (Corner3.y - Corner1.y) + Corner3.x * (Corner1.y - y)) / 2.0);
	double TriArea3 = abs((Corner1.x * (Corner2.y - y) + Corner2.x * (y - Corner1.y) + x * (Corner1.y - Corner2.y)) / 2.0);
	if (TriArea1 + TriArea2 + TriArea3 == TriArea) {
		return true;
	}
	else {
		return false;
	}
}
string Tri::printforselection() {

	string msg = "selecteed shape is triangle with corner coordinates  (" + to_string(Corner1.x) + "," + to_string(Corner1.y) + ")  and  (" + to_string(Corner2.x) + ", " + to_string(Corner2.y) + ") and (" + to_string(Corner3.x) + ", " + to_string(Corner3.y) + ")";
	return msg;
}

shape* Tri::copy() {

	Tri* newTriangle = new Tri(Corner1, Corner2, Corner3, ShpGfxInfo);
	return newTriangle;
}

void Tri::Move(Point P1, Point P2) {
	Corner1.x = P2.x - P1.x + Corner1.x;
	Corner2.x = P2.x - P1.x + Corner2.x;
	Corner1.y = P2.y - P1.y + Corner1.y;
	Corner2.y = P2.y - P1.y + Corner2.y;
	Corner3.x = P2.x - P1.x + Corner3.x;
	Corner3.y = P2.y - P1.y + Corner3.y;

}
void Tri::Zoom(double factor) {
	Point centre;
	centre.x = (Corner1.x + Corner2.x + Corner3.x) / 3;
	centre.y = (Corner1.y + Corner2.y + Corner3.y) / 3;
	Corner1.x = centre.x + (Corner1.x - centre.x) * factor;
	Corner1.y = centre.y + (Corner1.y - centre.y) * factor;
	Corner2.x = centre.x + (Corner2.x - centre.x) * factor;
	Corner2.y = centre.y + (Corner2.y - centre.y) * factor;
	Corner3.x = centre.x + (Corner3.x - centre.x) * factor;
	Corner3.y = centre.y + (Corner3.y - centre.y) * factor;
}


void Tri::Resize(double factor) {
	// Calculate centroid of the triangle
	double centroidX = (Corner1.x + Corner2.x + Corner3.x) / 3;
	double centroidY = (Corner1.y + Corner2.y + Corner3.y) / 3;

	// Calculate new coordinates for the vertices
	Corner1.x = centroidX + (Corner1.x - centroidX) * factor;
	Corner1.y = centroidY + (Corner1.y - centroidY) * factor;
	Corner2.x = centroidX + (Corner2.x - centroidX) * factor;
	Corner2.y = centroidY + (Corner2.y - centroidY) * factor;
	Corner3.x = centroidX + (Corner3.x - centroidX) * factor;
	Corner3.y = centroidY + (Corner3.y - centroidY) * factor;
}
Point Tri::CalculateCentroid() const {
	// Calculate the centroid of the triangle
	Point centroid;
	centroid.x = (Corner1.x + Corner2.x + Corner3.x) / 3;
	centroid.y = (Corner1.y + Corner2.y + Corner3.y) / 3;
	return centroid;
}

void Tri::Rotate() {
	// Calculate the centroid of the triangle
	Point centroid = CalculateCentroid();

	// Rotate Corner1
	double x_new1 = centroid.x + (Corner1.y - centroid.y);
	double y_new1 = centroid.y - (Corner1.x - centroid.x);
	Corner1.x = x_new1;
	Corner1.y = y_new1;

	// Rotate Corner2
	double x_new2 = centroid.x + (Corner2.y - centroid.y);
	double y_new2 = centroid.y - (Corner2.x - centroid.x);
	Corner2.x = x_new2;
	Corner2.y = y_new2;

	// Rotate Corner3
	double x_new3 = centroid.x + (Corner3.y - centroid.y);
	double y_new3 = centroid.y - (Corner3.x - centroid.x);
	Corner3.x = x_new3;
	Corner3.y = y_new3;
}

void Tri::ChngDrawClr(color Dclr)
{
	ShpGfxInfo.DrawClr = Dclr;
}

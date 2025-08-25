#include "opAddIrreg.h"
#include "..\shapes\Reg.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"


#include <cmath> // For trigonometric functions

opAddREGPOLY::opAddREGPOLY(controller* pCont) : operation(pCont)
{}

opAddREGPOLY::~opAddREGPOLY()
{}
void opAddREGPOLY::Execute()
{
	// Number of vertices (sides) for the regular polygon
	const int ivertices = 5;  // You can change this as needed

	// Array to store the vertices
	Point P1[ivertices];

	// Get a pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	// Get center point and radius from user
	pUI->PrintMessage("New REGULAR POLYGON: Click the center point");
	int centerX, centerY;
	pUI->GetPointClicked(centerX, centerY);
	Point center = { centerX, centerY };

	pUI->PrintMessage("Click to specify the radius");
	int radiusX, radiusY;
	pUI->GetPointClicked(radiusX, radiusY);
	int radius = static_cast<int>(sqrt(pow(radiusX - centerX, 2) + pow(radiusY - centerY, 2)));

	// Calculate the vertices of the regular polygon
	const double PI = 3.14;
	double angleStep = 2 * PI / ivertices;
	for (int i = 0; i < ivertices; i++)
	{
		double angle = i * angleStep;
		P1[i].x = static_cast<int>(centerX + radius * cos(angle));
		P1[i].y = static_cast<int>(centerY + radius * sin(angle));
	}

	// Inform the user
	pUI->ClearStatusBar();
	std::string msg = "Regular polygon with " + std::to_string(ivertices) + " vertices created.";
	pUI->PrintMessage(msg);

	// Prepare all polygon parameters
	GfxInfo regpolyGfxInfo;

	// Get drawing, filling colors, and pen width from the interface
	regpolyGfxInfo.DrawClr = pUI->getCrntDrawColor();
	regpolyGfxInfo.FillClr = pUI->getCrntFillColor();
	regpolyGfxInfo.BorderWdth = pUI->getCrntPenWidth();
	regpolyGfxInfo.isFilled = false;    // Default is not filled
	regpolyGfxInfo.isSelected = false;  // Default is not selected

	// Create a polygon with the above parameters
	regpoly* H = new regpoly(P1, ivertices, regpolyGfxInfo);

	// Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	// Add the polygon to the list of shapes
	pGr->Addshape(H);
}


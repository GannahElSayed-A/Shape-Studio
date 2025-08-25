#include "opAddReg.h"
#include "..\shapes\Reg.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"


opAddpoly::opAddpoly(controller* pCont) : operation(pCont)
{}

opAddpoly::~opAddpoly()
{}

void opAddpoly::Execute()
{
	const int ivertices = 5;  // Number of vertices for the polygon
	Point P1[ivertices];     // Array to store the vertices

	// Get a pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New POLYGON: Click at each corner");

	// Read all the vertices and store them in P1 array
	for (int i = 0; i < ivertices; i++)
	{
		pUI->GetPointClicked(P1[i].x, P1[i].y);
		std::string msg = "In order Corner " + to_string(i + 1) + " is at (" + to_string(P1[i].x) + ", " + to_string(P1[i].y) + " )";
		pUI->PrintMessage(msg);

		// Inform the user to click the next corner if it's not the last one
		if (i < ivertices - 1)
		{
			pUI->PrintMessage("Click at the next corner");
		}
		else
		{
			pUI->PrintMessage("All corners are clicked");
		}
	}

	pUI->ClearStatusBar();

	// Prepare all polygon parameters
	GfxInfo regpolyGfxInfo;

	// Get drawing, filling colors, and pen width from the interface
	regpolyGfxInfo.DrawClr = pUI->getCrntDrawColor();
	regpolyGfxInfo.FillClr = pUI->getCrntFillColor();
	regpolyGfxInfo.BorderWdth = pUI->getCrntPenWidth();
	regpolyGfxInfo.isFilled = false;    // Default is not filled
	regpolyGfxInfo.isSelected = false;  // Default is not selected

	// Create a polygon with the above parameters
	regpoly* D = new regpoly(P1, ivertices, regpolyGfxInfo);

	// Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	// Add the polygon to the list of shapes
	pGr->Addshape(D);
}

void opAddpoly::Undo()
{
	shape* temp = pControl->getOperatedOn();
	Graph* Gpr = pControl->getGraph();
	Gpr->PopFromShapeList(temp);
}

void opAddpoly::Redo()
{
	Graph* Gpr = pControl->getGraph();
	shape* temp = pControl->getFutureOperatedOn();
	Gpr->Addshape(temp);
}
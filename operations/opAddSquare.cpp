#include "opAddSquare.h"
#include "..\shapes\Square.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"






opAddsquare::opAddsquare(controller* pCont) : operation(pCont)
{}

opAddsquare::~opAddsquare()
{}

void opAddsquare::Execute()
{
	Point P1, P2;

	// Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Square: Click at the first corner");
	// Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "First corner is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at the opposite corner";
	pUI->PrintMessage(msg);
	// Read 2nd corner and store in point P2
	pUI->GetPointClicked(P2.x, P2.y);
	pUI->ClearStatusBar();

	// Calculate the side length to ensure it's a square
	int sideLength = min(abs(P2.x - P1.x), abs(P2.y - P1.y));

	// Determine the second corner to form a square
	if (P2.x > P1.x && P2.y > P1.y) {
		P2.x = P1.x + sideLength;
		P2.y = P1.y + sideLength;
	}
	else if (P2.x < P1.x && P2.y > P1.y) {
		P2.x = P1.x - sideLength;
		P2.y = P1.y + sideLength;
	}
	else if (P2.x > P1.x && P2.y < P1.y) {
		P2.x = P1.x + sideLength;
		P2.y = P1.y - sideLength;
	}
	else {
		P2.x = P1.x - sideLength;
		P2.y = P1.y - sideLength;
	}

	// Prepare all square parameters
	GfxInfo squareGfxInfo;

	// Get drawing, filling colors and pen width from the interface
	squareGfxInfo.DrawClr = pUI->getCrntDrawColor();
	squareGfxInfo.FillClr = pUI->getCrntFillColor();
	squareGfxInfo.BorderWdth = pUI->getCrntPenWidth();

	squareGfxInfo.isFilled = false; // default is not filled
	squareGfxInfo.isSelected = false; // default is not selected

	// Create a square with the above parameters
	square* S = new square(P1, P2, squareGfxInfo);

	// Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	// Add the square to the list of shapes
	pGr->Addshape(S);
}


void opAddsquare::Undo()
{
	shape* temp = pControl->getOperatedOn();
	Graph* Gpr = pControl->getGraph();
	Gpr->PopFromShapeList(temp);
}

void opAddsquare::Redo()
{
	Graph* Gpr = pControl->getGraph();
	shape* temp = pControl->getFutureOperatedOn();
	Gpr->Addshape(temp);
}







#include "opAddOval.h"
#include "..\shapes\Oval.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

opaddoval::opaddoval(controller* pCont) :operation(pCont)
{}
opaddoval::~opaddoval()
{}

void opaddoval::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New oval: Click at first corner");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "First point is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at second point";
	pUI->PrintMessage(msg);
	//Read 2nd corner and store in point P2
	pUI->GetPointClicked(P2.x, P2.y);
	pUI->ClearStatusBar();

	//Preapre all rectangle parameters
	GfxInfo ovalGfxInfo;

	//get drawing, filling colors and pen width from the interface
	ovalGfxInfo.DrawClr = pUI->getCrntDrawColor();
	ovalGfxInfo.FillClr = pUI->getCrntFillColor();
	ovalGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	ovalGfxInfo.isFilled = false;	//default is not filled
	ovalGfxInfo.isSelected = false;	//defualt is not selected


	//Create a Ellipse with the above parameters
	oval* O = new oval(P1, P2, ovalGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	pGr->Addshape(O);

}

void opaddoval::Undo()
{
	shape* temp = pControl->getOperatedOn();
	Graph* Gpr = pControl->getGraph();
	Gpr->PopFromShapeList(temp);
}

void opaddoval::Redo()
{
	Graph* Gpr = pControl->getGraph();
	shape* temp = pControl->getFutureOperatedOn();
	Gpr->Addshape(temp);
}
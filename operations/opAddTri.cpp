#include "opAddTri.h"
#include "..\shapes\Tri.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"



opAddTri::opAddTri(controller* pCont) :operation(pCont)
{}
opAddTri::~opAddTri()
{}
void opAddTri::Execute()
{
	Point P1, P2, P3;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Triangle: Click at first corner");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "First corner is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at second corner";
	pUI->PrintMessage(msg);
	//Read 2nd corner and store in point P2
	pUI->GetPointClicked(P2.x, P2.y);
	string msg1 = "Second corner is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg1 += " ... Click at third corner";
	pUI->PrintMessage(msg1);

	pUI->GetPointClicked(P3.x, P3.y);
	pUI->ClearStatusBar();

	
	GfxInfo TriGfxInfo;

	//get drawing, filling colors and pen width from the interface
	TriGfxInfo.DrawClr = pUI->getCrntDrawColor();
	TriGfxInfo.FillClr = pUI->getCrntFillColor();
	TriGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	TriGfxInfo.isFilled = false;	//default is not filled
	TriGfxInfo.isSelected = false;	//defualt is not selected


	
	Tri* T = new Tri(P1, P2, P3, TriGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	pGr->Addshape(T);

}

void opAddTri::Undo()
{
	shape* temp = pControl->getOperatedOn();
	Graph* Gpr = pControl->getGraph();
	Gpr->PopFromShapeList(temp);
}

void opAddTri::Redo()
{
	Graph* Gpr = pControl->getGraph();
	shape* temp = pControl->getFutureOperatedOn();
	Gpr->Addshape(temp);
}


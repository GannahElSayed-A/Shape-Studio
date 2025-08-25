#include "opAddLine.h"
#include "..\shapes\line.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"



opAddLine::opAddLine(controller* pCont) :operation(pCont)
{}
opAddLine::~opAddLine()
{}


void opAddLine::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Line: Click at first corner");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "First corner is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at second corner";
	pUI->PrintMessage(msg);
	//Read 2nd corner and store in point P2
	pUI->GetPointClicked(P2.x, P2.y);
	pUI->ClearStatusBar();

	
	GfxInfo lineGfxInfo;

	//get drawing, filling colors and pen width from the interface
	lineGfxInfo.DrawClr = pUI->getCrntDrawColor();
	lineGfxInfo.FillClr = pUI->getCrntFillColor();
	lineGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	lineGfxInfo.isFilled = false;	//default is not filled
	lineGfxInfo.isSelected = false;	//defualt is not selected


	
	line* L = new line(P1, P2, lineGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	
	pGr->Addshape(L);

}

void opAddLine::Redo()
{
	Graph* Gpr = pControl->getGraph();
	shape* temp = pControl->getFutureOperatedOn();
	Gpr->Addshape(temp);
}


void opAddLine::Undo()
{
	shape* temp = pControl->getOperatedOn();
	Graph* Gpr = pControl->getGraph();
	Gpr->PopFromShapeList(temp);
}
#include "opAddCircle.h"
#include "..\shapes\Circle.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"




opAddcircle::opAddcircle(controller* pCont) :operation(pCont)
{}
opAddcircle::~opAddcircle()
{}

void opAddcircle::Execute()
{
	Point P1;
	Point P2;
	double radius;
	
	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Circle: Click at the centre");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);
	//Read 2nd corner and store in point P2
	pUI->PrintMessage("New Circle: Click at the radius");
	pUI->GetPointClicked(P2.x, P2.y);
	pUI->ClearStatusBar();
	double x = pow((P2.x - P1.x), 2);
	double y = pow((P2.y - P1.y), 2);
	radius = sqrt(x+y);
	
	GfxInfo circleGfxInfo;

	//get drawing, filling colors and pen width from the interface
	circleGfxInfo.DrawClr = pUI->getCrntDrawColor();
	circleGfxInfo.FillClr = pUI->getCrntFillColor();
	circleGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	circleGfxInfo.isFilled = false;	//default is not filled
	circleGfxInfo.isSelected = false;	//defualt is not selected


	
	circle* C = new circle(P1,P2,radius, circleGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	pGr->Addshape(C);

}

void opAddcircle::Undo()
{
	shape* temp = pControl->getOperatedOn();
	Graph* Gpr = pControl->getGraph();
	Gpr->PopFromShapeList(temp);
}

void opAddcircle::Redo()
{
	Graph* Gpr = pControl->getGraph();
	shape* temp = pControl->getFutureOperatedOn();
	Gpr->Addshape(temp);
}






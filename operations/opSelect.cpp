#include "opSelect.h"
#include "..\shapes\Rect.h"
#include "..\shapes\line.h"
#include "..\shapes\square.h"
#include "..\shapes\Oval.h"
#include "..\shapes\Circle.h"
#include "..\shapes\Reg.h"
#include "..\shapes\Tri.h"
#include "..\controller.h"

#include "..\GUI\GUI.h"

opSelect::opSelect(controller* pCont) :operation(pCont)
{}
opSelect::~opSelect()
{}

//Execute the operation
void opSelect::Execute()
{
	Point P1;
	Graph* pGraph = pControl->getGraph();
	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage("Click At The Figure You want to select/unselect");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);
	pGraph->resetselect(P1.x, P1.y);
	shape* sel = pGraph->Getshape(P1.x, P1.y);

	if (sel) {

		if (pGraph->GetSelected()) {
			sel->SetSelected(true);
			pUI->ClearStatusBar();
			pUI->PrintMessage(sel->printforselection());
			pGraph->GetSelected()->SetSelected(false);
			pGraph->SetSelected(sel);

		}
		else {

			sel->SetSelected(true);
			pUI->ClearStatusBar(); 
			pUI->PrintMessage(sel->printforselection());

			pGraph->SetSelected(sel);
		}
	}

}

#include "opMultiSelect.h"
#include "..\shapes\Rect.h"
#include "..\shapes\line.h"
#include "..\shapes\square.h"
#include "..\shapes\Oval.h"
#include "..\shapes\Circle.h"
#include "..\shapes\Reg.h"
#include "..\shapes\Tri.h"
#include "..\controller.h"

#include "..\GUI\GUI.h"

opMultiSelect::opMultiSelect(controller* pCont) :operation(pCont)
{}
opMultiSelect::~opMultiSelect()
{}

//Execute the operation
void opMultiSelect::Execute()
{
	Point P1;
	Graph* pGraph = pControl->getGraph();
	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage("Welcome to Multi_Select, Click At The Figures You want to select/unselect");
	pUI->GetPointClicked(P1.x, P1.y);
	pGraph->resetmultiselect(P1.x, P1.y);
	shape* msel = pGraph->Getshape(P1.x, P1.y);

	if (msel)
	{

		if (pGraph->GetSelected())
		{
			msel->SetSelected(true);
			pUI->ClearStatusBar();
			pUI->PrintMessage(msel->printforselection());
			pGraph->SetSelected(msel);
		}
		else {
			msel->SetSelected(true);
			pUI->ClearStatusBar();
			pUI->PrintMessage(msel->printforselection());
			pGraph->SetSelected(msel);
		}
	}
	
}

opChangeFillColor::opChangeFillColor(controller* pCont) : operation(pCont)
{}
opChangeFillColor::~opChangeFillColor()

{}

void opChangeFillColor::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();

	// get selected shape
	shape* pSelectedShape = pGraph->GetSelected();
	//ChangeFillColor
	if (pSelectedShape)
	{
		// choose color from pallet 
		pUI->PrintMessage("Choose color to fill the shape from color pallete");
		color newColor = pUI->getColorPallete();


		pSelectedShape->ChngFillClr(newColor);


		pUI->ClearStatusBar();
		pUI->PrintMessage("The color changed ");


		pGraph->Draw(pUI);
	}
	else
	{
		pUI->PrintMessage("No Selected shape!");
	}
}




opRotate::opRotate(controller* pCont) : operation(pCont)
{}

opRotate::~opRotate()
{}

// Execute the rotate operation
void opRotate::Execute()
{
	// Get a pointer to the graph and UI
	Graph* pGraph = pControl->getGraph();
	GUI* pUI = pControl->GetUI();

	// Check if there is a selected shape
	shape* selectedShape = pGraph->GetSelected();

	if (selectedShape)
	{
		// Rotate the selected shape
		selectedShape->Rotate();

		// Clear status bar and display the updated information
		pUI->ClearStatusBar();
		pUI->PrintMessage(selectedShape->printforselection());

		selectedShape->Draw(pUI);
	}
	else
	{
		pUI->PrintMessage("No shape selected to rotate.");
	}
}




opChangeBorderColor::opChangeBorderColor(controller* pCont) : operation(pCont)
{}

opChangeBorderColor::~opChangeBorderColor()
{}

void opChangeBorderColor::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();

	// get selected shape
	shape* pSelectedShape = pGraph->GetSelected();

	if (pSelectedShape)
	{
		// choose color from pallet 
		pUI->PrintMessage("Choose color from color pallete");
		color newColor = pUI->getColorPallete();


		pSelectedShape->SetBorderColor(newColor);


		pUI->ClearStatusBar();
		pUI->PrintMessage("The color changed ");


		pGraph->Draw(pUI);
	}
	else
	{
		pUI->PrintMessage("No Selected shape!");
	}
}

opChangePenColor::opChangePenColor(controller* pCont) : operation(pCont)
{}

opChangePenColor::~opChangePenColor()
{}

void opChangePenColor::Execute()
{
	GUI* pUI = pControl->GetUI();


	pUI->PrintMessage("Choose New Color For Pen ");
	color newColor = pUI->getColorPallete();

	pUI->setcrntdrawcolor(newColor);

	pUI->ClearStatusBar();
	pUI->PrintMessage("The Pen Changed !");
}
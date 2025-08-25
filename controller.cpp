#include "controller.h"
#include "operations\opAddRect.h"
#include "operations\opAddTri.h"
#include "operations\opAddLine.h"
#include "operations\opAddCircle.h"
#include "operations\opAddOval.h"
#include "operations\opAddReg.h"
#include "operations\opAddIrreg.h"
#include "operations\opAddSquare.h"
#include "operations\opSelect.h"
#include "operations\opMultiselect.h"
#include "operations\opCut.h"
#include "operations\opCopy.h"
#include "operations\opUndo.h"
#include "operations\opRedo.h"
#include "operations\opMultiDelete.h"
#include "operations\opSendBack.h"
#include "operations\opZoomIn.h"
#include "operations\opZoomOut.h"
#include "operations\opMove.h"
#include"operations\opDelete.h"
#include"operations\opresize.h"
#include"operations\opPaste.h"
//Constructor
controller::controller()
{
	pGraph = new Graph;
	pGUI = new GUI;	//Create GUI object
}

//==================================================================================//
//								operations-Related Functions							//
//==================================================================================//
operationType controller::GetUseroperation() const
{
	//Ask the input to get the operation from the user.
	return pGUI->GetUseroperation();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an operation and executes it
operation* controller::createOperation(operationType OpType)
{
	operation* pOp = nullptr;
	
	//According to operation Type, create the corresponding operation object
	switch (OpType)
	{
	case DRAW_RECT:
		pOp = new opAddRect(this);
		break;
	case DRAW_TRI:
		pOp = new opAddTri(this);
		break;
	case DRAW_OVAL:
		pOp = new opaddoval(this);
		break;
	case EXIT:
		///create Exitoperation here
		break;
	case DRAW_LINE:
		pOp = new opAddLine(this);
		break;
	case DRAW_CIRC:
		pOp = new opAddcircle(this);
		break;
	case DRAW_SQUARE:
		pOp = new opAddsquare(this);
		break;
	case DRAW_POLY:
		pOp = new opAddpoly(this);
		break;
	case DRAW_REGPOLY:
		pOp = new opAddREGPOLY(this);
		break;
	case STATUS:	//a click on the status bar ==> no operation
		break;
	case SELECT:
		pOp = new opSelect(this);
		break;
	case MULTI_SELECT:
		pOp = new opMultiSelect(this);
		break;
	case COPY:
		pOp = new opCopy(this);
		break;
	case CUT:
		pOp = new opcut(this);
		break;
	case UNDO:
		pOp = new opUndo(this);
		break;
	case REDO:
		pOp = new opRedo(this);
		break;
	case MULTI_DELETE:
		pOp = new opMultDelete(this);
		break;
	case ZOOMIN:
		pOp = new ZoomIn(this);
		break;
	case ZOOMOUT:
		pOp = new ZoomOut(this);
		break;
	case SEND_BACK:
		pOp = new opSendBack(this);
		break;
	case MOVE:
		pOp = new opMove(this);
		break;
	case ROTATE:
		pOp = new opRotate(this);
		break;

	case CHNG_BORDER_CLR:
		pOp = new opChangeBorderColor(this);
		break;

	case CHNG_PN_CLR:
		pOp = new opChangePenColor(this);
		break;
	case TO_DELETE:
		pOp = new opDelete(this);
		break;
	case REsize:
		pOp = new opResize(this);
		break;
	case CHNG_FILL_CLR:
		pOp = new opChangeFillColor(this);
		break;
	case PASTE:
		pOp = new opPaste(this);
		break;
	/*	case SAVE:
		pOp = new opSave(this);
		break;*/


	/*case GROUP:
		pOp = new opGroup(this);
		break;*/
	}

	return pOp;
	
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all shapes on the user interface
void controller::UpdateInterface() const
{	
	pGraph->Draw(pGUI);
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the UI
GUI *controller::GetUI() const
{	return pGUI; }
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the Graph
Graph* controller::getGraph() const
{
	return pGraph;
}



//Destructor
controller::~controller()
{
	delete pGUI;
	delete pGraph;
	
}



//==================================================================================//
//							Run function											//
//==================================================================================//
void controller::Run()
{
	operationType OpType;
	do
	{
		//1. Ask the GUI to read the required operation from the user
		OpType = GetUseroperation();

		//2. Create an operation coresspondingly
		operation* pOpr = createOperation(OpType);
		 
		//3. Execute the created operation
		if (pOpr)
		{
			pOpr->Execute();//Execute
			delete pOpr;	//operation is not needed any more ==> delete it
			pOpr = nullptr;
		}

		//Update the interface
		UpdateInterface();

	} while (OpType != EXIT);

}

bool controller::checkPresent() { return Present.size(); }
operation* controller::UpdateTimeLine()
{
	operation* op = Present.back();	//get last element
	Present.pop_back();	//remove
	future.push_back(op); //Add
	return op;
}
void controller::pushToFutureOperatedOn(shape* shp) { FutureOperatedOn.push_back(shp); }
void controller::popOperatedOn()
{
	pushToFutureOperatedOn(OperatedOn.back());
	OperatedOn.pop_back();
}

bool controller::checkFuture()
{
	return future.size();
}

operation* controller::UpdateFuture()
{
	operation* op = future.back();	//get last element
	future.pop_back();	//remove
	Present.push_back(op); //Add
	return op;
}
void controller::pushToOperatedOn(shape* shp) { OperatedOn.push_back(shp); }
void controller::popOperatedOnToPresent()
{
	pushToOperatedOn(FutureOperatedOn.back());
	FutureOperatedOn.pop_back();

}
shape* controller::getFutureOperatedOn() { return FutureOperatedOn.back(); }
shape* controller::getOperatedOn() { if (OperatedOn.size()) { return OperatedOn.back(); } }
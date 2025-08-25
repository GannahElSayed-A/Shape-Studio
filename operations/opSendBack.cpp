#include "opSendBack.h"
#include"../Shapes/Graph.h"
#include"../controller.h"
#include"../operations/operation.h"

opSendBack::opSendBack(controller * pCont) : operation(pCont)
{
}
void opSendBack::Execute()
{
    GUI* pUI = pControl->GetUI();
    Graph* pGr = pControl->getGraph();
    pGr->back();
    pUI->PrintMessage("Selected Shape is Sent Back");
}


#include "opCopy.h"
#include"../Shapes/Graph.h"
#include"../controller.h"
#include"../operations/operation.h"

opCopy::opCopy(controller* pCont) : operation(pCont) {}

void opCopy::Execute()
{
    GUI* pUI = pControl->GetUI();
    Graph* pGr = pControl->getGraph();

    pGr->copy();

    pUI->PrintMessage("Object copied to clipboard click paste to add it to graph");

}



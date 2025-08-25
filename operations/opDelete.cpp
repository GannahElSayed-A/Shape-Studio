#include "opDelete.h"
#include"../Shapes/Graph.h"
#include"../controller.h"
#include"../operations/operation.h"

opDelete::opDelete(controller* pCont) : operation(pCont)
{
}
void opDelete::Execute()
{
    GUI* pUI = pControl->GetUI();
    Graph* pGr = pControl->getGraph();
    pGr->Delete();
    pUI->PrintMessage("deleted");
}

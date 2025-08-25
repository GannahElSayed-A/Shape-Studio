#include "opMultiDelete.h"
#include"../Shapes/Graph.h"
#include"../controller.h"
#include"../operations/operation.h"

opMultDelete::opMultDelete(controller* pCont) : operation(pCont)
{
}
void opMultDelete::Execute()
{
    GUI* pUI = pControl->GetUI();
    Graph* pGr = pControl->getGraph();
    pGr->multiDelete();
    pUI->PrintMessage("All Selected Shapes are deleted");
}





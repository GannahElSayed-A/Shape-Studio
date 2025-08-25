#include "opGroup.h"
#include"../Shapes/Graph.h"
#include"../controller.h"
#include"../operations/operation.h"

grouped::grouped(controller* pCont) : operation(pCont)
{
}
void grouped::Execute()
{
    GUI* pUI = pControl->GetUI();
    Graph* pGr = pControl->getGraph();
    pGr->grouped();
    pUI->PrintMessage("grouped");
}
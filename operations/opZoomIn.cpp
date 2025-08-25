#include "opZoomIn.h"
#include"../Shapes/Graph.h"
#include"../controller.h"
#include"../operations/operation.h"

ZoomIn::ZoomIn(controller* pCont) : operation(pCont)
{
}
void ZoomIn::Execute()
{
    GUI* pUI = pControl->GetUI();
    Graph* pGr = pControl->getGraph();
    pGr->zoom_in();
    pUI->PrintMessage("Zoom Out by Factor 2");
}
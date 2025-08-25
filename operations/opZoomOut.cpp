#include "opZoomOut.h"
#include"../Shapes/Graph.h"
#include"../controller.h"
#include"../operations/operation.h"

ZoomOut::ZoomOut(controller* pCont) : operation(pCont)
{
}
void ZoomOut::Execute()
{
    GUI* pUI = pControl->GetUI();
    Graph* pGr = pControl->getGraph();
    pGr->zoom_out();
    pUI->PrintMessage("Zoom Out by Factor 0.5");
}
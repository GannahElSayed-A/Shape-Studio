#include "opPaste.h"
#include"../Shapes/Graph.h"
#include"../controller.h"
#include"../operations/operation.h"

opPaste::opPaste(controller* pCont) : operation(pCont) {}
void opPaste::Execute() {
    GUI* pUI = pControl->GetUI();
    Graph* pGr = pControl->getGraph();

    pGr->paste();

    pUI->PrintMessage("Pasted");
}
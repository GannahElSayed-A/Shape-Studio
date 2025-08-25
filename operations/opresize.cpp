#include "opresize.h"
#include"../Shapes/Graph.h"
#include"../controller.h"
#include"../operations/operation.h"

opResize::opResize(controller* pCont) : operation(pCont) {}

opResize::~opResize() {}

void opResize::Execute() {
    GUI* pUI = pControl->GetUI();
    Graph* pGr = pControl->getGraph();


    pUI->PrintMessage("Enter resize factor (e.g., 2for 200%):");
    string input = pUI->GetSrting();

    double factor = atof(input.c_str());

    if (factor > 0) {
        pGr->ResizeSelectedShapes(factor);
        pUI->PrintMessage("Shape resized successfully.");
    }
    else {
        pUI->PrintMessage("Invalid factor. Resize operation aborted.");
    }
}

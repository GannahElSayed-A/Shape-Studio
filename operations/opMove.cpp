#include "opMove.h"
opMove::opMove(controller* pcont) :operation(pcont) {}
opMove :: ~opMove() {}
void opMove::Execute() {
	Point P1;
	Point P2;
	GUI* pUI = pControl->GetUI(); 
	Graph* pGr = pControl->getGraph(); 
	pUI->PrintMessage("click in the shape you want to move");
	pUI->GetPointClicked(P1.x, P1.y);
	
		shape* sel = pGr->Getshape(P1.x, P1.y);
		if (sel) {

			if (pGr->GetSelected()) {
				sel->SetSelected(true);
				pUI->ClearStatusBar();
				pGr->GetSelected()->SetSelected(false);
				pGr->SetSelected(sel);

			}
			else {

				sel->SetSelected(true);
				pGr->SetSelected(sel);
				bool flag = false;
				pUI->ClearStatusBar();
				pUI->PrintMessage("click again to stop moving");

				while (!flag) {
					pUI->Drag(P1);

					while (!pUI->Drag(P2)) {
						Sleep(16);
						if (pGr->GetSelected()) {
							pGr->GetSelected()->Move(P1, P2); // is done after making select function 
							pGr->Draw(pUI);
							P1 = P2;

						}
					}
					sel->SetSelected(false);

					flag = true;

				}

			}
			
			pUI->CreateDrawToolBar();
			sel->SetSelected(false);
		
		}
		pControl->getGraph()->setselectedshapenull();

}
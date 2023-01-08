#include "opToDrawMode.h"

opToDrawMode::opToDrawMode(controller* pCont) :operation(pCont)
{}
opToDrawMode::~opToDrawMode() {}

void opToDrawMode::Execute() {
	GUI* pUI = pControl->GetUI();
	Graph* pGrp = pControl->getGraph();
	pUI->CreateDrawToolBar();
}
#include "opCopy.h"

opCopy::opCopy(controller* pCont):operation(pCont)
{
}

opCopy::~opCopy()
{
}

void opCopy::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	//pUI->PrintMessage("No figure has been selected");
	pGraph->CopyShape();
}

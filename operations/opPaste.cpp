#include "opPaste.h"

opPaste::opPaste(controller* pCont): operation(pCont)
{
}

opPaste::~opPaste()
{
}

void opPaste::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	shape* ShapeToPaste;
	pGraph->oppPasteShape();
	
}

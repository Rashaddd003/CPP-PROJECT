#include "opRedo.h"



opRedo::opRedo(controller* pCont) :operation(pCont)
{}

opRedo::~opRedo()
{}

void opRedo::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();

	pGr->Redo();

}
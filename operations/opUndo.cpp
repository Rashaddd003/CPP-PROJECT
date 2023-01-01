#include "opUndo.h"



opUndo::opUndo(controller* pCont) :operation(pCont)
{}

opUndo::~opUndo()
{}

void opUndo::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();

	pGr->Undo();

}
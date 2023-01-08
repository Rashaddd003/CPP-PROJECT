#include "opDrag.h"

opDrag::opDrag(controller* pCont) :operation(pCont)
{

}
opDrag::~opDrag()
{}

void opDrag::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();

	pGr->dragShape(pUI,pGr);
	pGr->Addoperation("Drag");
}
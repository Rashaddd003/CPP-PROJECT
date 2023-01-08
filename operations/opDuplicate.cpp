#include "opDuplicate.h"

opDuplicate::opDuplicate(controller* pCont) :operation(pCont)
{

}
opDuplicate::~opDuplicate()
{}

void opDuplicate::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();

	pGr->Duplicate();
	pGr->Addoperation("Duplicate");
}
#include "opGroupShapes.h"

opGroupShapes::opGroupShapes(controller* pCont) :operation(pCont)
{

}
opGroupShapes::~opGroupShapes()
{}

void opGroupShapes::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();

	pGr->GroupShapes(pUI);
}
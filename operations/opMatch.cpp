#include "opMatch.h"

opMatch::opMatch(controller* pCont) :operation(pCont)
{

}
opMatch::~opMatch()
{}

void opMatch::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
;
	pGr->Match(pUI,pGr);
}
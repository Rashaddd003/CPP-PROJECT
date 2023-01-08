#include "opRotateShape.h"

opRotateShape::opRotateShape(controller* pCont) :operation(pCont)
{

}
opRotateShape::~opRotateShape()
{}

void opRotateShape::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();

	pGr->RotateShape();
}
#include "opResizeShape.h"

opResizeShape::opResizeShape(controller* pCont) :operation(pCont)
{

}
opResizeShape::~opResizeShape()
{}

void opResizeShape::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	pUI->PrintMessage("Enter the resize scale");
	
	double scale;

	scale = stod(pUI->GetSrting());
	pUI->ClearStatusBar();

	pGr->resizeShape(scale);
	pGr->Addoperation("Resize");
}
#include "opStickImage.h"

opStickImage::opStickImage(controller* pCont): operation(pCont)
{}

opStickImage::~opStickImage()
{
}

void opStickImage::Execute()
{
	Point ClickedPoint;
	GUI* pUI = pControl->GetUI();
	pUI->GetPointClicked(ClickedPoint.x, ClickedPoint.y);
	Graph* pGraph = pControl->getGraph();
	shape* ShapeToStick = pGraph->Getshape(ClickedPoint.x, ClickedPoint.y);
	if (ShapeToStick)
	{
		ShapeToStick->setImagePresent();
	}
}



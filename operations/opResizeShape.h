#pragma once
#include "operation.h"
#include "..\CMUgraphicsLib\colors.h"
#include "..\shapes/Shape.h"
#include "..\Shapes\Graph.h"
#include "../GUI/GUI.h"
#include "../controller.h"

class opResizeShape : public operation
{
public:
	opResizeShape(controller* pCont);
	~opResizeShape();
	virtual void Execute();

};
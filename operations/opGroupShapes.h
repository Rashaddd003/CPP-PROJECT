#pragma once
#include "operation.h"
#include "..\shapes/Shape.h"
#include "..\Shapes\Graph.h"
#include "../GUI/GUI.h"
#include "../controller.h"

class opGroupShapes : public operation
{
public:
	opGroupShapes(controller* pCont);
	~opGroupShapes();
	virtual void Execute();
};
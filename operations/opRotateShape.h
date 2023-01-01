#pragma once
#include "operation.h"
#include "..\CMUgraphicsLib\colors.h"
#include "..\shapes/Shape.h"
#include "..\Shapes\Graph.h"
#include "../GUI/GUI.h"
#include "../controller.h"

class opRotateShape : public operation
{
public:
	opRotateShape(controller* pCont);
	~opRotateShape();
	virtual void Execute();
};
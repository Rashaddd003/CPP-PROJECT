#pragma once
#include "../controller.h"
#include "operation.h"
#include "../GUI/GUI.h"
#include "../controller.h"
#include "../Shapes/Graph.h"
#include "../Shapes/Graph.h"

class opToDrawMode : public operation
{
public:
	opToDrawMode(controller* pCont);
	~opToDrawMode();
	//Add rectangle to the controller
	void Execute();

};
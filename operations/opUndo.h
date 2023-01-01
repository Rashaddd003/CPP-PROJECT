#pragma once
#include "operation.h"
#include "..\shapes/Shape.h"
#include "..\Shapes\Graph.h"
#include "../GUI/GUI.h"
#include "../controller.h"

class opUndo : public operation
{
public:
	opUndo(controller* pCont);
	~opUndo();
	virtual void Execute();
};
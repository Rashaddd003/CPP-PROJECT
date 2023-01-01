#pragma once
#include "operation.h"
#include "..\shapes/Shape.h"
#include "..\Shapes\Graph.h"
#include "../GUI/GUI.h"
#include "../controller.h"

class opRedo : public operation
{
public:
	opRedo(controller* pCont);
	~opRedo();
	virtual void Execute();
};
#pragma once
#include "operation.h"
#include <iostream>
#include <vector>
#include "operation.h"
#include "..\shapes/Shape.h"
#include "..\Shapes\Graph.h"
#include "../GUI/GUI.h"
#include "../controller.h"

class opCopy : public operation
{
public:
	opCopy(controller* pCont);
	~opCopy();
	virtual void Execute();
};
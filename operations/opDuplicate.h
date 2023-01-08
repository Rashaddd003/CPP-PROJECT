#pragma once
#include "operation.h"
#include "..\CMUgraphicsLib\colors.h"
#include "..\shapes/Shape.h"
#include "..\Shapes\Graph.h"
#include "../GUI/GUI.h"
#include "../controller.h"

class opDuplicate : public operation
{
public:
	opDuplicate(controller* pCont);
	~opDuplicate();
	virtual void Execute();

};
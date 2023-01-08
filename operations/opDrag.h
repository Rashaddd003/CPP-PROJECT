#pragma once
#pragma once
#include "operation.h"
#include "..\CMUgraphicsLib\colors.h"
#include "..\shapes/Shape.h"
#include "..\Shapes\Graph.h"
#include "../GUI/GUI.h"
#include "../controller.h"

class opDrag : public operation
{
public:
	opDrag(controller* pCont);
	~opDrag();
	virtual void Execute();

};
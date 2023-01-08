#pragma once
#include "operation.h"
#include "..\CMUgraphicsLib\colors.h"
#include "..\shapes/Shape.h"
#include "..\Shapes\Graph.h"
#include "../GUI/GUI.h"
#include "../controller.h"

class opMatch : public operation
{
public:
	opMatch(controller* pCont);
	~opMatch();
	virtual void Execute();

};
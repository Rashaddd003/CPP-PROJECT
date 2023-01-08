#pragma once
#include "operation.h"
#include "..\CMUgraphicsLib\colors.h"
#include "..\shapes/Shape.h"
#include "../controller.h"
class opStartGame : public operation
{
public:
	opStartGame(controller* pCont);
	~opStartGame();
	virtual void Execute();
};
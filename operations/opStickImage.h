#pragma once
#include "operation.h"
#include "..\CMUgraphicsLib\colors.h"
#include "..\shapes/Shape.h"
#include "../controller.h"
class opStickImage : public operation
{
public:
	opStickImage(controller* pCont);
	~opStickImage();
	virtual void Execute();
};
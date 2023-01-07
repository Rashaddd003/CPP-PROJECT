#pragma once
#include "operation.h"
#include <iostream>
#include <vector>
#include "operation.h"
#include "..\shapes/Shape.h"
#include "..\Shapes\Graph.h"
#include "../GUI/GUI.h"
#include "../controller.h"
using namespace std;

class opPaste : public operation
{
public:
	opPaste(controller* pCont);
	~opPaste();
	virtual void Execute();
};


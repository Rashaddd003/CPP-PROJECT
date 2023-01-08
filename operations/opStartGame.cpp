#include "opStartGame.h"

opStartGame::opStartGame(controller* pCont) : operation(pCont)
{}

opStartGame::~opStartGame()
{
}

void opStartGame::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();


	pGraph->Start(pUI, pGraph);
}



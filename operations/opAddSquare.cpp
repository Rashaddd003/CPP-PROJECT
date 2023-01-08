#include "opAddRect.h"
#include "../Shapes/Square.h"
#include "..\controller.h"
#include "../Shapes/Shape.h"
#include "..\GUI\GUI.h"
#include "opAddSquare.h"

opAddSquare::opAddSquare(controller* pCont) :operation(pCont)
{}
opAddSquare::~opAddSquare()
{}

//Execute the operation
void opAddSquare::Execute()
{
	Point P1;
	double lenght = 4;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	
	pUI->PrintMessage("New Square: Click at first corner");
	//Read center and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	pUI->ClearStatusBar();
	pUI->PrintMessage("Enter the length");
	lenght = stoi(pUI->GetSrting());
	pUI->ClearStatusBar();
	//Preapre all square parameters
	GfxInfo SquareGfxInfo;

	//get drawing, filling colors and pen width from the interface
	SquareGfxInfo.DrawClr = pUI->getCrntDrawColor();
	SquareGfxInfo.FillClr = pUI->getCrntFillColor();
	SquareGfxInfo.BorderWdth = pUI->getCrntPenWidth();

	SquareGfxInfo.isFilled = pUI->isFilled();	//default is not filled
	SquareGfxInfo.isSelected = false;	//defualt is not selected
	SquareGfxInfo.isGrouped = false;


	//Create a square with the above parameters
	Square* S = new Square(P1, lenght, SquareGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the square to the list of shapes
	pGr->Addshape(S);
	pGr->Addoperation("Draw");

}



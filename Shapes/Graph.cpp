#include "Graph.h"
#include "../GUI/GUI.h"
#include <vector>
#include "Graph.h"
#include "../GUI/GUI.h"
#include <sstream>
#include "..\controller.h"
#include "..\Shapes\Circle.h"
#include "..\Shapes\Line.h"
#include "..\Shapes\Rect.h"
#include "..\Shapes\Triangle.h"
#include"..\Shapes\Polygon.h"
#include"..\Shapes\Square.h"
#include "Shape.h"
#include <iostream>
#include "..\CMUgraphicsLib\auxil.h"	// where Pause is found

Graph::Graph()
{
	selectedShape = nullptr;
}

Graph::~Graph()
{
}

//==================================================================================//
//						shapes Management Functions								//
//==================================================================================//

//Add a shape to the list of shapes
void Graph::Addshape(shape* pShp)
{
	//Add a new shape to the shapes vector
	shapesList.push_back(pShp);	
}
void Graph::Addoperation(string x)
{
	LastOperation.push_back(x);
}
////////////////////////////////////////////////////////////////////////////////////
//Draw all shapes on the user interface
void Graph::Draw(GUI* pUI) const
{
	pUI->ClearDrawArea();
	for (auto shapePointer : shapesList)
		shapePointer->Draw(pUI);
	for (auto shapePointer : DuplicateList)
		shapePointer->Draw(pUI);
}
void Graph::DrawDupl(GUI* pUI) const
{
	pUI->ClearDrawArea();
	for (auto shapePointer : DuplicateList)
		shapePointer->Draw(pUI);
}
void Graph::DeleteShapeFromList()
{
	int size;
	size = shapesList.size();
	for (int i = 0; i < shapesList.size(); i++)
	{
		if (shapesList[i]->IsSelected())
		{
			if (shapesList[i]->IsGrouped()) {
				for (int i = 0; i < shapesList.size(); i++) {
					if (shapesList[i]->IsGrouped()) {
						//SelectaShape(shapesList[i], BLUE);
						shapesList.erase(shapesList.begin() + i);
					}
				}
			}
			SelectaShape(shapesList[i], BLUE);
			DeletedshapesList.push_back(shapesList[i]); //store deleted shape
			shapesList.erase(shapesList.begin()+i); //delete &shapePointer;
			
		}
	}
}


shape* Graph::Getshape(int x, int y) const
{
	Point S;
	int counts = 0;
	int countd = 0;
	//If a shape is found return a pointer to it.
	//if this point (x,y) does not belong to any shape return NULL
	for (shape* aShape : shapesList) {
		if (aShape->ClickedInside(x, y))
		{
			counts++;
			return aShape;

		}
	}
	for (shape* aShape : DuplicateList) {
		if (aShape->ClickedInside(x, y))
		{
			countd++;
			return aShape;

		}
	}

	return nullptr;
}

void Graph::SelectaShape(shape* Selected, color oldColor)
{
	if (Selected->IsSelected())
	{
		selectedShape = Selected;
		Selected->SetSelected(false);
		Selected->ChngDrawClr(oldColor);
	}
	else
	{
		Selected->SetSelected(true);
		Selected->ChngDrawClr(MAGENTA);
	}
}
void Graph::Save(ofstream& outfile)
{
	outfile << shapesList.size() << endl;
	for (auto& shapePointer : shapesList)
	{
		shapePointer->Save(outfile);
		shapePointer->setSaved();

	}

	outfile.close();
}

void Graph::load(ifstream& inputfile, GUI* pUI, Graph* pGr)
{
	string x;
	string type;
	int noOfShapes;

	inputfile >> noOfShapes;
	int y = 0;
	shape* p;

	for (int i = 0; i < noOfShapes; i++)
	{
		y++;

		string z;
		inputfile >> type;
		if (type == "Line")
		{
			p = new Line();
			p->Load(inputfile);
			Addshape(p);
		}
		else if (type == "Circle")
		{
			p = new Circle();

			p->Load(inputfile);

			Addshape(p);
		}
		else if (type == "Triangle")
		{
			p = new Triangle();
			p->Load(inputfile);
			Addshape(p);
		}
		else if (type == "Rect")
		{

			p = new Rect();
			p->Load(inputfile);
			Addshape(p);
		}
		else if (type == "RegPoly")
		{
			p = new RegPolygon();
			p->Load(inputfile);
			Addshape(p);

		}
		else if (type =="Square")
		{
			p = new Square();
			p->Load(inputfile);
			Addshape(p);
		}




	}

	inputfile.close();
}

bool Graph::CanExit()
{
	if (shapesList.size() > 0) {
		for (auto* shape : shapesList) {
			if ((shape->IsSaved()) == true)
				return true;
		}
	}
	else
		return false;
}

void Graph::resizeShape(double x)
{
	int size;
	size = shapesList.size();
	for (int i = 0; i < size; i++)
	{
		if (shapesList[i]->IsSelected())
		{
			if (shapesList[i]->IsGrouped()) {
				for (int i = 0; i < shapesList.size(); i++) {
					if (shapesList[i]->IsGrouped()) {
						shapesList[i]->Resize(x);
					}
				}
			}
			else {
				//shape* newpointer = shapesList[i];  
				ResizedShapes.push_back(shapesList[i]); //store shape
				shapesList[i]->Resize(x);
				//Addshape(shapesList[i]);
				LastResize.push_back(x);
			}
			}
		}
	}



shape* Graph::resizeagain(shape* s, double x) {
	s->Resize(x);
	ResizedShapes.push_back(s);
	return s;
}

void Graph::RotateShape()
{
	int size;
	size = shapesList.size();
	for (int i = 0; i<size; i++)
	{
		if (shapesList[i]->IsSelected())
		{
			shapesList[i]->Rotate();
			SelectaShape(shapesList[i], BLUE);
			//Addshape(shapesList[i]);
		}
	}
}

void Graph::dragShape(GUI* pUI, Graph* pGr)
{
	int size;
	size = shapesList.size();
	bool bDragging = false;
	int x = 0;
	int iX = 0, iY = 0;

	int iXOld = 0;
	int iYOld = 0;
	bool first = false;

	do {
		int SHIFTx = 0; int SHIFTy = 0;
		if (bDragging == false ) {
			bDragging = true;
			
			


		}
		else if (bDragging == true && pUI->getIsClicked(iX, iY) == BUTTON_DOWN) {
			/*if (pUI->getIsClicked(iX, iY) == BUTTON_UP) {
				bDragging = false;


			}*/
			if (first == false)
			{
				iXOld = iX;
				iYOld = iY;
				first = true;
				predrag.x = iXOld;
				predrag.y = iYOld;
			}
			else {
				if (iX != iXOld || iY != iYOld) {
					SHIFTx = (iX - iXOld);
					iXOld = iX;
					SHIFTy = (iY - iYOld);
					iYOld = iY;
					for (int i = 0; i < size; i++)
					{
						if (shapesList[i]->IsSelected())
						{
							postdrag.x = iX;
							postdrag.y = iY;
							shapesList[i]->Drag(SHIFTx, SHIFTy);
							draggedshape = shapesList[i];
							pGr->Draw(pUI);
							//Addshape(shapesList[i]);
							x++;
						}
					}
					//first = false;
				}
				
				
				
			}
		}
			

		} while (x<=2 || pUI->getIsClicked(iX, iY) != BUTTON_UP);









}



void Graph::Undo()
{
	if (LastOperation[LastOperation.size() - 1] == "Draw" && LastOperation.size() != 0){
		UndoneDrawing.push_back(shapesList[shapesList.size() - 1]);
		shapesList.erase(shapesList.begin() + shapesList.size()-1);
		LastOperation.erase(LastOperation.begin() + LastOperation.size() - 1);
		undoOperations.push_back("Draw");
	}else if (LastOperation[LastOperation.size() - 1] == "Delete" && LastOperation.size()!=0) {
		Addshape(DeletedshapesList[DeletedshapesList.size() - 1]);
		DeletedshapesList.erase(DeletedshapesList.begin() + DeletedshapesList.size() - 1);
		LastOperation.erase(LastOperation.begin() + LastOperation.size() - 1);
		undoOperations.push_back("Delete");
	}
	else if (LastOperation[LastOperation.size() - 1] == "Resize" && LastOperation.size() != 0) {
		shapesList.erase(shapesList.begin() + shapesList.size() - 1);
		shape* newshape = resizeagain((ResizedShapes[ResizedShapes.size() - 1]), (1/LastResize[LastResize.size() - 1]));
		//shapesList.erase(shapesList.begin() + shapesList.size() - 1);
		Addshape(newshape);
		LastUndoResize.push_back(LastResize[LastResize.size() - 1]);
		ResizedShapesUndo.push_back(ResizedShapes[ResizedShapes.size()-1]);
		ResizedShapes.erase(ResizedShapes.begin() + ResizedShapes.size() - 1);
		LastOperation.erase(LastOperation.begin() + LastOperation.size() - 1);
		undoOperations.push_back("Resize");
	}
	else if (LastOperation[LastOperation.size() - 1] == "Drag" && LastOperation.size() != 0) {
		draggedshape->Drag(predrag.x - postdrag.x,  predrag.y- postdrag.y);
		undoOperations.push_back("Drag");
	}
}

void Graph::Redo()
{
	if (undoOperations[undoOperations.size() - 1] == "Draw" && undoOperations.size() != 0) {
		Addshape(UndoneDrawing[UndoneDrawing.size() - 1]);
		LastOperation.push_back("Draw");
	} else if(undoOperations[undoOperations.size() - 1] == "Delete" && undoOperations.size() != 0){
		DeletedshapesList.push_back(shapesList[shapesList.size() - 1]);
		shapesList.erase(shapesList.begin() + shapesList.size() - 1);
		LastOperation.push_back("Delete");
	}
	else if (undoOperations[undoOperations.size() - 1] == "Resize" && undoOperations.size() != 0) {
		shapesList.erase(shapesList.begin() + shapesList.size() - 1);
		shape* newshape = resizeagain((ResizedShapesUndo[ResizedShapesUndo.size() - 1]), (LastUndoResize[LastUndoResize.size() - 1]));
		Addshape(newshape);
		LastOperation.push_back("Resize");
	}
	else if (undoOperations[undoOperations.size() - 1] == "Drag" && undoOperations.size() != 0) {
		draggedshape->Drag(postdrag.x - predrag.x, postdrag.y - predrag.y);
	}
}





void Graph::Duplicate()
{
	for (auto shapePointer : shapesList)
	{
		Point p1,p2,p3;
		
		//if (shapePointer->type == "Line")
		//{
		//	p1 = shapePointer->Shift1();
		//	p2 = shapePointer->Shift2();
		//	shape* L = shapePointer->duplicate();
		//	DuplicateList.push_back(L);



		//}
		//else if (shapePointer->type == "Circle")
		//{
		//	p1 = shapePointer->Shift1();
		//	p2 = shapePointer->Shift2();
		//	shape* C = shapePointer->duplicate();
		//	DuplicateList.push_back(C);



		//}else if (shapePointer->type == "Rect")
		//{
		//	//p1 = shapePointer->Shift1();
		//	//p2 = shapePointer->Shift2();
			shape* R = shapePointer->duplicate();
			DuplicateList.push_back(R);



		//}else if (shapePointer->type == "Triangle")
		//{/*
		//	p1 = shapePointer->Shift1();
		//	p2 = shapePointer->Shift2();
		//	p3 = shapePointer->Shift2();*/
		//	shape* T = shapePointer->duplicate();
		//	DuplicateList.push_back(T);



		//}
		//else if (shapePointer->type == "RegPoly")
		//{/*
		//	p1 = shapePointer->Shift1();
		//	p2 = shapePointer->Shift2();
		//	p3 = shapePointer->Shift2();*/
		//	shape* Po = shapePointer->duplicate();
		//	DuplicateList.push_back(Po);



		//}
		//else if (shapePointer->type == "Square")
		//{/*
		//	p1 = shapePointer->Shift1();
		//	p2 = shapePointer->Shift2();
		//	p3 = shapePointer->Shift2();*/
		//	shape* Sq = shapePointer->duplicate();
		//	DuplicateList.push_back(Sq);



		//}

		
		

	}
	

}
void Graph::Match(GUI* pUI,Graph* pGr)
{
	int x, y;
	static int score =0;
	pUI->PrintMessage("choose first shape");
	pUI->GetPointClicked(x,y);
	shape* S=pGr->Getshape(x, y);
	if (S == nullptr)
	{

		pUI->PrintMessage("No shape selected" );

	}
	else
	{
		int counts=0, countd =0;
		for (int i = 0; i < shapesList.size(); i++) {
			if (shapesList[i] == S)
			{
				counts=i;
				shapesList[i]->setHideorNot(false);
			}
		}
		for (int i = 0; i < DuplicateList.size(); i++) {
			if (DuplicateList[i] == S)
			{
				counts = i;
				DuplicateList[i]->setHideorNot(false);
			}
		}
		pUI->PrintMessage("choose 2nd shape");
		pUI->GetPointClicked(x, y);
		shape* S2 = pGr->Getshape(x, y);
		if (S2 == nullptr)
		{

			pUI->PrintMessage("No shape selected");
			S->setHideorNot(true);
			S->Hide(pUI);
		}
		else if (S2 != S)
		{
			for (int i = 0; i < shapesList.size(); i++) {
				if (shapesList[i] == S2)
				{
					countd = i;
					shapesList[i]->setHideorNot(false);

				}
			}
			for (int i = 0; i < DuplicateList.size(); i++) {
				if (DuplicateList[i] == S2)
				{
					countd = i;
					DuplicateList[i]->setHideorNot(false);

				}
			}
			if (S->type == S2->type && countd == counts)
			{
				score++;
				pUI->PrintMessage("Great!");
				Pause(500);
				pUI->PrintMessage("Score=");
				Pause(400);
				pUI->PrintMessage(to_string(score));
				for (int i = 0; i < shapesList.size(); i++) {
					if (shapesList[i] == S2)
					{
						shapesList.erase(shapesList.begin()+i);
						DuplicateList.erase(DuplicateList.begin() + i);
					}
					if (DuplicateList[i] == S2)
					{
						DuplicateList.erase(DuplicateList.begin() + i);
						shapesList.erase(shapesList.begin() + i);
					}
				}
				if (shapesList.size() == 0) {
					pUI->PrintMessage("Mabrok");
					exit(0);
				}
			}
			else
			{
				score--;
				pUI->PrintMessage("Missmatch! ... Try Again!");
				Pause(500);
				pUI->PrintMessage("(-1) Score=");
				Pause(450);
				pUI->PrintMessage(to_string(score));
				S->setHideorNot(true);
				S2->setHideorNot(true);
				S->Hide(pUI);
				S2->Hide(pUI);
			}
			}
		
	}
}




void Graph::GroupShapes(GUI* pUI)
{
	int size;
	string is;
	size = shapesList.size();
	for (int i = 0; i < size; i++)
	{
		if (shapesList[i]->IsSelected() && shapesList[i]->IsGrouped()==false)
		{
			shapesList[i]->setGrouped(true);
			is = "grouped";
		}
		else if (shapesList[i]->IsSelected() && shapesList[i]->IsGrouped() == true) {
			for (int i = 0; i < size; i++)
			{
				shapesList[i]->setGrouped(false);
				is = "notgrouped";
			}
		}
	}
	if (is == "grouped") {
		pUI->PrintMessage("shapes have been grouped");
	}
	else if (is == "notgrouped") {
		pUI->PrintMessage("shapes have been ungrouped");
	}
	else {
		pUI->PrintMessage("you haven't selected any shapes");
	}
}

void Graph::StickingImage(GUI* pGUI) const
{
	for (shape* aShape : shapesList) {
		if (aShape->getImagePresentState())
		{
			aShape->Stick(pGUI);
		}
	}
}

void Graph::HideAShape(GUI* pGUI) const
{
	for (shape* aShape : shapesList) {
		if (aShape->getHideorNot())
		{
			aShape->Hide(pGUI);
		}
	}
}

void Graph::unHideAShape(GUI* pGUI) const
{
	for (shape* aShape : shapesList) {
		if (aShape->getHideorNot() == false)
		{
			aShape->Hide(pGUI);
		}
	}
}

void Graph::Scramble()
{
	srand(time(0));

	int dx, dy;

	for (int i = 0; i < shapesList.size(); i++) {

		dy = 350 + (rand() % 350);
		dx = 250 + (rand() % 1000);
		cout << "   X == " << dx << "   Y ===  " << dy << endl;
		if (Getshape(dx, dy) == nullptr)
			shapesList[i]->ScrambleShape(dx, dy);
	}
}
void Graph::Start(GUI* pUI, Graph* pGrp)
{
	pUI->PrintMessage("Welcome");
	if (shapesList.size() <= 5) {
		pGrp->Duplicate();
		pGrp->Scramble();
		Pause(50);
		pUI->PrintMessage("Get Ready!!!!");
		for (int i = 0; i < shapesList.size(); i++) {
			shapesList[i]->setHideorNot(true);
			DuplicateList[i]->setHideorNot(true);
			shapesList[i]->Hide(pUI);
			DuplicateList[i]->Hide(pUI);
		}
		while(1){
		pGrp->Match(pUI, pGrp);
		}
	}


}


void Graph::CopyShape()
{
	Clipboard.clear();
	for (shape* aShape : shapesList) {
		if (aShape->IsSelected())
		{
			Clipboard.push_back(aShape);
		}

	}
}

void Graph::oppPasteShape()
	{
		for (shape* aShape : Clipboard) {
			if (aShape)
			{
				shapesList.push_back(aShape->PasteShape());
			}
		}
	}

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
	for (auto shapePointer : shapesList) {
		StickingImage(pUI);
		shapePointer->Draw(pUI);

	}
}

void Graph::DeleteShapeFromList()
{
	int size, count;
	size = shapesList.size();
	count = 0;
	for (auto &shapePointer : shapesList)
	{
		
		if (shapePointer->IsSelected())
		{
			SelectaShape(shapePointer, BLUE);
			//shape* newpointertoshape = shapePointer;
			DeletedshapesList.push_back(shapePointer); //store deleted shape
			shapesList.erase(shapesList.begin()+count); //delete &shapePointer;
			count--;
		}
		count++;
	}
}


shape* Graph::Getshape(int x, int y) const
{
	//If a shape is found return a pointer to it.
	//if this point (x,y) does not belong to any shape return NULL
	for (shape* aShape : shapesList) {
		if (aShape->ClickedInside(x, y))
		{
			return aShape;

		}
	}	
	return nullptr;
}


void Graph::CopyShape()
{
	/*Clipboard.clear();
	for (shape* aShape : shapesList) {
		if (aShape->IsSelected())
		{
			Clipboard.push_back(aShape);
		}
	}*/
	Scramble();
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
		/*else if (type == "RegPoly")
		{
			p = new RegPolygon();
			p->Load(inputfile);
			Addshape(p);

		}*/
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
			//shape* newpointer = shapesList[i];  
			ResizedShapes.push_back(shapesList[i]); //store shape
			shapesList[i]->Resize(x);
			Addshape(shapesList[i]);
			LastResize.push_back(x);
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
			Addshape(shapesList[i]);
		}
	}
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

void Graph::Scramble()
{
	srand(time(0));
	
	int dx, dy;
	
	for (int i = 0; i < shapesList.size(); i++) {
		
		dy = 350 + (rand() % 350);
		dx = 250 + (rand() % 1000);
		cout <<"   X == " << dx << "   Y ===  " << dy << endl;
		if (Getshape(dx, dy) == nullptr)
			shapesList[i]->ScrambleShape(dx, dy);
	}
}



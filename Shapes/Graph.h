#pragma once
#include "Shape.h"
#include <fstream>
#include <vector>
using namespace std;

//forward decl
class GUI;	

//A class that is responsible on everything related to shapes
class Graph
{
private:
	vector <string> undoOperations;
	vector <double> LastResize;
	vector <string> LastOperation;
	vector <shape*> shapesList; //a container to hold all shapes
	vector <shape*> DeletedshapesList; //container to hold the deleted shapes
	vector <shape*> UndoneDrawing;
	vector <shape*> ResizedShapesUndo;
	vector <double> LastUndoResize;
	vector <shape*> ResizedShapes; //container to the resized shapes
	shape* selectedShape;	//pointer to the currently selected shape


	
public:										
	Graph();
	~Graph();
	void Addshape(shape* pFig); //Adds a new shape to the shapesList
	void Addoperation(string);
	void Draw(GUI* pUI) const;			//Draw the graph (draw all shapes)
	void DeleteShapeFromList();
	shape* Getshape(int x, int y) const; //Search for a shape given a point inside the shape
	void SelectaShape(shape* Selected, color oldColor);
	void Save(ofstream& outfile);	//Save all shapes to a file
	void load(ifstream& inputfile, GUI* pUI, Graph* pGr);	//Load all shapes from a file
	bool CanExit();
	void resizeShape(double);
	shape* resizeagain(shape* s, double x);
	void RotateShape();
	void Undo();
	void Redo();
};

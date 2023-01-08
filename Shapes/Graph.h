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
	vector <shape*> DuplicateList;
	vector <double> LastUndoResize;
	vector <shape*> ResizedShapes; //container to the resized shapes
	shape* selectedShape;	//pointer to the currently selected shape
	vector <shape*> Clipboard; //a container to hold all copied shapes


	
public:										
	Graph();
	~Graph();
	void Addshape(shape* pFig); //Adds a new shape to the shapesList
	void Addoperation(string);
	void Draw(GUI* pUI) const;			//Draw the graph (draw all shapes)
	void DrawDupl(GUI* pUI) const;			//Draw the graph (draw duplicated shapes)
	void DeleteShapeFromList();
	shape* Getshape(int x, int y) const; //Search for a shape given a point inside the shape
	void SelectaShape(shape* Selected, color oldColor);
	void Save(ofstream& outfile);	//Save all shapes to a file
	void load(ifstream& inputfile, GUI* pUI, Graph* pGr);	//Load all shapes from a file
	bool CanExit();
	void resizeShape(double);
	shape* resizeagain(shape* s, double x);
	void RotateShape();
	void dragShape(GUI* pUI, Graph* pGr);
	void Duplicate();
	void Undo();
	void Redo();
	void Match(GUI* pUI,Graph* pGr );
	Point Matchcheck(Point x);
	void GroupShapes(GUI* pUI);
	void CopyShape();
	void oppPasteShape();
	void StickingImage(GUI* pGUI) const;
	void HideAShape(GUI* pGUI) const;
	void unHideAShape(GUI* pGUI) const;
	void Scramble();
};

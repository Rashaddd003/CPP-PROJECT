#pragma once
#include "Shape.h"
#include <vector>
#include <cmath>
#include <algorithm>
class Square : public shape
{
private:
	Point Corner1;
	Point Corner2;
	double Length;
	//Point center;
	//Point StPt;
	//int sides;
	//vector <int> Vertexx;
	//vector <int> Vertexy;
public:
	Square();
	Square(Point , double, GfxInfo );
	virtual ~Square();
	//void SetVertices();
	virtual void Draw(GUI* pUI) const;
	virtual bool ClickedInside(int x, int y) const;
	shape* PasteShape() override;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Outfile);
	void Stick(GUI* pGUI) override;
	virtual void Resize(double x);
	virtual void Rotate();
};

#pragma once
#include "Shape.h"


class Circle : public shape
{
private:
	Point center;
	Point radius;
public:
	Circle();
	Circle(Point p1, Point p2, GfxInfo shapeGfxInfo);
	virtual ~Circle();
	virtual void Draw(GUI* pUI) const;
	virtual bool ClickedInside(int x, int y) const;

	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Outfile);
	virtual void Resize(double x);
	virtual void Rotate();
	virtual void Drag(int x, int y);
	virtual Point Shift1();
	virtual Point Shift2();
	virtual shape* duplicate();

};

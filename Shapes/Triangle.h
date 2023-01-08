#pragma once
#include "Shape.h"


class Triangle : public shape
{
private:
	Point corner1;
	Point corner2;
	Point corner3;
public:
	Triangle();
	Triangle(Point p1, Point p2, Point p3, GfxInfo shapeGfxInfo);
	virtual ~Triangle();
	virtual bool ClickedInside(int x, int y) const;
	virtual void Draw(GUI* pUI) const;

	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Outfile);
	virtual void Resize(double x);
	virtual void Rotate();
	virtual void Drag(int x, int y);
	virtual Point Shift1();
	virtual Point Shift2();
	Point Shift3();
	virtual shape* duplicate();

};

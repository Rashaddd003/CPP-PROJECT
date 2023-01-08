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
	virtual bool ClickedInside(int x, int y) const override;
	virtual void Draw(GUI* pUI) const override;
	virtual shape* PasteShape() override;
	virtual void Save(ofstream& OutFile) override;
	virtual void Load(ifstream& Outfile) override;
	virtual void Resize(double x) override;
	virtual void Stick(GUI* pGUI) override;
	virtual void Rotate() override;
	virtual void ScrambleShape(double shiftx, double shifty) override;
	virtual int GetMaxX() override;
	virtual int GetMaxY() override;
	virtual void Hide(GUI* pGUI) override;
};

#pragma once

#include "shape.h"

class Line : public shape
{
private:
	Point point1;
	Point point2;
	GfxInfo copyGFX;
	
public:
	Line();
	Line(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Line();
	Line(const Line& lineo);
	virtual void Draw(GUI* pUI) const;
	virtual bool ClickedInside(int x, int y) const;

	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Outfile);
	virtual void Resize(double x);
	virtual void Rotate();
	virtual void ScrambleShape(double shiftx, double shifty) override;
	virtual int GetMaxX() override;
	virtual int GetMaxY() override;
	virtual void Hide(GUI* pGUI) override;
	virtual void Drag(int x, int y);
	virtual Point Shift1();
	virtual Point Shift2();
	virtual shape* duplicate();
};


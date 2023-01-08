#pragma once

#include "shape.h"

class Line : public shape
{
private:
	Point point1;
	Point point2;
	
public:
	Line();
	Line(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Line();
	virtual void Draw(GUI* pUI) const;
	virtual bool ClickedInside(int x, int y) const;
	shape* PasteShape();
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Outfile);
	virtual void Resize(double x);
	void Stick(GUI* pGUI) override;
	virtual void Rotate();
	virtual void ScrambleShape(double shiftx, double shifty) override;
	virtual int GetMaxX() override;
	virtual int GetMaxY() override;
	virtual void Hide(GUI* pGUI) override;
};


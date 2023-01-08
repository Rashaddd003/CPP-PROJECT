#pragma once

#include "shape.h"

class Rect : public shape
{
private:
	Point Corner1;	
	Point Corner2;
public:
	Rect();
	Rect(Point , Point, GfxInfo shapeGfxInfo );
	virtual ~Rect();
	virtual void Draw(GUI* pUI) const;
	virtual bool ClickedInside(int x, int y) const;
	shape* PasteShape() override;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Outfile);
	virtual void Resize(double x);
	void Stick(GUI* pGUI) override;
	virtual void Hide(GUI* pGUI) override;
	virtual void Rotate();
	virtual void ScrambleShape(double shiftx, double shifty) override;
	virtual int GetMaxX() override;
	virtual int GetMaxY() override;
};


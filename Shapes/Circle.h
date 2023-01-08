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

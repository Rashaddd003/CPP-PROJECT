#pragma once
#include "Shape.h"
#include <vector>
#include <cmath>


class RegPolygon : public shape
{
private:
	Point center;
	Point StPt;
	int sides;
	vector <int> Vertexx;
	vector <int> Vertexy;
public:
	RegPolygon();
	RegPolygon(Point p1,Point Stp2 ,int vertices, GfxInfo shapeGfxInfo);
	virtual ~RegPolygon();
	void SetVertices();
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
	virtual shape* PasteShape() override;
	virtual void Stick(GUI* pGUI) override;
	virtual void ScrambleShape(double shiftx, double shifty) override;
	virtual int GetMaxX() override;
	virtual int GetMaxY() override;
	virtual void Hide(GUI* pGUI) override;
	int getSides();

};

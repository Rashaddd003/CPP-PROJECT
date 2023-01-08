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
	int getSides();
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

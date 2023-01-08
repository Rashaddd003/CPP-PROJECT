#include "Triangle.h"

Triangle::Triangle()
{

}

Triangle::Triangle(Point p1, Point p2, Point p3, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	corner1 = p1;
	corner2 = p2;
	corner3 = p3;
	type = "Triangle";
}

Triangle::~Triangle()
{}

bool Triangle::ClickedInside(int x, int y) const
{
		int as_x = x - corner1.x;
		int as_y = y - corner1.y;

		bool s_ab = (corner2.x - corner1.x) * as_y - (corner2.y - corner1.y) * as_x > 0;

		if ((corner3.x - corner1.x) * as_y - (corner3.y - corner1.y) * as_x > 0 == s_ab) return false;

		if ((corner3.x - corner2.x) * (y - corner2.y) - (corner3.y - corner2.y) * (x - corner2.x) > 0 != s_ab) return false;

		return true;
}

void Triangle::Draw(GUI * pUI) const
{
	pUI->DrawTriangle(corner1, corner2, corner3, ShpGfxInfo);
}
void Triangle::Save(ofstream& OutFile)
{
	OutFile << type << " " << corner1.x << " " << corner1.y << " " << corner2.x << " " << corner2.y << " " << corner3.x << " " << corner3.y << " " << (ShpGfxInfo.isFilled) << " " << to_string(ShpGfxInfo.FillClr.ucRed) << " " << to_string(ShpGfxInfo.FillClr.ucGreen) << " " << to_string(ShpGfxInfo.FillClr.ucBlue) << " " << to_string(ShpGfxInfo.DrawClr.ucRed) << " " << to_string(ShpGfxInfo.DrawClr.ucGreen) << " " << to_string(ShpGfxInfo.DrawClr.ucBlue) << " " << (ShpGfxInfo.BorderWdth) << endl;

}

void Triangle::Load(ifstream& inFile)
{
	type = "Triangle";
	int x;
	string jump;

	inFile >> x;
	corner1.x = x;

	inFile >> x;
	corner1.y = x;

	inFile >> x;

	corner2.x = x;

	inFile >> x;
	corner2.y = x;

	inFile >> x;
	corner3.x = x;

	inFile >> x;
	corner3.y = x;
	inFile >> x;
	if (x == 0)
	{
		ShpGfxInfo.isFilled = FALSE;

	}
	else if (x == 1)
	{
		ShpGfxInfo.isFilled = TRUE;

	}
	inFile >> jump;

	ShpGfxInfo.FillClr.ucRed = stoi(jump);
	inFile >> jump;

	ShpGfxInfo.FillClr.ucGreen = stoi(jump);
	inFile >> jump;

	ShpGfxInfo.FillClr.ucBlue = stoi(jump);
	inFile >> jump;

	ShpGfxInfo.DrawClr.ucRed = stoi(jump);
	inFile >> jump;

	ShpGfxInfo.DrawClr.ucGreen = stoi(jump);
	inFile >> jump;

	ShpGfxInfo.DrawClr.ucBlue = stoi(jump);
	inFile >> x;

	ShpGfxInfo.BorderWdth = x;

	ShpGfxInfo.isSelected = FALSE;
}

void Triangle::Resize(double x)
{
	corner2.x = corner1.x + ((x) * (corner2.x - corner1.x));
	corner2.y = corner1.y + ((x) * (corner2.y - corner1.y));
	corner3.x = corner1.x + ((x) * (corner3.x - corner1.x));
	corner3.y = corner1.y + ((x) * (corner3.y - corner1.y));
}

void Triangle::Rotate()
{
	Point center;
	center.x = (corner1.x + corner2.x + corner3.x) / 3;
	center.y = (corner1.y + corner2.y + corner3.y) / 3;
	int swap = corner1.x;
	corner1.x = -corner1.y + center.x + center.y;
	corner1.y = swap - center.x + center.y;
	int swap1 = corner2.x;
	corner2.x = -corner2.y + center.x + center.y;
	corner2.y = swap1 - center.x + center.y;
	int swap3 = corner3.x;
	corner3.x = -corner3.y + center.x + center.y;
	corner3.y = swap3 - center.x + center.y;
}

void Triangle::Drag(int x, int y)
{
	corner1.x = corner1.x + x;
	corner1.y = corner1.y + y;
	corner2.x = corner2.x + x;
	corner2.y = corner2.y + y;
	corner3.x = corner3.x + x;
	corner3.y = corner3.y + y;
}

Point Triangle::Shift1()
{
	Point p1;
	p1.x = corner1.x + 5;
	//p2.x = point2.x + 5;
	p1.y = corner1.y + 5;
	//p2.y = point2.y + 5;

	return p1;
}
Point Triangle::Shift2()
{
	Point  p2;
	p2.x = corner2.x + 5;
	//p2.x = point2.x + 5;
	p2.y = corner2.y + 5;
	//p2.y = point2.y + 5;

	return p2;

}
Point Triangle::Shift3()
{
	Point  p3;
	p3.x = corner3.x + 5;
	//p2.x = point2.x + 5;
	p3.y = corner3.y + 5;
	//p2.y = point2.y + 5;

	return p3;
}

shape* Triangle::duplicate()
{
	Point p1;
	p1.x = corner1.x + 60;
	//p2.x = point2.x + 5;
	p1.y = corner1.y + 5;
	//p2.y = point2.y + 5;


	Point  p2;
	p2.x = corner2.x + 60;
	//p2.x = point2.x + 5;
	p2.y = corner2.y + 5;
	//p2.y = point2.y + 5;

	Point  p3;
	p3.x = corner3.x + 60;
	//p2.x = point2.x + 5;
	p3.y = corner3.y + 5;

	return new Triangle(p1,p2,p3,ShpGfxInfo);
}

shape* Triangle::PasteShape()
{
	Point corner11, corner22, corner33;
	corner11.x = corner1.x + 20;
	corner11.y = corner1.y - 20;
	corner22.x = corner2.x + 20;
	corner22.y = corner2.y - 20;
	corner33.x = corner3.x + 20;
	corner33.y = corner3.y - 20;
	return new Triangle(corner11, corner22, corner33, ShpGfxInfo);

}
void Triangle::Stick(GUI* pGUI)
{
	double MaxPx = max(max(corner1.x, corner2.x), corner3.x);
	double MinPx = min(min(corner1.x, corner2.x), corner3.x);
	double MaxPy = max(max(corner1.y, corner2.y), corner3.y);
	double MinPy = min(min(corner1.y, corner2.y), corner3.y);
	Point P;
	P.x = MinPx;
	P.y = MinPy;
	int width = MaxPx - MinPx;
	int length = MaxPy - MinPy;
	string name = "images\\MenuIcons\\idkk.jpg";
	pGUI->StickImage(name, P, width, length);
}


void Triangle::ScrambleShape(double shiftx, double shifty)
{
	int Dx = corner1.x - shiftx;
	int Dy = corner1.y - shifty;
	corner1.x = shiftx;
	corner1.y = shifty;

	corner2.x -= Dx;
	corner3.x -= Dx;
	corner2.y -= Dy;
	corner3.y -= Dy;
}
int Triangle::GetMaxX()
{
	return max(max(corner1.x, corner2.x), corner3.x);
}

int Triangle::GetMaxY()
{
	return max(max(corner1.y, corner2.y), corner3.y);
}

void Triangle::Hide(GUI* pGUI)
{
	if (Hidden)
	{
		double MaxPx = max(max(corner1.x, corner2.x), corner3.x);
		double MinPx = min(min(corner1.x, corner2.x), corner3.x);
		double MaxPy = max(max(corner1.y, corner2.y), corner3.y);
		double MinPy = min(min(corner1.y, corner2.y), corner3.y);
		Point P;
		P.x = MinPx;
		P.y = MinPy;
		int width = MaxPx - MinPx;
		int length = MaxPy - MinPy;
		string name = "images\\MenuIcons\\HideCard.jpg";
		pGUI->StickImage(name, P, width, length);
	}
}
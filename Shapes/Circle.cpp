#include "Circle.h"

Circle::Circle()
{

}

Circle::Circle(Point p1, Point p2, GfxInfo shapeGfxInfo):shape(shapeGfxInfo)
{
	center = p1;
	radius = p2;
	type = "Circle";
}

Circle::~Circle()
{}

void Circle::Draw(GUI * pUI) const
{
	pUI->DrawCircle(center, radius, ShpGfxInfo);
}

bool Circle::ClickedInside(int x, int y) const
{
	double ClickedRadius, radiuss;

	ClickedRadius = sqrt(pow((x - center.x), 2) + pow((y - center.y), 2));
	radiuss = sqrt(pow((radius.x - center.x), 2) + pow((radius.y - center.y), 2));
	if (ClickedRadius <= radiuss)
		return true;
	else
		return false;
}
shape* Circle::PasteShape()
{
	Point P1, P2;
	P1.x = center.x + 20;
	P1.y = center.y - 20;
	P2.x = radius.x + 20;
	P2.y = radius.y - 20;
	return new Circle(P1, P2, ShpGfxInfo);
}
void Circle::Save(ofstream& OutFile)
{
	OutFile << type << " " << center.x << " " << center.y << " " << radius.x << " " << radius.y << " " << ShpGfxInfo.isFilled;
	OutFile << " " << to_string(ShpGfxInfo.FillClr.ucRed) << " " << to_string(ShpGfxInfo.FillClr.ucGreen) << " " << to_string(ShpGfxInfo.FillClr.ucBlue) << " " << to_string(ShpGfxInfo.DrawClr.ucRed) << " " << to_string(ShpGfxInfo.DrawClr.ucGreen) << " " << to_string(ShpGfxInfo.DrawClr.ucBlue) << " " << (ShpGfxInfo.BorderWdth) << endl;

}
void Circle::Load(ifstream& inFile)
{
	type = "Circle";
	int x;
	string jump;

	inFile >> x;
	center.x = x;

	inFile >> x;
	center.y = x;

	inFile >> x;

	radius.x = x;

	inFile >> x;
	radius.y = x;

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

void Circle::Resize(double x)
{
	radius.x = center.x + ((x) * (radius.x - center.x));
	radius.y = center.y + ((x) * (radius.y - center.y));
}

void Circle::Stick(GUI* pGUI)
{
	double radiuss = sqrt(pow((radius.x - center.x), 2) + pow((radius.y - center.y), 2));
	Point P;
	P.x = center.x - radiuss;
	P.y = center.y - radiuss;
	int width = radiuss * 2;
	int length = width;
	string name = "images\\MenuIcons\\idkk.jpg";
	pGUI->StickImage(name, P, width, length);
}

void Circle::Rotate()
{
}




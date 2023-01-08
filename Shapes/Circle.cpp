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

void Circle::Rotate()
{
}

void Circle::Drag(int x, int y)
{
	center.x = center.x + x;
	center.y = center.y + y;
	radius.x = radius.x + x;
	radius.y = radius.y + y;

}

Point Circle::Shift1() 
{
	Point p1;
	p1.x = center.x + 60;
	//p2.x = point2.x + 5;
	p1.y = center.y + 5;
	//p2.y = point2.y + 5;

	return p1;
}
Point Circle::Shift2()
{
	Point  p2;
	p2.x = radius.x + 60;
	//p2.x = point2.x + 5;
	p2.y = radius.y + 5;
	//p2.y = point2.y + 5;

	return p2;
}

shape* Circle::duplicate()
{

	Point p1;
	p1.x = center.x + 60;
	//p2.x = point2.x + 5;
	p1.y = center.y;
	Point  p2;
	p2.x = radius.x + 60;
	//p2.x = point2.x + 5;
	p2.y = radius.y;

	return new Circle(p1, p2, ShpGfxInfo);
}



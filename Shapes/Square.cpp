#include "Square.h"
#include <cmath>
using namespace std;

Square::Square()
{

}

Square::Square(Point p1, double lenght, GfxInfo shapeGfxInfo):shape(shapeGfxInfo)
{
	Corner1 = p1;
    //center = p1;
    //StPt = p2;
    //sides = 4;
    //SetVertices();
    //type = "Square";
	Corner2.x = Corner1.x + lenght;
	Corner2.y = Corner1.y + lenght;
	
}

Square::~Square()
{
}

void Square::Draw(GUI* pUI) const
{
		
	//Call Output::DrawRect to draw a square on the screen	:3
    pUI->DrawRect(Corner1, Corner2, ShpGfxInfo);
}

bool Square::ClickedInside(int x, int y) const
{
	float Minx = min(Corner1.x, Corner2.x);
	float Maxx = max(Corner1.x, Corner2.x);
	float Miny = min(Corner1.y, Corner2.y);
	float Maxy = max(Corner1.y, Corner2.y);

	if (x<Maxx && x >Minx && y<Maxy && y >Miny)
	{
		return true;
	}
	else
	{
		return false;
	}

}


void Square::Save(ofstream& OutFile)
{
	OutFile << "Square" << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " " << (ShpGfxInfo.isFilled) << " " << to_string(ShpGfxInfo.FillClr.ucRed) << " " << to_string(ShpGfxInfo.FillClr.ucGreen) << " " << to_string(ShpGfxInfo.FillClr.ucBlue) << " " << to_string(ShpGfxInfo.DrawClr.ucRed) << " " << to_string(ShpGfxInfo.DrawClr.ucGreen) << " " << to_string(ShpGfxInfo.DrawClr.ucBlue) << " " << (ShpGfxInfo.BorderWdth) << endl;

}

void Square::Load(ifstream& inFile)
{
	type = "Square";
	int x;
	string jump;

	inFile >> x;
	Corner1.x = x;

	inFile >> x;
	Corner1.y = x;

	inFile >> x;

	Corner2.x = x;

	inFile >> x;
	Corner2.y = x;

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


void Square::Resize(double x)
{

	Corner2.x *= x;
	Corner2.x -= (x - 1) * Corner1.x;
	Corner2.y *= x;
	Corner2.y -= (x - 1) * Corner1.y;

}

void Square::Rotate()
{
	Point center;
	center.x = Corner1.x + ((Corner2.x - Corner1.x) / 2);
	center.y = Corner1.y + ((Corner2.y - Corner1.y) / 2);
	int swap = Corner1.x;
	Corner1.x = -Corner1.y + center.x + center.y;
	Corner1.y = swap - center.x + center.y;
	int swap1 = Corner2.x;
	Corner2.x = -Corner2.y + center.x + center.y;
	Corner2.y = swap1 - center.x + center.y;
}

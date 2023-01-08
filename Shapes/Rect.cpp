#include "Rect.h"

Rect::Rect()
{

}

Rect::Rect(Point P1, Point P2, GfxInfo shapeGfxInfo):shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	type = "Rect";
}

Rect::~Rect()
{}

void Rect::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawRect(Corner1, Corner2, ShpGfxInfo);
}

bool Rect::ClickedInside(int x, int y) const
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

shape* Rect::PasteShape()
{
	Point Corner11, Corner22;
	Corner11.x = Corner1.x + 20;
	Corner11.y = Corner1.y - 20;
	Corner22.x = Corner2.x + 20;
	Corner22.y = Corner2.y - 20;

	return new Rect(Corner11, Corner22, ShpGfxInfo);

}

void Rect::Save(ofstream& OutFile)
{
	OutFile << type << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " " << (ShpGfxInfo.isFilled) << " " << to_string(ShpGfxInfo.FillClr.ucRed) << " " << to_string(ShpGfxInfo.FillClr.ucGreen) << " " << to_string(ShpGfxInfo.FillClr.ucBlue) << " " << to_string(ShpGfxInfo.DrawClr.ucRed) << " " << to_string(ShpGfxInfo.DrawClr.ucGreen) << " " << to_string(ShpGfxInfo.DrawClr.ucBlue) << " " << (ShpGfxInfo.BorderWdth) << endl;

}

void Rect::Load(ifstream& inFile)
{
	type = "Rect";
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

void Rect::Resize(double x)
{
	
	Corner2.x *= x;
	Corner2.x -=(x-1)*Corner1.x;
	Corner2.y *= x;
	Corner2.y-=(x-1)*Corner1.y;
	
}

void Rect::Stick(GUI* pGUI)
{
	Point P;
	P.x = Corner1.x;
	P.y = Corner1.y;
	int width = abs(Corner1.x - Corner2.x);
	int length = abs(Corner1.y - Corner2.y);
	string name = "images\\MenuIcons\\idkk.jpg";
	pGUI->StickImage(name, P, width, length);
}

void Rect::Hide(GUI* pGUI)
{
	if (Hidden)
	{
		Point P;
		P.x = Corner1.x;
		P.y = Corner1.y;
		int width = abs(Corner1.x - Corner2.x);
		int length = abs(Corner1.y - Corner2.y);
		string name = "images\\MenuIcons\\HideCard.jpg";
		pGUI->StickImage(name, P, width, length);
	}
	else
	{

	}


}

void Rect::Rotate()
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

void Rect::ScrambleShape(double shiftx, double shifty)
{

	int Dx = Corner1.x - shiftx;
	int Dy = Corner1.y - shifty;
	Corner1.x = shiftx;
	Corner1.y = shifty;
	Corner2.x -= Dx;
	Corner2.y -= Dy;
}

int Rect::GetMaxX()
{
	return max(Corner1.x, Corner2.x);
}

int Rect::GetMaxY()
{
	return max(Corner1.y, Corner2.y);
}

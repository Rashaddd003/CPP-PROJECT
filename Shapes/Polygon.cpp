#include "Polygon.h"
#include <cmath>


RegPolygon::RegPolygon(Point p1, Point p2, int nsides, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	center = p1;
    StPt = p2;
    sides = nsides;
    SetVertices();
    type = "RegPoly";
}

RegPolygon::~RegPolygon()
{}

void RegPolygon::SetVertices()
{
    float pi = 3.14159265358979323846;
    vector<int> VerX = { (StPt.x - center.x) };
    vector<int> VerY = { (StPt.y - center.y) };
    for (int i = 0; i < sides; i++)
    {
        int vx = ceil((VerX[i] * cos((2 * pi) / sides)) - (VerY[i] * sin((2 * pi) / sides))); //Matrix transofmation after translating to origin
        int vy = ceil((VerX[i] * sin((2 * pi) / sides)) + (VerY[i] * cos((2 * pi) / sides)));

        VerX.push_back(vx);
        VerY.push_back(vy);
    }
    for (int i = 0; i < sides; i++) { VerX[i] += center.x; VerY[i] += center.y; }
    Vertexx = VerX;
    Vertexy = VerY;

}

int RegPolygon::getSides()
{
	return sides;
}

void RegPolygon::Draw(GUI* pUI) const
{
	pUI->DrawPolygon(Vertexx, Vertexy,sides, ShpGfxInfo);
}

bool RegPolygon::ClickedInside(int x, int y) const
{

        int i, j, c = 0;
        for (i = 0, j = sides - 1; i < sides; j = i++) {
            if (((Vertexy[i] > y) != (Vertexy[j] > y)) &&
                (x < (Vertexx[j] - Vertexx[i]) * (y - Vertexy[i]) / (Vertexy[j] - Vertexy[i]) + Vertexx[i]))
                c = !c;
        }
        return c;
}

shape* RegPolygon::PasteShape()
{
	Point C1, St1;
	C1.x=center.x + 20;
	C1.y=center.y - 20;
	St1.x= StPt.x+20;
	St1.y= StPt.y-20;
	return new RegPolygon(C1, St1, getSides(), getShpGfx());
}


void RegPolygon::Save(ofstream& OutFile)
{
    OutFile << type << " " <<sides<<" "<<center.x << " " << center.y << " " << StPt.x << " " << StPt.y << " " << ShpGfxInfo.isFilled;
    OutFile << " " << to_string(ShpGfxInfo.FillClr.ucRed) << " " << to_string(ShpGfxInfo.FillClr.ucGreen) << " " << to_string(ShpGfxInfo.FillClr.ucBlue) << " " << to_string(ShpGfxInfo.DrawClr.ucRed) << " " << to_string(ShpGfxInfo.DrawClr.ucGreen) << " " << to_string(ShpGfxInfo.DrawClr.ucBlue) << " " << (ShpGfxInfo.BorderWdth) << endl;
}

void RegPolygon::Load(ifstream& inFile)
{
	/*type = "RegPoly";
	int x;
	string jump;

	inFile >> x;
	sides = x;
	inFile >> x;
	center.x = x;

	inFile >> x;
	center.y = x;

	inFile >> x;

	StPt.x = x;

	inFile >> x;
	StPt.y = x;

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
	SetVertices();*/



}

void RegPolygon::Resize(double x)
{
	for (int i = 0; i < sides; i++) {
		Vertexx[i] = center.x + ((x) * (Vertexx[i] - center.x));
		Vertexy[i] = center.y + ((x) * (Vertexy[i] - center.y));
	}
}

void RegPolygon::Stick(GUI* pGUI)
{
	double radiuss = sqrt(pow((StPt.x - center.x), 2) + pow((StPt.y - center.y), 2));
	Point P;
	P.x = center.x - radiuss;
	P.y = center.y - radiuss;
	int width = radiuss * 2;
	int length = width;
	string name = "images\\MenuIcons\\idkk.jpg";
	pGUI->StickImage(name, P, width, length);


}

void RegPolygon::Hide(GUI* pGUI)
{

	if (Hidden)
	{
		double radiuss = sqrt(pow((StPt.x - center.x), 2) + pow((StPt.y - center.y), 2));
		Point P;
		P.x = center.x - radiuss;
		P.y = center.y - radiuss;
		int width = radiuss * 2;
		int length = width;
		string name = "images\\MenuIcons\\HideCard.jpg";
		pGUI->StickImage(name, P, width, length);
	}

}


void RegPolygon::Rotate()
{
	int swap1;
	for (int i = 0; i < sides; i++) {
		swap1 = Vertexx[i];
		Vertexx[i] = -Vertexy[i]+center.y+center.x;
		Vertexy[i] = swap1-center.x+center.y;

	}
}


void RegPolygon::ScrambleShape(double shiftx, double shifty)
{
	int Dx = Vertexx[0] - shiftx;
	int Dy = Vertexy[0] - shifty;
	Vertexx[0] = shiftx;
	Vertexy[0] = shifty;
	for (int i = 1; i < sides; i++) {
		Vertexx[i] -= Dx ;
		Vertexy[i] -= Dy ;
	}
}

int RegPolygon::GetMaxX()
{
	return max(center.x, StPt.x);
}

int RegPolygon::GetMaxY()
{
	return max(center.y, StPt.y);

void RegPolygon::Drag(int x, int y)
{
	center.x = center.x + x;
	center.y = center.y + y;
	StPt.x = StPt.x + x;
	StPt.y = StPt.y + y;
	for (int i = 0; i < sides; i++) {
		
		Vertexx[i] = Vertexx[i] + x;
		Vertexy[i] = Vertexy[i] +y;

	}
	
}

Point RegPolygon::Shift1()
{
	Point p;
	return p;
}
Point RegPolygon::Shift2()
{
	Point p;
	return p;
}

shape* RegPolygon::duplicate()
{
	Point p1,p2;
	 p1.x= StPt.x + 60;
	p2.x = center.x + 60;

	p1.y = StPt.y + 40;
	p2.y= center.y + 40;

	return new RegPolygon(p2,p1,sides,ShpGfxInfo);
}



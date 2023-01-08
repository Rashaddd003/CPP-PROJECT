#include "Line.h"

Line::Line()
{

}

Line::Line(Point p1, Point p2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	point1 = p1;
	point2 = p2;
	copyGFX = shapeGfxInfo;

	type = "Line";
}

Line::~Line()
{}

Line::Line(const Line & lineo)
{
	this->point1.x = lineo.point1.x+5;
	this->point2.x = lineo.point2.x + 5;
	this->point1.y = lineo.point1.y + 5;
	this->point2.y = lineo.point2.y + 5;
}

void Line::Draw(GUI* pUI) const
{
	pUI->DrawLine(point1, point2, ShpGfxInfo);
}

bool Line::ClickedInside(int x, int y) const
{
	int maxx, minx, maxy, miny;
	if (point1.x > point2.x) { maxx = point1.x; minx = point2.x; }
	else { maxx = point2.x; minx = point1.x; }
	if (point1.y > point2.y) { maxy = point1.y; miny = point2.y; }
	else { maxy = point2.y; miny = point1.y; }

	if (point1.x != point2.x && point1.y != point2.y)
	{
		float m = float(point1.y - point2.y) / (point1.x - point2.x);
		int c = (point1.y) - (m * point1.x);


		if (int(y - (m * x)) <= c + 5 && int(y - (m * x)) >= c - 5 && x <= maxx && x >= minx && y >= miny && y <= maxy) { return true; }
		else { return false; }

	}
	if (point1.x == point2.x) {
		if (y <= maxy && y >= miny && x > point1.x - 4 && x < point1.x + 4) { return true; }
		else return false;
	}

	if (point1.y == point2.y) {
		if (x <= maxx && x >= minx && y > point1.y - 4 && y < point1.y + 4) { return true; }
		else return false;
	}
}
void Line::Save(ofstream& OutFile)
{


	OutFile << type << " " << point1.x << " " << point1.y << " " << point2.x << " " << point2.y << " " << (ShpGfxInfo.isFilled) << " " << to_string(ShpGfxInfo.FillClr.ucRed) << " " << to_string(ShpGfxInfo.FillClr.ucGreen) << " " << to_string(ShpGfxInfo.FillClr.ucBlue) << " " << to_string(ShpGfxInfo.DrawClr.ucRed) << " " << to_string(ShpGfxInfo.DrawClr.ucGreen) << " " << to_string(ShpGfxInfo.DrawClr.ucBlue) << " " << (ShpGfxInfo.BorderWdth) << endl;

}

void Line::Load(ifstream& inFile)
{
	type = "line";
	int x;
	string jump;

	inFile >> x;
	point1.x = x;

	inFile >> x;
	point1.y = x;

	inFile >> x;

	point2.x = x;

	inFile >> x;
	point2.y = x;

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

void Line::Resize(double x)
{
	point2.x = point1.x + ((x) * (point2.x - point1.x));
	point2.y = point1.y + ((x) * (point2.y - point1.y));
}

void Line::Rotate()
{
	Point center;
	center.x = point1.x + ((point2.x - point1.x) / 2);
	center.y = point1.y + ((point2.y - point1.y) / 2);
	int swap = point1.x;
	point1.x = -point1.y + center.x + center.y;
	point1.y = swap - center.x + center.y;
	int swap1 = point2.x;
	point2.x = -point2.y + center.x + center.y;
	point2.y = swap1 - center.x + center.y;
}

void Line::Drag(int x,int y)
{
	int p2x; int p1x; int p2y; int p1y;
	point1.x = point1.x + x;
	point1.y = point1.y + y;
	point2.x = point2.x + x;
	point2.y = point2.y + y;
	Point p1; Point p2;
	/*p1.x = p1x;
	p1.y = p1y;
	p2.x = p2x;
	p2.y = p2y;*/
	//Line* R = new Line(p1, p2, copyGFX);
	
	//Get a pointer to the graph
	

	//Add the rectangle to the list of shapes
	
}

Point Line::Shift1()
{
	Point p1;
	p1.x = point1.x + 20;
	//p2.x = point2.x + 5;
	p1.y = point1.y ;
	//p2.y = point2.y + 5;

	return p1;
}
Point Line::Shift2()
{
	Point  p2;
	p2.x = point2.x + 20;
	//p2.x = point2.x + 5;
	p2.y = point2.y;
	//p2.y = point2.y + 5;

	return p2;
}

shape* Line::duplicate()
{

	Point p1;
	p1.x = point1.x + 60;
	//p2.x = point2.x + 5;
	p1.y = point1.y;
	Point  p2;
	p2.x = point2.x + 60;
	//p2.x = point2.x + 5;
	p2.y = point2.y;

	return new Line(p1, p2, ShpGfxInfo);
}





shape* Line::PasteShape()
{
	Point Point11, Point22;
	Point11.x = point1.x + 20;
	Point11.y = point1.y - 20;
	Point22.x = point2.x + 20;
	Point22.y = point2.y - 20;

	return new Line(Point11, Point22, ShpGfxInfo);

}
void Line::Stick(GUI* pGUI)
{
}
void Line::ScrambleShape(double shiftx, double shifty)
{
	int Dx = point1.x - shiftx;
	int Dy = point1.y - shifty;
	point1.x = shiftx;
	point1.y = shifty;
	point2.x -= Dx;
	point2.y -= Dy;

}
int Line::GetMaxX()
{
	return max(point1.x, point2.x);
}

int Line::GetMaxY()
{
	return max(point1.y, point2.y);
}

void Line::Hide(GUI* pGUI)
{

	if (Hidden)
	{
		Point P;
		P.x = point1.x;
		P.y = point1.y;
		int width = abs(point1.x - point2.x);
		int length = abs(point1.y - point2.y);
		string name = "images\\MenuIcons\\HideCard.jpg";
		pGUI->StickImage(name, P, width, length);
	}

}
#include "CRectangle.h"
#include <fstream>

CRectangle::CRectangle() {}
CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Center.x = (P1.x + P2.x) / 2;
	Center.y = (P1.y + P2.y) / 2;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}
bool CRectangle::IsInside(int x, int y){ //Checking if the point is inside the rectangle
	if ((x >= Corner1.x && x <= Corner2.x || x <= Corner1.x && x >= Corner2.x) && (y >= Corner1.y && y <= Corner2.y || y <= Corner1.y && y >= Corner2.y)) {
		return 1;
	}
	else {
		return 0;
	}
}
void CRectangle :: Move(int x, int y) {
	int xtranslate = Center.x - x;
	int ytranslate = Center.y - y;
	Center.x = x;
	Center.y = y;
	Corner1.x -= xtranslate; //translating points
	Corner1.y -= ytranslate;
	Corner2.x -= xtranslate;
	Corner2.y -= ytranslate;
}
void CRectangle::PrintInfo(Output* pOut) 
{
	int length = abs(Corner1.x-Corner2.x)>=abs(Corner1.y-Corner2.y)? abs(Corner1.x - Corner2.x): abs(Corner1.y - Corner2.y);
	int width = abs(Corner1.x - Corner2.x) < abs(Corner1.y - Corner2.y) ? abs(Corner1.x - Corner2.x) : abs(Corner1.y - Corner2.y);
	string MESSAGE = "Figure Type: Rectangle, ID: " + to_string(ID) + ", Corners Points:(" + to_string(Corner1.x) + "," + to_string(Corner1.y) + ")-(" + to_string(Corner2.x) + "," + to_string(Corner2.y) + "), Length="+to_string(length)+", Width="+to_string(width);
	pOut->PrintMessage(MESSAGE);
}
void CRectangle::Save(ofstream& outputFile) {
	outputFile << "RECT" << " " << GetID() << " "
		<< Corner1.x << " " << Corner1.y << " "
		<< Corner2.x << " " << Corner2.y << " "
		<< convertcolorToString(FigGfxInfo.DrawClr) << " "
		<< ((FigGfxInfo.isFilled) ? convertcolorToString(FigGfxInfo.FillClr) :"NO_FILL" ) << endl;

}

void CRectangle::Load(ifstream& inputFile) {
	string id, Corner1x, Corner1y, Corner2x, Corner2y, currentdrawclr, currentfillclr;
	inputFile >> id >> Corner1x >> Corner1y >> Corner2x >> Corner2y >> currentdrawclr >> currentfillclr;

	//set id
	SetID(stoi(id));

	//set point 1
	Corner1.x = stoi(Corner1x);
	Corner1.y = stoi(Corner1y);
	//set point 2
	Corner2.x = stoi(Corner2x);
	Corner2.y = stoi(Corner2y);
	//set current drawclr and currentfillclr
	if (FigGfxInfo.DrawClr != MAGENTA)
	{
		Selected = false;
	}
	FigGfxInfo.DrawClr = convertStringToColor(currentdrawclr);
	if (currentfillclr == "NO_FILL")
	{
		FigGfxInfo.isFilled = false;
		FigGfxInfo.FillClr = LIGHTGOLDENRODYELLOW;
	}
	else {
		FigGfxInfo.FillClr = convertStringToColor(currentfillclr);
	}
}

string CRectangle::GetFigureType()
{
	return "Rectangle";
}

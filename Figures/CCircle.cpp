#include "CCircle.h"
#include <fstream> 
#include"..\Actions\SaveAction.h"

CCircle::CCircle() {}

CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
	Point2 = P2;
}


void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawCirc to draw a circle on the screen	
	pOut->DrawCir(Center, Point2, FigGfxInfo, Selected);
}
bool CCircle::IsInside(int x, int y){ //Checking if the point is inside the rectangle
	float radius = sqrt(pow((Center.x - Point2.x), 2) + pow((Center.y - Point2.y), 2));//calculating radius
	if (sqrt(pow((Center.x - x), 2) + pow((Center.y - y), 2)) <= radius) {
		return 1;
	}
	else {
		return 0;
	}
}
void CCircle::Move(int x, int y) {
	int xtranslate = Center.x-x;
	int ytranslate = Center.y-y;
	Center.x = x;
	Center.y = y;
	Point2.x -= xtranslate;
	Point2.y -= ytranslate;

}
string CCircle::GetFigureType()
{
	return "Circle";
}
void CCircle::PrintInfo(Output* pOut) {
	string MESSAGE = "Figure Type: Circle, ID: " + to_string(ID) + ", Center Point:(" + to_string(Center.x) + "," + to_string(Center.y) + ")-Radius="+to_string(sqrt(pow((Center.x - Point2.x), 2) + pow((Center.y - Point2.y), 2)));
	pOut->PrintMessage(MESSAGE);
}

void CCircle::Save(ofstream& outputFile) {
	outputFile << "CIRC" <<" "<< GetID() << " " 
		<< Center.x << " " << Center.y   << " "
		<< Point2.x << " " << Point2.y   << " "
		<< convertcolorToString(FigGfxInfo.DrawClr)<<" "
		<< ((FigGfxInfo.isFilled) ? convertcolorToString(FigGfxInfo.FillClr) : "NO_FILL") << endl;
	
}
void CCircle::Load(ifstream& inputFile) {
	string id, Point1x, Point1y, Point2x, Point2y,currentdrawclr,currentfillclr;
	inputFile >> id >> Point1x >> Point1y >> Point2x >> Point2y >> currentdrawclr >> currentfillclr;

	//set id
	SetID(stoi(id));

	//set point 1
	Center.x = stoi(Point1x);
	Center.y = stoi(Point1y);
	//set point 2
	Point2.x = stoi(Point2x);
	Point2.y = stoi(Point2y);
	//set current drawclr and currentfillclr
	if (FigGfxInfo.DrawClr!=MAGENTA)
	{
		Selected = false;
	}
	FigGfxInfo.DrawClr = convertStringToColor(currentdrawclr);
	if (currentfillclr=="NO_FILL")
	{
		FigGfxInfo.isFilled = false;
		FigGfxInfo.FillClr = LIGHTGOLDENRODYELLOW;
	}
	else {
		FigGfxInfo.FillClr = convertStringToColor(currentfillclr);
	}
}
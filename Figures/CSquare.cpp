#include "CSquare.h"
#include <fstream>

CSquare::CSquare() {}

CSquare::CSquare(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
	
}


void CSquare::Draw(Output* pOut) const
{
	//Call Output::DrawSquare to draw a square on the screen	
	pOut->DrawSquare(Center, FigGfxInfo, Selected);
}
bool CSquare::IsInside(int x, int y){ //Checking if the point is inside the square
	if ((x >= Center.x-50 && x <= Center.x+50) && (y >= Center.y-50 && y <= Center.y+50 )) {
		return 1;
	}
	else {
		return 0;
	}
}
void CSquare::Move(int x, int y) {
	Center.x = x; // assigning new centerrr
	Center.y = y;
}
void CSquare::PrintInfo(Output* pOut){
	string MESSAGE = "Figure Type: Square, ID: " + to_string(ID) + ", Center Point:(" + to_string(Center.x) + "," + to_string(Center.y) + "), Side Length=50";
	pOut->PrintMessage(MESSAGE);
}
void CSquare::Save(ofstream& outputFile) {
	outputFile << "SQUAR" << " " << GetID() << " "
		<< Center.x << " " << Center.y << " "
		<< convertcolorToString(FigGfxInfo.DrawClr) << " "
		<< ((FigGfxInfo.isFilled) ? convertcolorToString(FigGfxInfo.FillClr) :"NO_FILL"  ) << endl;

}

void CSquare::Load(ifstream& inputFile) {
	string id, Centerx, Centery,currentdrawclr, currentfillclr;
	inputFile >> id >> Centerx >> Centery >> currentdrawclr >> currentfillclr;

	//set id
	SetID(stoi(id));

	//set center
	Center.x = stoi(Centerx);
	Center.y = stoi(Centery);

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

string CSquare::GetFigureType()
{
	return "Square";
}

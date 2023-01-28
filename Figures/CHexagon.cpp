#include "CHexagon.h"
#include <fstream>
CHexagon::CHexagon() {}
CHexagon::CHexagon(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
	
}


void CHexagon::Draw(Output* pOut) const
{
	//Call Output::DrawHexagon to draw a hexagon on the screen	
	pOut->DrawHexagon(Center, FigGfxInfo, Selected);
}
bool CHexagon::IsInside(int x, int y){
	//co-ordinates of Hexagon from origin	
	float X[6] = { 100,50,-50,-100,-50,50 };
	float Y[6] = { 0,sqrt(3) * 50,sqrt(3) * 50,0,-1 * (sqrt(3) * 50),-1 * (sqrt(3) * 50) };
	//adding them to our refrence point
	for (int i = 0; i < 6; i++)
	{
		X[i] += Center.x;
		Y[i] += Center.y;
	}
	float A = (pow(100.0, 2) * 6.0) / (4.0 * tan(3.141593 /6.0));;//calculating area of hexagon of side length 100
	//calculating area of each triangle ex:PAB,PBC....
	float A1 = abs((x * (Y[0] - Y[1]) + X[0] * (Y[1] - y) + X[1] * (y - Y[0])) / 2.0f);
	float A2 = abs((x * (Y[1] - Y[2]) + X[1] * (Y[2] - y) + X[2] * (y - Y[1])) / 2.0f);
	float A3 = abs((x * (Y[2] - Y[3]) + X[2] * (Y[3] - y) + X[3] * (y - Y[2])) / 2.0f);
	float A4 = abs((x * (Y[3] - Y[4]) + X[3] * (Y[4] - y) + X[4] * (y - Y[3])) / 2.0f);
	float A5 = abs((x * (Y[4] - Y[5]) + X[4] * (Y[5] - y) + X[5] * (y - Y[4])) / 2.0f);
	float A6 = abs((x * (Y[5] - Y[0]) + X[5] * (Y[0] - y) + X[0] * (y - Y[5])) / 2.0f);
	float total = A1 + A2 + A3 + A4 + A5 + A6;
	return abs((A -total))<=0.01;//adding an error tolerance
}
void CHexagon::Move(int x, int y) {
	Center.x = x;
	Center.y = y;
}
void CHexagon::PrintInfo(Output* pOut){
	string MESSAGE = "Figure Type: Hexagon, ID: " + to_string(ID) + ", Center Point:(" + to_string(Center.x) + "," + to_string(Center.y) + "), Side Length=100";
	pOut->PrintMessage(MESSAGE);
}
void CHexagon::Save(ofstream& outputFile) {
	outputFile << "HEXAG" << " " << GetID() << " "
		<< Center.x << " " << Center.y << " "
		<< convertcolorToString(FigGfxInfo.DrawClr) << " "
		<< ((FigGfxInfo.isFilled) ? convertcolorToString(FigGfxInfo.FillClr) :"NO_FILL") << endl;

}
void CHexagon::Load(ifstream& inputFile) {
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

string CHexagon::GetFigureType()
{
	return "Hexagon";
}

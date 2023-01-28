#include "LoadAction.h"

LoadAction::LoadAction(ApplicationManager* pApp) :Action(pApp) {};

void LoadAction::ReadActionParameters() {
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	//Read name of file to save graph info into from user
	pOut->PrintMessage("Enter Name of File: ");
	this->filename = pIn->GetSrting(pOut);

	pOut->ClearStatusBar();
}

void LoadAction::Execute(bool WillRecord, string filename2, bool where ) {
	
	//resetting everything and clear drawing area to be ready to get new graph
	pManager->clearAll();
	ifstream inputFile;
	if (where)
	{
		ReadActionParameters();
		inputFile.open(filename + ".txt", ios::in);
		//input current color & current fill color from txt file
		string Current_Draw_Color;
		string Current_Fill_Color;

		inputFile >> Current_Draw_Color >> Current_Fill_Color; //inputing data of current draw and fill color first line in txt file

		//setting program two current colors
		currentGfxInfo.DrawClr = convertStringToColor(Current_Draw_Color);
		currentGfxInfo.FillClr = convertStringToColor(Current_Fill_Color);

		
	}
	else
	{
		inputFile.open(filename2 + ".txt", ios::in);
	}
	 

	//reading ficount from txt file
	int figcount;
	inputFile >> figcount;

	//Determine and constructing shapes 
	CFigure* myFigure = NULL;
	for (size_t i = 0; i < figcount; i++)
	{
		string nameofshape;
		inputFile >> nameofshape;

		if (nameofshape=="RECT")
		{
			myFigure = new CRectangle;
		}
		else if (nameofshape == "SQUAR")
		{
			myFigure = new CSquare;
		}
		else if (nameofshape == "TRIANG")
		{
			myFigure = new CTriangle;
		}
		else if (nameofshape == "HEXAG")
		{
			myFigure = new CHexagon;
		}
		else if (nameofshape == "CIRC")
		{
			myFigure = new CCircle;
		}

		myFigure->Load(inputFile);
		pManager->AddFigure(myFigure);
	}
	
	

	inputFile.close();
}

color LoadAction::convertStringToColor(string color) {

	if (color =="BLACK")
	{
		return  BLACK;
	}
	else if (color == "YELLOW")
	{
		return YELLOW;
	}
	else if (color =="ORANGE" )
	{
		return ORANGE;
	}
	else if (color == "RED")
	{
		return  RED;
	}
	else if (color =="GREEN" )
	{
		return GREEN ;
	}
	else if (color == "BLUE")
	{
		return  BLUE;
	}
}

void LoadAction::Undo()
{

}

void LoadAction::Redo()
{

}

LoadAction::~LoadAction()
{

}
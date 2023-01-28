#include "SaveAction.h"
#include <fstream> 


SaveAction::SaveAction(ApplicationManager* pApp) :Action(pApp) {};

string SaveAction::convertcolorToString(color color) {

	if (color == BLACK)
	{
		return "BLACK";
	}
	else if (color == YELLOW)
	{
		return "YELLOW";
	}
	else if (color == ORANGE)
	{
		return "ORANGE";
	}
	else if (color == RED)
	{
		return "RED";
	}
	else if (color == GREEN)
	{
		return "GREEN";
	}
	else if (color == BLUE)
	{
		return "BLUE";
	}
}

void SaveAction::ReadActionParameters() {

	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Read name of file to save graph info into from user
	pOut->PrintMessage("Enter Name of File: ");
	this->filename5 = pIn->GetSrting(pOut);

	//get drawing, filling colors 
	currentGfxInfo.DrawClr = pOut->getCrntDrawColor();
	currentGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

void SaveAction::Execute(bool WillRecord, string filename, bool where ) {

	ReadActionParameters();
	ofstream outputFile;
	outputFile.open(filename5+".txt", ios::out); //if we 've used ofstream(write into files) we dont need to open file  

	//write current color & current fill color into txt file

	string Current_Draw_Color = convertcolorToString(currentGfxInfo.DrawClr);
	string Current_Fill_Color = convertcolorToString(currentGfxInfo.FillClr);

	outputFile << Current_Draw_Color << " " << Current_Fill_Color << endl; //saving data of current draw and fill color first line in txt file

	//saving number of figures in figlist by calling function saveficount in application manager

	pManager->SaveFigcount(outputFile);

	//calls ApplicationManager::SaveAll(…) to write data members of each shape into text file 
	pManager->SaveAll(outputFile);

	outputFile.close();
}

void SaveAction::Undo()
{

}

void SaveAction::Redo()
{

}

SaveAction::~SaveAction()
{

}
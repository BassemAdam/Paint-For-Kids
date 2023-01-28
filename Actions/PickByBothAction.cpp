#include "PickByBothAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include"LoadAction.h"
#include"SelectOneAction.h"

PickByBothAction::PickByBothAction(ApplicationManager* pApp) :Action(pApp)
{
	NumberOfFiguresOnScreen = pManager->getFigCount();
	CorrectCounter = 0;
	WrongCounter = 0;
}

void PickByBothAction::UpdateScore(bool Correct)
{
	Output* pOut = pManager->GetOutput();

	if (Correct)
	{
		CorrectCounter++;


	}
	else
	{

		WrongCounter++;
	}

}

void PickByBothAction::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	pIn->GetPointClicked(P.x, P.y);

}

void PickByBothAction::Execute(bool WillRecord, string filename, bool where)
{
	pManager->Reset();//sets draw are to draw mode figured
	pManager->UpdateInterface();//updates interface 
	Output* pOut = pManager->GetOutput();
	if (NumberOfFiguresOnScreen < 2) {
		pOut->PrintMessage("You must have at least two or more Shapes to play pick by both Shape and Color!");
		return;
	}

	CFigure* PlayFig = pManager->GetRandFig();// Random Figure
	string PlayFigureName = PlayFig->GetFigureType();//gets figure type
	GfxInfo FigureGfxInfo = PlayFig->GetGfxInfo();//gets color
	if (FigureGfxInfo.isFilled)//checks to see if figure is filled or not 
	{
		PlayFigureColor = FigureGfxInfo.FillClr;
		StringColor = PlayFig->convertcolorToString(PlayFigureColor);

	}
	else
	{
		StringColor = "NON-FILLED";
	}
	
	//Check the number of this figure on the screen
	int NumberofPlayFigures = pManager->GetNumberofSelectedFigure(PlayFig,PlayFig->GetGfxInfo());
	pOut->PrintMessage("Please Select All the " + StringColor +" " + PlayFigureName + "s");



	while (NumberofPlayFigures > 0)
	{

		ReadActionParameters();
		CFigure* FigNew = pManager->GetFigure(P.x, P.y); //Checks if the points clicked are inside a figure


		if (FigNew == NULL || !FigNew->IsHidden())//if user clicked empty area 
		{
			pOut->PrintMessage("You Clicked An Empty Area");
			continue;
		}


		if (PlayFigureName == FigNew->GetFigureType() && PlayFig->GetGfxInfo().FillClr == FigNew->GetGfxInfo().FillClr )
		{

			UpdateScore(1);//adds coorect
			FigNew->SetHidden(false);//removes fiure from screen
			pManager->UpdateInterface();
			NumberofPlayFigures--;
			pOut->PrintMessage("Correct! Current Score = " + to_string(CorrectCounter) + " Right, and " + to_string(WrongCounter) + " Wrong.");
			continue;
		}
		UpdateScore(0);//adds wrong counter 
		FigNew->SetHidden(false);
		pManager->UpdateInterface();
		pOut->PrintMessage("Wrong! Try Again! Current Score = " + to_string(CorrectCounter) + " Right, and " + to_string(WrongCounter) + " Wrong.");

		
	}

	pOut->PrintMessage("Congratulations YOU WIN!, Final Score = " + to_string(CorrectCounter) + " Right, and " + to_string(WrongCounter) + " Wrong.");


}

void PickByBothAction::Undo()
{

}

void PickByBothAction::Redo()
{

}

PickByBothAction::~PickByBothAction()
{

}
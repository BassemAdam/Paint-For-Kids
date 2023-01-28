#include "PickByShapeAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include"LoadAction.h"
#include"SelectOneAction.h"

PickByShapeAction::PickByShapeAction(ApplicationManager* pApp) :Action(pApp)
{
	NumberOfFiguresOnScreen = pManager->getFigCount();
	CorrectCounter = 0;
	WrongCounter = 0;
}

void PickByShapeAction::UpdateScore(bool Correct)
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
// reads input from user 
void PickByShapeAction::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	pIn->GetPointClicked(P.x, P.y);

}

void PickByShapeAction::Execute(bool WillRecord, string filename, bool where)
{
	pManager->Reset();// resets the board to the draw mode figures
	pManager->UpdateInterface();// updates interface
	Output* pOut = pManager->GetOutput();
	if (NumberOfFiguresOnScreen < 2) {
		pOut->PrintMessage("You must have at least two or more Shapes to play pick by shape!");
		return;
	}
	
	CFigure* PlayFig = pManager->GetRandFig();// Random Figure
	string PlayFigureName = PlayFig->GetFigureType();// gets figure name 
	//Check the number of this figure on the screen
	int NumberofPlayFigures = pManager->GetNumberofSelectedFigure(PlayFig);
	pOut->PrintMessage("Please Select All the " + PlayFigureName + "s");



	while (NumberofPlayFigures > 0)
	{
		
		ReadActionParameters();
		CFigure* FigNew = pManager->GetFigure(P.x, P.y); //Checks if the points clicked are inside a figure


		if (FigNew == NULL||!FigNew->IsHidden())// if clicked on nothing
		{
			pOut->PrintMessage("You Clicked An Empty Area");
			continue;
		}
		

		if (PlayFigureName==FigNew->GetFigureType())// if figure is of correct type 
		{

			UpdateScore(1);//adds positive counter 
			FigNew->SetHidden(false);//hides the figure 
			pManager->UpdateInterface();//updates interface
			NumberofPlayFigures--;// reduces number of play figures counter 
			pOut->PrintMessage("Correct! Current Score = " + to_string(CorrectCounter) + " Right, and " + to_string(WrongCounter) + " Wrong.");
			continue;
			
		}
		UpdateScore(0);// adds wrong counter 
		FigNew->SetHidden(false);// hides shape
		pManager->UpdateInterface();//update interface
		pOut->PrintMessage("Wrong! Try Again! Current Score = " +to_string(CorrectCounter) + " Right, and " + to_string(WrongCounter) + " Wrong.");
		
	}

	pOut->PrintMessage("Congratulations YOU WIN!, Final Score = " + to_string(CorrectCounter) + " Right, and " + to_string(WrongCounter) + " Wrong.");//prints final score


}

void PickByShapeAction::Undo()
{

}

void PickByShapeAction::Redo()
{

}

PickByShapeAction::~PickByShapeAction()
{

}
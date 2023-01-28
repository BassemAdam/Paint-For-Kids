#include "AddCircAction.h"
#include "..\Figures\CCircle.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include<Windows.h>

AddCircAction::AddCircAction(ApplicationManager* pApp) :Action(pApp) {} //Constructor

void AddCircAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at Center");

	//Read Center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Circle: Click at Radius");

	//Read Radius and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	CircGfxInfo.isFilled = UI.isFilled;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	CircGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddCircAction::Execute(bool WillRecord, string filename, bool where )
{
	if(!WillRecord)//Checks to see of the recording is being played, when will record = 1 , the recording is being played
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a Circle with the parameters read from the user
	FigPtr = new CCircle(P1, P2, CircGfxInfo);

	//Add the circle to the list of figures
	pManager->AddFigure(FigPtr);

	//Check if Mute is activated. Default not muted
	if (pManager->IsMute() == 0)
	{
		PlaySound("audio/Circle.wav", NULL, SND_FILENAME); //Play circle sound
	}
	if (pManager->getWillRecord())
	{
		pManager->AddRecordingFigure(this);
	}
	pManager->AddActionToUndoList(this); //Add the action to the undo list
}

//Undo the action
void AddCircAction::Undo()
{
	pManager->DeleteFigure(FigPtr); //Remove the figure from FigList
	FigPtr->SetSelected(false); //Unselect the removed figure
}

//Redo the action
void AddCircAction::Redo()
{
	pManager->AddFigure(FigPtr); //Add the figure to FigList
	FigPtr->SetSelected(false); //Unselect the added figure
}

// Destructor
AddCircAction::~AddCircAction()
{
	if (FigPtr != NULL && pManager->IsFoundInFigList(FigPtr) == false) //Checks if FigPtr not equal NULL and if the figure is not in FigList
	{
		delete FigPtr; //Deallocate the Figure
	}
}
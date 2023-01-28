#include "AddHexaAction.h"
#include "..\Figures\CHexagon.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include<Windows.h>

AddHexaAction::AddHexaAction(ApplicationManager* pApp) :Action(pApp) {} //Constructor

void AddHexaAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Hexagon: Click at Center");

	//Read Center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);



	HexaGfxInfo.isFilled = UI.isFilled;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	HexaGfxInfo.DrawClr = pOut->getCrntDrawColor();
	HexaGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddHexaAction::Execute(bool WillRecord, string filename, bool where )
{
	if(!WillRecord)//Checks to see of the recording is being played, when will record = 1 , the recording is being played
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a hexagon with the parameters read from the user
	FigPtr = new CHexagon(P1, HexaGfxInfo);

	//Add the circle to the list of figures
	pManager->AddFigure(FigPtr);

	//Check if Mute is activated. Default not muted
	if (pManager->IsMute() == 0)
	{
		PlaySound("audio/Hexagon.wav", NULL, SND_FILENAME); //Play Hexagon sound
	}
	if (pManager->getWillRecord())
	{
		pManager->AddRecordingFigure(this);
	}
	pManager->AddActionToUndoList(this); //Add the action to the undo list
}

//Undo the action
void AddHexaAction::Undo()
{
	pManager->DeleteFigure(FigPtr); //Remove the figure from FigList
	FigPtr->SetSelected(false); //Unselect the removed figure
}

//Redo the action
void AddHexaAction::Redo()
{
	pManager->AddFigure(FigPtr); //Add the figure to FigList
	FigPtr->SetSelected(false); //Unselect the added figure
}

// Destructor
AddHexaAction::~AddHexaAction()
{
	if (FigPtr != NULL && pManager->IsFoundInFigList(FigPtr) == false) //Checks if FigPtr not equal NULL and if the figure is not in FigList
	{
		delete FigPtr; //Deallocate the Figure
	}
}
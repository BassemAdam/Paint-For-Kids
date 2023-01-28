#include "AddTriAction.h"
#include "..\Figures\CTriangle.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include<Windows.h>

AddTriAction::AddTriAction(ApplicationManager* pApp) :Action(pApp) {} //Constructor

void AddTriAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at first corner");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Triangle: Click at second corner");

	//Read 2nd corner and store in point P2

	pIn->GetPointClicked(P2.x, P2.y);

	pOut->PrintMessage("New Triangle: Click at Third corner");

	//Read 3rd corner and store in point P3
	pIn->GetPointClicked(P3.x, P3.y);

	TriGfxInfo.isFilled = UI.isFilled;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	TriGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddTriAction::Execute(bool WillRecord, string filename, bool where )
{
	if(!WillRecord)//Checks to see of the recording is being played, when will record = 1 , the recording is being played
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rectangle with the parameters read from the user
	FigPtr = new CTriangle(P1, P2, P3, TriGfxInfo);

	//Add the triangle to the list of figures
	pManager->AddFigure(FigPtr);

	//Check if Mute is activated. Default not muted
	if (pManager->IsMute() == 0)
	{
		PlaySound("audio/Triangle.wav", NULL, SND_FILENAME); //Play triangle sound
	}
	if (pManager->getWillRecord())
	{
		pManager->AddRecordingFigure(this);
	}
	pManager->AddActionToUndoList(this); //Add the action to the undo list
}

//Undo the action
void AddTriAction::Undo()
{
	pManager->DeleteFigure(FigPtr); //Remove the figure from FigList
	FigPtr->SetSelected(false); //Unselect the removed figure
}

//Redo the action
void AddTriAction::Redo()
{
	pManager->AddFigure(FigPtr); //Add the figure to FigList
	FigPtr->SetSelected(false); //Unselect the added figure
}

//Destructor
AddTriAction::~AddTriAction()
{
	if (FigPtr != NULL && pManager->IsFoundInFigList(FigPtr) == false) //Checks if FigPtr not equal NULL and if the figure is not in FigList
	{
		delete FigPtr; //Deallocate the Figure
	}
}
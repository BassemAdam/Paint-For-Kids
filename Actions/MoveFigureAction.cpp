#include "MoveFigureAction.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

MoveFigureAction::MoveFigureAction(ApplicationManager* pApp) :Action(pApp) {} //Constructor

void MoveFigureAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	FigPtr = pManager->GetSelectedFigure();

	if (FigPtr == NULL)//chrecking if he selected a figure first
	{
		pOut->PrintMessage("Error! Please Select a figure first");
		SelectedFlag = false;
		return;// so he doesnt read further parameters("action wont be executed")
	}

	pOut->PrintMessage("Moving Selected Figure: Click on new center");

	//Read new center and store in point P1
	pIn->GetPointClicked(PNew.x, PNew.y);

	pOut->ClearStatusBar();
}

//Execute the action
void MoveFigureAction::Execute(bool WillRecord, string filename, bool where)
{
	if (!WillRecord)//Checks to see of the recording is being played, when will record = 1 , the recording is being played
		//This action needs to read some parameters first
		ReadActionParameters();

	if (!SelectedFlag) //checking if he selected a figure first
	{
		return;
	}
	Output* pOut = pManager->GetOutput();
	FigPtr = pManager->GetSelectedFigure();
	POld = FigPtr->GetCenter();
	FigPtr->Move(PNew.x, PNew.y); // Moves Figure to new Center;
	pOut->PrintMessage("Figure Moved");

	if (pManager->getWillRecord())
	{
		pManager->AddRecordingFigure(this);
	}

	pManager->AddActionToUndoList(this); //Add the action to undo list
}

//Undo the action
void MoveFigureAction::Undo()
{
	FigPtr->Move(POld.x, POld.y); //Set the center of the figure with the old one
}

//Redo the action
void MoveFigureAction::Redo()
{
	FigPtr->Move(PNew.x, PNew.y); //Set the center of the figure with the new one created
}

//Destructor
MoveFigureAction::~MoveFigureAction(){}
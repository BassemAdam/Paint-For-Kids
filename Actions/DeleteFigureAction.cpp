#include "DeleteFigureAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

DeleteFigureAction::DeleteFigureAction(ApplicationManager* pApp) :Action(pApp) {} //Constructor

//Read action parameters
void DeleteFigureAction::ReadActionParameters()
{
	FigPtr = pManager->GetSelectedFigure(); //FigPtr points to the selected figure to delete
}

//Execute the action
void DeleteFigureAction::Execute(bool WillRecord, string filename, bool where )
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	if (!WillRecord)//Checks to see of the recording is being played, when will record = 1 , the recording is being played
	{
		ReadActionParameters();
	}

	if (FigPtr == NULL)
	{
		pOut->PrintMessage("Error! Please Select a figure first");
		return;
	}

	pManager->DeleteFigure(FigPtr); //Removes the figure from FigList
	pOut->PrintMessage("Figure Deleted");

	if (pManager->getWillRecord())
	{
		pManager->AddRecordingFigure(this);
	}

	pManager->AddActionToUndoList(this); //Add action to the undo list
}

//Undo the action
void DeleteFigureAction::Undo()
{
	pManager->AddFigure(FigPtr); //Restore the figure in FigList
	FigPtr->SetSelected(false); //Unselect the restored figure
}

//Redo the action
void DeleteFigureAction::Redo()
{
	pManager->DeleteFigure(FigPtr); //Removes the figure from FigList
	FigPtr->SetSelected(false); //Unselect the restored figure
}

//Destructor
DeleteFigureAction::~DeleteFigureAction() {}
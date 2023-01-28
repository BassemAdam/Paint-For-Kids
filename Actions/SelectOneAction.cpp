#include "SelectOneAction.h"
#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SelectOneAction::SelectOneAction(ApplicationManager* pApp) :Action(pApp)
{}
void SelectOneAction::ReadActionParameters() {
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Select a Figure");

	//Reads a point and stores it in P
	pIn->GetPointClicked(P.x, P.y);
	pOut->ClearStatusBar();
}
void SelectOneAction::Execute(bool WillRecord, string filename, bool where ) {
	if(!WillRecord)//Checks to see of the recording is being played, when will record = 1 , the recording is being played
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	CFigure* FigNew = pManager->GetFigure(P.x, P.y); //Checks if the points clicked are inside a figure
	CFigure* SelectedFig = pManager->GetSelectedFigure(); //Returns the old selected figure
	if (FigNew == NULL) {
		pOut->PrintMessage("A Click on an Empty Area");
	}
	else if (SelectedFig == NULL && FigNew != NULL)//if there is no selected figure and you clicked on a new figure
	{
		FigNew->SetSelected(1);
		pManager->SetSelectedFigure(FigNew);
		FigNew->PrintInfo(pOut);
	}
	else if (SelectedFig == FigNew) //Clicked on an already selected figure
	{
		SelectedFig->SetSelected(0);
		FigNew->SetSelected(0);
		pManager->SetSelectedFigure(NULL);
		pOut->PrintMessage("Figure Unselected");
	}
	else if (SelectedFig->IsSelected() == 1 && FigNew != NULL)//if there is a selected figure and you clicked on a new figure
	{
		SelectedFig->SetSelected(0);
		FigNew->SetSelected(1);
		pManager->SetSelectedFigure(FigNew);
		FigNew->PrintInfo(pOut);
	}
	if (pManager->getWillRecord())
	{
		pManager->AddRecordingFigure(this);
	}
}

void SelectOneAction::Undo()
{

}

void SelectOneAction::Redo()
{

}

SelectOneAction::~SelectOneAction()
{

}
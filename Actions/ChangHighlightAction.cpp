#include "ChangHighlightAction.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ChangeHighlightAction::ChangeHighlightAction(ApplicationManager* pApp) :Action(pApp) {} //Constructor

//Reading some parameters
void ChangeHighlightAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Get the selected figure
	FigPtr = pManager->GetSelectedFigure();

	if (FigPtr == NULL) //chrecking if he selected a figure first
	{
		pOut->PrintMessage("Error! Please Select a figure first");
		SelectedFlag = false;
		return;// so he doesnt read further parameters("action wont be executed")
	}

	pOut->PrintMessage("Please Choose Highlight Colour");
	ColorAct = pIn->GetUserAction();//getting the point clicked after choosing to change the fill color
	pOut->ClearStatusBar();

}

bool ChangeHighlightAction::GetHighlightColour(ActionType ColorAct)//storing the color clicked or if he didnt click on a color
{
	if (ColorAct == C_BLACK)
	{
		UI.DrawColor = BLACK;
		NewGfxInfo.DrawClr = BLACK;
		return 1;
	}
	else if (ColorAct == C_YELLOW)
	{
		UI.DrawColor = YELLOW;
		NewGfxInfo.DrawClr = YELLOW;
		return 1;
	}
	else if (ColorAct == C_ORANGE)
	{
		UI.DrawColor = ORANGE;
		NewGfxInfo.DrawClr = ORANGE;
		return 1;
	}
	else if (ColorAct == C_RED)
	{
		UI.DrawColor = RED;
		NewGfxInfo.DrawClr = RED;
		return 1;
	}
	else if (ColorAct == C_GREEN)
	{
		UI.DrawColor = GREEN;
		NewGfxInfo.DrawClr = GREEN;
		return 1;
	}
	else if (ColorAct == C_BLUE)
	{
		UI.DrawColor = BLUE;
		NewGfxInfo.DrawClr = BLUE;
		return 1;
	}
	else {
		return 0;
	}
}

//Execute the action
void ChangeHighlightAction::Execute(bool WillRecord, string filename, bool where) {
	if (!WillRecord)//Checks to see of the recording is being played, when will record = 1 , the recording is being played
		//This action needs to read some parameters first
		ReadActionParameters();

	if (!SelectedFlag)//checking if he selected a figure first
	{
		return;
	}

	Output* pOut = pManager->GetOutput();
	FigPtr = pManager->GetSelectedFigure();
	OldGfxInfo = FigPtr->GetGfxInfo();
	NewGfxInfo = OldGfxInfo;

	if (GetHighlightColour(ColorAct))//changing the color if he clicked on a color icon
	{
		FigPtr->ChngDrawClr(UI.DrawColor);
	}
	else
	{
		pOut->PrintMessage("Please Click on a Colour icon");
	}

	if (pManager->getWillRecord())
	{
		pManager->AddRecordingFigure(this);
	}

	if (GetHighlightColour(ColorAct))
	{
		pManager->AddActionToUndoList(this); //Add the action to the undo list
	}
}

//Undo the action
void ChangeHighlightAction::Undo()
{
	FigPtr->ChngGfxInfo(OldGfxInfo); //Set the graphics info of the figure with the old one
}

//Redo the action
void ChangeHighlightAction::Redo()
{
	FigPtr->ChngGfxInfo(NewGfxInfo); //Set the graphics info of the figure with the new stored one
}

//Destructor
ChangeHighlightAction::~ChangeHighlightAction() {}
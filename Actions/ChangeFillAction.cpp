#include "ChangeFillAction.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "../DEFS.h"

ChangeFillAction::ChangeFillAction(ApplicationManager* pApp) :Action(pApp) {} //Constructor

//Reading some parameters
void ChangeFillAction::ReadActionParameters()
{
    //Get a Pointer to the Input / Output Interfaces
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();
    //Get the selected figure
    FigPtr = pManager->GetSelectedFigure();
    if (FigPtr == NULL) //checking if he selected a figure first
    {
        pOut->PrintMessage("Error! Please Select a figure first");
        SelectedFlag = false;
        return; // so he doesnt read further parameters("action wont be executed")
    }
    pOut->PrintMessage("Please Choose Fill Colour");
    ColorAct = pIn->GetUserAction();//getting the point clicked after choosing to change the fill color
    pOut->ClearStatusBar();

}

bool ChangeFillAction::GetFillColour(ActionType ColorAct) //Checking the color clicked or if he didnt click on a color
{
    if (ColorAct == C_BLACK)
    {
        UI.FillColor = BLACK;
        NewGfxInfo.FillClr = BLACK;
        return 1;
    }
    else if (ColorAct == C_YELLOW)
    {
        UI.FillColor = YELLOW;
        NewGfxInfo.FillClr = YELLOW;
        return 1;
    }
    else if (ColorAct == C_ORANGE)
    {
        UI.FillColor = ORANGE;
        NewGfxInfo.FillClr = ORANGE;
        return 1;
    }
    else if (ColorAct == C_RED)
    {
        UI.FillColor = RED;
        NewGfxInfo.FillClr = RED;
        return 1;
    }
    else if (ColorAct == C_GREEN)
    {
        UI.FillColor = GREEN;
        NewGfxInfo.FillClr = GREEN;
        return 1;
    }
    else if (ColorAct == C_BLUE)
    {
        UI.FillColor = BLUE;
        NewGfxInfo.FillClr = BLUE;
        return 1;
    }
    else {
        return 0;
    }
}

//Execute the action
void ChangeFillAction::Execute(bool WillRecord, string filename, bool where) {
    if (!WillRecord)//Checks to see of the recording is being played, when will record = 1 , the recording is being played
        //This action needs to read some parameters first
        ReadActionParameters();

    if (!SelectedFlag)//checking if he selected a figure first
    {
        return;
    }

    FigPtr = pManager->GetSelectedFigure();
    Output* pOut = pManager->GetOutput();
    OldGfxInfo = FigPtr->GetGfxInfo(); //Stores old graphics info of the figure
    NewGfxInfo = OldGfxInfo;

    if (GetFillColour(ColorAct))//changing the color if he clicked on a color icon
    {
        UI.isFilled = true;
        NewGfxInfo.isFilled = true;
        FigPtr->ChngFillClr(UI.FillColor); //changing the fill color
    }
    else
    {
        pOut->PrintMessage("Please Click on a Colour icon");
    }

    if (pManager->getWillRecord())
    {
        pManager->AddRecordingFigure(this);
    }

    if (GetFillColour(ColorAct))
    {
        pManager->AddActionToUndoList(this); //Add the action to the undo list
    }
}

//Undo the action
void ChangeFillAction::Undo()
{
    FigPtr->ChngGfxInfo(OldGfxInfo); //Set the graphics info of the figure with the old one
}

//Redo the action
void ChangeFillAction::Redo()
{
    FigPtr->ChngGfxInfo(NewGfxInfo); //Set the graphics info of the figure with the new stored one
}

//Destructor
ChangeFillAction::~ChangeFillAction() {}
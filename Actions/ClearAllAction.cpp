#include "ClearAllAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ClearAllAction::ClearAllAction(ApplicationManager* pApp) :Action(pApp) {} //Constructor

void ClearAllAction::ReadActionParameters() {}

//Execute the action
void ClearAllAction::Execute(bool WillRecord, string filename, bool where)
{
	//Get a Pointer to the Output Interfaces
	Output* pOut = pManager->GetOutput();

	pManager->ResetData(); //Calls ResetData function in Application Manager

	pOut->PrintMessage("Cleared All Data");
}

void ClearAllAction::Undo() {}

void ClearAllAction::Redo() {}

//Destructor
ClearAllAction::~ClearAllAction() {}
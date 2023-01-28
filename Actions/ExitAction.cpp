#include "ExitAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ExitAction::ExitAction(ApplicationManager* pApp) :Action(pApp) {} //Constructor

void ExitAction::ReadActionParameters(){}

void ExitAction::Execute(bool WillRecord, string filename, bool where)
{
	pManager->ResetData(); //Reset data and deallocate memory before exit
}

void ExitAction::Undo() {}

void ExitAction::Redo() {}

ExitAction::~ExitAction() {} //Destructor
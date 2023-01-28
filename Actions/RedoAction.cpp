#include "RedoAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

RedoAction::RedoAction(ApplicationManager* pApp) :Action(pApp) {} //Constructor

void RedoAction::ReadActionParameters() {}

//Execute the action
void RedoAction::Execute(bool WillRecord, string filename, bool where )
{
	pManager->RedoPrevAction(); //Calls RedoPrevAction function in Application Manager

	if (pManager->getWillRecord())
	{
		pManager->AddRecordingFigure(this);
	}
}

void RedoAction::Undo() {}

void RedoAction::Redo() {}

//Destructor
RedoAction::~RedoAction() {}
#include "UndoAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

UndoAction::UndoAction(ApplicationManager* pApp) :Action(pApp) {} //Constructor

void UndoAction::ReadActionParameters() {}

//Execute the action
void UndoAction::Execute(bool WillRecord, string filename, bool where )
{
	pManager->UndoPrevAction();//Calls UndoPrevAction function in Application Manager

	if (pManager->getWillRecord())
	{
		pManager->AddRecordingFigure(this);
	}
}
void UndoAction::Undo() {}

void UndoAction::Redo() {}

//Destructor
UndoAction::~UndoAction() {}
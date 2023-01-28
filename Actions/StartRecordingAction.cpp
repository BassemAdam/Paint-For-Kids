#include "StartRecordingAction.h"
#include "..\ApplicationManager.h"


#include "..\GUI\Output.h"

//Constructor
StartRecordingAction::StartRecordingAction(ApplicationManager* pApp) :Action(pApp)
{
}
//Execution
void StartRecordingAction::Execute(bool isBeingPlayed, string filename, bool where )
{
	Output* pOut = pManager->GetOutput();
	if (pManager->IsEmpty())//checks to see if the the drawboard is empty
	{
		pManager->setWillRecord(1);//starts recording
		pOut->PrintMessage("Started Recording");
	}
	else
	{

		pOut->PrintMessage("Error: Drawing Area is not empty");
	}
}

void StartRecordingAction::ReadActionParameters()
{
}

void StartRecordingAction::Undo()
{
}

void StartRecordingAction::Redo()
{
}

StartRecordingAction::~StartRecordingAction()
{

}
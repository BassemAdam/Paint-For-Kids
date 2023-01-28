#include "StopRecordingAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Output.h"

StopRecordingAction::StopRecordingAction(ApplicationManager* pApp) :Action(pApp)
{
}

void StopRecordingAction::Execute(bool isBeingPlayed, string filename, bool where )
{
	Output* pOut = pManager->GetOutput();
	if (pManager->getWillRecord())//checks  if user is recording
	{
		pManager->setWillRecord(0);//stops recording

		pOut->PrintMessage("Stopped Recording");
	}
	else
	{
		pOut->PrintMessage("Cannot Stop Recording , Start Recording First! ");
	}

}

void StopRecordingAction::ReadActionParameters()
{
}

void StopRecordingAction::Undo()
{
}

void StopRecordingAction::Redo()
{
}

StopRecordingAction::~StopRecordingAction()
{

}
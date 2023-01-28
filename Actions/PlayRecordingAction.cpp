#include "PlayRecordingAction.h"
#include "..\ApplicationManager.h"


#include "..\GUI\Output.h"





PlayRecordingAction::PlayRecordingAction(ApplicationManager* pApp) :Action(pApp)
{
}

void PlayRecordingAction::Execute(bool isBeingPlayed, string filename, bool where )
{
	Output* pOut = pManager->GetOutput();
	if (pManager->GetRecordingListCount() == 0) //checks if there is anything recorded
	{
		pOut->PrintMessage("No Recording to Be Played!");
		return;
	}
	if (pManager->getWillRecord())// checks if user is recording 
	{
		pOut->PrintMessage("Cannot Play Recording While Recording!");
		return;
	}
	
	pOut->PrintMessage("Playing the Recording");
	CFigure::resetID();//resets the ID's 
	pManager->clearAll();// clears the board
	Sleep(1000);
	for (int i = 0; i < pManager->GetRecordingListCount(); i++)
	{
		pManager->PlayRecording(i);//plays an action 
		pManager->UpdateInterface();//updates interface
		if (i % 2 != 0)// sleeps every 2 actions
		{
			Sleep(1000);
		}
	}
	
	pOut->PrintMessage("Recording Played");
}

void PlayRecordingAction::ReadActionParameters()
{
}

void PlayRecordingAction::Undo()
{
}

void PlayRecordingAction::Redo()
{
}

PlayRecordingAction::~PlayRecordingAction()
{

}

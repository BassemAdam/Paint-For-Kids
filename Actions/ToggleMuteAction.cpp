#include"ToggleMuteAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ToggleMuteAction::ToggleMuteAction(ApplicationManager* pApp) :Action(pApp) {} //Constructor

void ToggleMuteAction::ReadActionParameters(){}

//Execute the action
void ToggleMuteAction::Execute(bool WillRecord, string filename, bool where)
{
	//Get a Pointer to the Output Interfaces
	Output* pOut = pManager->GetOutput();

	if (!WillRecord)//Checks to see of the recording is being played, when will record = 1 , the recording is being played
		//This action needs to read some parameters first
		ReadActionParameters();

	if (pManager->IsMute()==0) //Check if the sound isn't muted
	{
		pOut->PrintMessage("Muted");
	}
	else
	{
		pOut->PrintMessage("Unmuted");
	}

	pManager->ToggleMute(); //Change Mute state;

	
}

void ToggleMuteAction::Undo(){}

void ToggleMuteAction::Redo() {}

//Destructor
ToggleMuteAction::~ToggleMuteAction() {}
#include "SwitchToPlayAction.h"


#include "..\ApplicationManager.h"
#include <fstream>

#include "..\GUI\Output.h"

SwitchToPlayAction::SwitchToPlayAction(ApplicationManager* pApp) :Action(pApp)
{

}



void SwitchToPlayAction::Execute(bool WillRecord, string filename, bool where )
{

	Output* pOut = pManager->GetOutput();
	pOut->CreatePlayToolBar();//Calls the Create tool bar
	pManager->UpdateInterface();
	/*ofstream outputFile;
	string details = "Details";
	outputFile.open(details, ios::out);
	pManager->SaveFigcount(outputFile);
	pManager->SaveAll(outputFile);*/


}

void SwitchToPlayAction::ReadActionParameters()
{
}

void SwitchToPlayAction::Undo()
{
}

void SwitchToPlayAction::Redo()
{
}

SwitchToPlayAction::~SwitchToPlayAction()
{

}
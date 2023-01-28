#include "ToDraw.h"


ToDraw::ToDraw(ApplicationManager* pApp):Action(pApp) {}


void ToDraw::ReadActionParameters() {
	
}

void ToDraw::Execute(bool WillRecord, string filename, bool where ) {

	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	

	pOut->PrintMessage("Action: Switch to Draw Mode, creating simualtion tool bar");

	//alternative method
	//LoadAction* L = new LoadAction(pManager);
	//L->Execute(false, "Details", 0);

	pOut->ClearToolBar();
	pOut->ClearDrawArea();
	pManager->Reset();
	pManager->UpdateInterface();

	pOut->CreateDrawToolBar();
	pOut->CreateDrawToolBar();

	//any cleanup have been implmented in distructor of appmanager

	pOut->ClearStatusBar();
}

ToDraw::~ToDraw()
{
	
}

void ToDraw::Undo() {}

void ToDraw::Redo() {}
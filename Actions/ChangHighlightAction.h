#ifndef CHANGE_HIGHLIGHT_ACTION_H
#define CHANGE_HIGHLIGHT_ACTION_H

#include "Action.h"

//Add Change Highlight Colour Action class
class ChangeHighlightAction : public Action
{
private:
	ActionType ColorAct; //Changed color
	GfxInfo OldGfxInfo, NewGfxInfo; //Old and new graphics info
	bool SelectedFlag;
public:
	ChangeHighlightAction(ApplicationManager* pApp); //Constructor

	virtual void Execute(bool WillRecord, string filename, bool where = true); //Execute the action

	virtual void ReadActionParameters();

	bool GetHighlightColour(ActionType); //function for changing the highlight ui color
		
	void Undo(); //Undo the action

	void Redo(); //Redo the action

	~ChangeHighlightAction(); //Destructor
};

#endif
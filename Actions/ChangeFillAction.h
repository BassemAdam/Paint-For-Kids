#ifndef CHANGE_FILL_ACTION_H
#define CHANGE_FILL_ACTION_H

#include "Action.h"

//Add Change Highlight Colour Action class
class ChangeFillAction : public Action
{
private:
	ActionType ColorAct; //CLICKED COLOR
	GfxInfo OldGfxInfo, NewGfxInfo; //Old and new graphics info
	bool SelectedFlag;

public:
	ChangeFillAction(ApplicationManager* pApp); //Constructor

	virtual void ReadActionParameters();

	virtual void Execute(bool WillRecord, string filename, bool where = true); //Execute the action


	bool GetFillColour(ActionType); //function for changing the fill ui color

	void Undo(); //Undo the action

	void Redo(); //Redo the action

	~ChangeFillAction(); //Destructor
};

#endif
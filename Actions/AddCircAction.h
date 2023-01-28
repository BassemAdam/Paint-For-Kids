#ifndef ADD_CIRC_ACTION_H
#define ADD_CIRC_ACTION_H

#include "Action.h"

//Add Circle Action class
class AddCircAction : public Action
{
private:
	Point P1, P2; //Circle Center and Radius
	GfxInfo CircGfxInfo; //Circle graphics info
public:
	AddCircAction(ApplicationManager* pApp); //Constructor

	virtual void ReadActionParameters(); //Reads Circle parameters

	virtual void Execute(bool WillRecord, string filename, bool where = true); //Execute the action

	void Undo(); //Undo the action

	void Redo(); //Redo the action

	~AddCircAction(); //Destructor
};

#endif